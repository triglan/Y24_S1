sList = input('정수를 입력 : ').split()
iList = [eval(s) for s in sList] # 문자열 -> 정수로 치환
average = sum(iList) / len(iList)

count = 0
for i in iList:
    if i >= average:
        count += 1

print('평균이상인 개수 : ', count)
print('평균 미만 개수 : ', len(iList) - count)