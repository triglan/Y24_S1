import random
nOfBalls = eval(input())
nOfSlots = eval(input())
slots = [0] * nOfSlots # 0으로 초기화

for i in range(nOfBalls):#공의 개수만큼 반복
    count = 0 #R의 개수를 샌다
    balls = input()
    count += balls.count("R")
    # for j in range(nOfSlots):
    #     if balls == 'R':
    #         count += 1
    #     else:
    #         pass
    slots[count] += 1 # 해당 슬롯에 공 1개 추가
# print(slots) # 디버깅
Max = max(slots) # 최댓값

for h in range(Max, 0, -1): # h=M, M-1, ..., 1
    for i in slots:
        if i >= h:
            print('*', end = '')
        else:
            print('.', end = '')
    print()
