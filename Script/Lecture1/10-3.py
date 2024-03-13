s = input('1과 100사이 정수 입력 : ')
sList = s.split()
iList = [eval(i) for i in sList]
histogram = [0]*100

for i in iList:
    histogram[i-1] += 1