import math

d = []
x1, y1 = 35.1768201,126.7735892
x2, y2 = 35.1645701,129.0015892
x3, y3 = 37.7637326,128.8824475
x4, y4 = 37.565289,126.8491259
def cal_distance(x1, y1, x2, y2):
    d = (6370.01 * math.acos(math.sin(math.radians(x1))
         * math.sin(math.radians(x2))
        + math.cos(math.radians(x1))
        * math.cos(math.radians(x2))
        * math.cos(math.radians(y1-y2))))
    return d

def cal_Area(d1, d2, d3):
    s = (d1 + d2 + d3) / 2
    area = (s * (s - d1) * (s - d2) * (s - d3)) ** 0.5
    return area

d12 = cal_distance(x1,y1,x2,y2)
d23 = cal_distance(x2,y2,x3,y3)
d34 = cal_distance(x3,y3,x4,y4)
d14 = cal_distance(x1,y1,x4,y4)
d13 = cal_distance(x1,y1,x3,y3)

area1 = cal_Area(d12,d23,d13)
area2 = cal_Area(d14,d34,d13)
sum = area1 + area2
print("넓이 : ", sum)