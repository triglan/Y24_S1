import random
nOfBalls = eval(input('공의 개수 : '))
nOfSlots = eval(input('슬롯의 개수 : '))
slots = [0] * nOfSlots # 0으로 초기화

for i in range(nOfBalls):#공의 개수만큼 반복
    count = 0 #R의 개수를 샌다
    for j in range(nOfSlots-1): #슬롯개수 - 1 만큼 반복
        if random.random() > 0.5:
            print('R', end = '') # 강제로 한줄 띄는 것을 방지
            count += 1
        else:
            print('L', end = '')
    print()
    slots[count] += 1 # 해당 슬롯에 공 1개 추가
print(slots) # 디버깅
Max = max(slots) # 최댓값
for h in range(Max, 0, -1): # h=M, M-1, ..., 1
    for i in slots:
        if i >= h:
            print(' o ', end = '')
        else:
            print('   ', end = '')
    print()
