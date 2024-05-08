#HTML 사용
import urllib
import http.client
conn = http.client.HTTPConnection('apis.data.go.kr')
conn.request("GET","/B551182/hospInfoServicev2/getHospBasisList?serviceKey=sea100UMmw23Xycs33F1EQnumONR%2F9ElxBLzkilU9Yr1oT4TrCot8Y2p0jyuJP72x9rG9D8CN5yuEs6AS2sAiw%3D%3D&pageNo=1&numOfRows=10&sidoCd=110000&sgguCd=110019")
req = conn.getresponse()
print(req.status,req.reason)
print(req.read().decode('utf-8'))

#urlopen
from urllib.request import urlopen
url = 'http://apis.data.go.kr/B551182/hospInfoServicev2/getHospBasisList?serviceKey=sea100UMmw23Xycs33F1EQnumONR%2F9ElxBLzkilU9Yr1oT4TrCot8Y2p0jyuJP72x9rG9D8CN5yuEs6AS2sAiw%3D%3D&pageNo=1&numOfRows=10&sidoCd=110000&sgguCd=110019'
res_body = urlopen(url).read()
print(res_body.decode('utf-8'))

#requests 외부 모듈
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