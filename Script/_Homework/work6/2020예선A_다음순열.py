import itertools
N, K = map(eval, input().split())
for _ in range(K):
    L = [eval(s) for s in input().split()] # L = [1,3,4,2]
    for i in range(N-1, 0, -1): # i = N-1, N-2 ...., 1 (N-1번 비교)
        if L[i-1] < L[i]: # if 3 < 4
            R = L[i-1:] # L[i-1]에서 부터 끝까지 slice 한다 R = [3,4,2]
            R.sort() # R = [2,3,4]
            j = R.index(L[i-1]) # 3의 위치를 알아낸다.
            number = R.pop(j+1) # 3 다음의 숫자 4를 꺼낸다. R = [2,3]
            R.insert(0,number) #4를 제일 앞에 넣는다. R = [4,2,3]
            L = L[:i-1] + R     # L = [1] + [4,2,3]
            break
    for i in L:
        print(i, end= ' ')
    print()