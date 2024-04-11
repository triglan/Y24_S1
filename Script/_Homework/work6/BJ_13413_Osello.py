T = eval(input())
for _ in range(T): # T번 반복
    N = eval(input())
    orig = input()
    goal = input()
    NofBW = 0
    NofWB = 0
    for i in range(N): # 말의 개수만큼 B->W, W-.B 변경해야 하는 개수를 센다.
        if orig[i] == 'B' and goal[i] == 'W':
            NofBW += 1
        elif orig[i] == 'W' and goal[i] == 'B':
            NofWB += 1
    # B -> W = 5, W->B = 3 라면 3번 위치를 바꾸고, 나머지 2번 돌을 뒤집는다. 즉 둘중에 큰수를 출력
    print(max(NofBW, NofWB))


