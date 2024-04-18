n = eval(input())
line = input()


M = [] # 최소한의 2차원 행렬을 구성하자
M.append(['.']*n)
r = 0           #2차원 행렬의 행 인덱스 변수 0으로 초기화
p = '.'         #전날 자산 증감의 값 관리
for c in range(n):
    if line[c] == '+':
        if p == '/':        #전날이 '/'이면 현재 r 인덱스를 위로 올려야 함
            if r == 0:      #행을 위에 추가
                M.insert(0,['.']*n)
            else:           #현재 행 인덱스 위에 행이 있음
                r -= 1
        p = M[r][c] = '/'
    elif line[c] == '-':
        if p == '\\' or p == '_': #전날이 '\\' 감소 혹은 '_'이면 행을 아래로 내려야 함
            if r== len(M)-1:      #현재 행 인덱스가 마지막 행을 가리키고 있으면 행을 아래 추가
                M.append(['.']*n)
            r += 1
        p = M[r][c] = '\\'
    else: #'='
        if p == '/':
            if r == 0:
                M.insert(0,['.']*n)
            else:
                r -= 1
        p = M[r][c] = '_'
for r in range(len(M)):
    for c in range(n):
        print(M[r][c], end ='')
    print()