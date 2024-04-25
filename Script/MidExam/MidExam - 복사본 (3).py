# 3개의 문자 ... ..X .XY

x, y = map(int, input().split())
cnt = 0 #날짜 넘어가는 카운트
#31번 돌면서 만든다.

print('+---------------------+')

print('|', end='')

for a in range(y - 1):
    print("...", end='')
    cnt += 1
for i in range(x):
    if i < 9:
        print("..", end='')
    else:
        print(".", end='')

    if cnt < 6:
        print(i + 1, end='')
        cnt += 1
    else:
        print(i + 1, end='')
        print('|')
        if not i+1 == x:
            print('|', end= '')
        # print(i + 1, " || ", x)
        cnt = 0

if cnt > 0:
    for _ in range(7 - cnt):
        print("...", end='')
        cnt += 1
    print('|')

print('+---------------------+')
