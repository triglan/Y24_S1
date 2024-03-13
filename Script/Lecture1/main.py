import math
x1,y1 = eval(input('첫번째 점 위도 경도 : '))
x2,y2 = eval(input('두번째 점 위도 경도 : '))
d = (6370.01 * math.acos(math.sin(math.radians(x1)))
     * math.sin(math.radians(x2))
     + math.cos(math.radians(x1))
     * math.cos(math.radians(x2))
     * math.cos(math.radians(y1-y2)))
print("두 점 사이 거리 : ", d)


