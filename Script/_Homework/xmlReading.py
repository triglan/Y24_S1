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

