
def findMaxSize(snow,n,m,r,c,maxSize):
    while True:
        for ch, dr, dc in [('|', -1,0), ('|',1,0), ('-',0, -1),('-',0, 1), ('\\',-1, -1), ('/',-1,1),('/',1, -1), ('\\',1,1)]:
            for i in range(1, maxSize+1):
                nr = r + i*dr
                nc = c + i*dc
                if not (0<=nr<n and 0 <= nc < m and snow[nr][nc] == ch): # maxSize크기를 가질 수 없다.
                    return maxSize - 1
        maxSize += 1

P = eval(input())
for _ in range(P):
    n,m = map(eval, input().split()) # 도면의 크기인 두 정수 n과 m(1 ≤ n, m ≤ 50)이 포함됩니다.
    snow = [input() for i in range(n)]
    maxSize = 0 # 눈송이 최대 크기 0으로 초기화
    for r in range(n): # n개 줄에 대해서 눈송이 중심인 '+'를 우선 찾는다.
        count = snow[r].find('+')
        c = 0
        for _ in range(count): # 눈송이 중심 개수만큼 반복해서
            c = snow[r].find('+')
            maxSize = max(maxSize, findMaxSize(snow,n,m,r,c,maxSize+1))
    print(maxSize)
