'''
# 인증키를 입력한 후, 필요한 매개변수를 queryParams 딕셔너리로 전달하여 requests 모듈을 사용하여 API 호출을 합니다.
# API에서 반환하는 데이터는 XML 포맷으로 되어 있으므로, xml.etree.ElementTree 모듈을 사용하여 XML을 파싱하여 데이터를 읽어옵니다.
# 읽어온 데이터는 ElementTree의 iter 메소드를 사용하여 item 태그를 찾아서 필요한 데이터를 추출하고 출력하는 예제입니다.
# 필요한 데이터의 태그명을 API 문서에서 확인하여 findtext 메소드를 사용하여 데이터를 추출할 수 있습니다.
# 이 코드를 수정하여 필요한 데이터를 추출하고 활용할 수 있습니다.
# tkinter 모듈을 사용하여 윈도우 창과 표를 생성합니다.
# 표의 첫 번째 행에는 열 이름이 포함되어 있습니다.
# root.iter() 메소드를 사용하여 XML 데이터를 반복하면서 필요한 데이터를 추출하고, 데이터를 data 리스트에 저장합니다.
# data 리스트는 tkinter.Label() 메소드를 사용하여 GUI 창에 표시됩니다.

import requests
import xml.etree.ElementTree as ET
import tkinter
#병원정보 서비스 예제
url = 'http://apis.data.go.kr/B551182/hospInfoServicev2/getHospBasisList'
# 공공데이터포털에서 발급받은 디코딩되지 않은 인증키 입력
service_key = "sea100UMmw23Xycs33F1EQnumONR/9ElxBLzkilU9Yr1oT4TrCot8Y2p0jyuJP72x9rG9D8CN5yuEs6AS2sAiw=="
queryParams = {'serviceKey': service_key, 'pageNo': '1', 'numOfRows': '10', 'sidoCd': '110000', 'sgguCd': '110019'}

response = requests.get(url, params=queryParams)
print(response.text)
root = ET.fromstring(response.text)

window = tkinter.Tk()
window.title("병원정보")

frame = tkinter.Frame(window)
frame.pack()

header = ["Name", "Addr", "Tel", "Url"]

for i, col_name in enumerate(header):
    label = tkinter.Label(frame, text=col_name, font=("Helvetica", 14, "bold"))
    label.grid(row=0, column=i)

row_count = 1
for item in root.iter("item"):
    yadmNm = item.findtext("yadmNm")
    addr = item.findtext("addr")
    telno = item.findtext("telno")
    hospUrl = item.findtext("hospUrl")

    data = [yadmNm, addr, telno, hospUrl]
    for i, value in enumerate(data):
        label = tkinter.Label(frame, text=value, font=("Helvetica", 12))
        label.grid(row=row_count, column=i)

    row_count += 1

window.mainloop()
'''
#pip install pillow
#pip install googlemaps
#pip install requests
import tkinter as tk
import tkinter.ttk as ttk
import requests
import xml.etree.ElementTree as ET
from PIL import Image, ImageTk
import io
from googlemaps import Client

# 공공데이터 API 키
api_key = "sea100UMmw23Xycs33F1EQnumONR/9ElxBLzkilU9Yr1oT4TrCot8Y2p0jyuJP72x9rG9D8CN5yuEs6AS2sAiw=="

# 서울시 구별 병원 정보 데이터
url = "http://apis.data.go.kr/B551182/hospInfoServicev2/getHospBasisList"
params = {
    "serviceKey": api_key,
    "numOfRows": 350,  # 최대 350개의 병원 데이터 요청
    "sidoCd": 110000,  # 서울특별시 코드
}
response = requests.get(url, params=params)
root = ET.fromstring(response.content)
items = root.findall(".//item")

hospitals = []
for item in items:
    hospital = {
        "name": item.findtext("yadmNm"),  # 병원 이름
        "address": item.findtext("addr"),  # 병원 주소
        "lat": item.findtext("YPos"),  # 위도
        "lng": item.findtext("XPos"),  # 경도
        "doctors": item.findtext("drTotCnt"),  # 의사수
    }
    hospitals.append(hospital)

# Google Maps API 클라이언트 생성 (한달에 $20 까지 무료)
# https://console.cloud.google.com/apis/credentials
Google_API_Key = 'AIzaSyCWcSC_y2tIzsEmQawZyMCtKHIAc9WaXDM'
gmaps = Client(key=Google_API_Key)

# 서울시 지도 생성
seoul_center = gmaps.geocode("서울특별시 중구 을지로2가")[0]['geometry']['location']
seoul_map_url = f"https://maps.googleapis.com/maps/api/staticmap?center={seoul_center['lat']},{seoul_center['lng']}&zoom=11&size=400x400&maptype=roadmap"

# 서울시 구별 병원 위치 마커 추가
for hospital in hospitals:
    if hospital['lat'] and hospital['lng']:
        lat, lng = float(hospital['lat']), float(hospital['lng'])
        marker_url = f"&markers=color:red%7C{lat},{lng}"
        seoul_map_url += marker_url

# tkinter GUI 생성
root = tk.Tk()
root.title("서울시 구별 병원 정보")

# 구 선택 콤보박스 생성
selected_gu = tk.StringVar()
selected_gu.set("강남구")  # 초기값 설정
gu_options = set([hospital['address'].split()[1] for hospital in hospitals])
gu_combo = ttk.Combobox(root, textvariable=selected_gu, values=list(gu_options))
gu_combo.pack()

# 병원 목록 표시 함수
def show_hospitals():
    hospital_list.delete(0, tk.END)

    gu_name = selected_gu.get()
    hospitals_in_gu = [hospital for hospital in hospitals if hospital['address'].split()[1] == gu_name]

    hospital_names = [hospital['name'] for hospital in hospitals_in_gu]
    doctor_counts = [int(hospital['doctors']) for hospital in hospitals_in_gu]

    # 캔버스 초기화
    canvas.delete('all')

    # 막대그래프 생성
    max_doctor_count = max(doctor_counts)
    bar_width = 20
    x_gap = 30
    x0 = 60
    y0 = 250
    for i in range(len(hospital_names)):
        x1 = x0 + i * (bar_width + x_gap)
        y1 = y0 - 200 * doctor_counts[i] / max_doctor_count
        canvas.create_rectangle(x1, y1, x1 + bar_width, y0, fill='blue')
        canvas.create_text(x1 + bar_width / 2, y0 + 100, text=hospital_names[i], anchor='n', angle=90)
        canvas.create_text(x1 + bar_width / 2, y1 -10, text=doctor_counts[i], anchor='s')

    # 병원 목록에 추가
    for hospital in hospitals_in_gu:
        hospital_list.insert(tk.END, f"{hospital['name']} ({hospital['doctors']} doctors)")

# 캔버스 생성
canvas = tk.Canvas(root, width=800, height=400)
canvas.pack()

# 병원 목록 리스트박스 생성
hospital_list = tk.Listbox(root, width=60)
hospital_list.pack(side=tk.LEFT, fill=tk.BOTH)

# 스크롤바 생성
scrollbar = tk.Scrollbar(root)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

# 스크롤바와 병원 목록 연결
hospital_list.config(yscrollcommand=scrollbar.set)
scrollbar.config(command=hospital_list.yview)


#서울시 지도 이미지 다운로드
response = requests.get(seoul_map_url+'&key='+Google_API_Key)
image = Image.open(io.BytesIO(response.content))
photo = ImageTk.PhotoImage(image)

#지도 이미지 라벨 생성
map_label = tk.Label(root, image=photo)
map_label.pack()

#지도 이미지 업데이트 함수
def update_map():
    gu_name = selected_gu.get()
    gu_center = gmaps.geocode(f"{gu_name} 구")[0]['geometry']['location']
    gu_map_url = f"https://maps.googleapis.com/maps/api/staticmap?center={gu_center['lat']},{gu_center['lng']}&zoom=14&size=400x400&maptype=roadmap"

    # 선택한 구의 병원 위치 마커 추가
    hospitals_in_gu = [hospital for hospital in hospitals if hospital['address'].split()[1] == gu_name]
    for hospital in hospitals_in_gu:
        if hospital['lat'] and hospital['lng']:
            lat, lng = float(hospital['lat']), float(hospital['lng'])
            marker_url = f"&markers=color:red%7C{lat},{lng}"
            gu_map_url += marker_url

    # 지도 이미지 업데이트
    response = requests.get(gu_map_url+'&key='+Google_API_Key)
    image = Image.open(io.BytesIO(response.content))
    photo = ImageTk.PhotoImage(image)
    map_label.configure(image=photo)
    map_label.image = photo

    # 병원 목록 업데이트
    show_hospitals()

def on_gu_select(event):
    update_map()

gu_combo.bind("<<ComboboxSelected>>", on_gu_select)

update_map()

root.mainloop()









