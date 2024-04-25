N = eval(input())
D = {}              # 딕셔너리 key:value = genre:[총 재생횟수, (1등번호, 횟수), (2등번호, 횟수)
#그 다음 N개 줄에는 각 줄마다 장르를 나타내는 문자열 genre와 play가 주어진다.
for i in range(N):
    [genre, play] = input().split()
    play = int(play)
    if not genre in D: # i번째 곡 genre가 D에 없다면
        D[genre] = [play, (i, play), (-1, 0)] # genre 를 key로 같는 value = []를 추가한다.
    else:
        D[genre][0] += play
        if play > D[genre][1][1]:
            D[genre][2] = D[genre][1]   # 해당 장르 1등을 2등 자리로 복사
            D[genre][1] = (i, play)     # 해당 장르 1등 자리에 (i, play)를 설정.
        elif play > D[genre][2][1]:     # i번 곡의 재생 횟수가 2등 횟수보다 크면
            D[genre][2] = (i, play)     # 해당 장르 2등 자리에 (i, play)를 설정
#print(D)
G = [] # 장르별 총재생횟수 정보를 갖는 리스트 [(genre1, 총 재생횟수), (genre2, 총 재생횟수), ...]
for key, value in D.items():
    G.append( (key, D[key][0]) )
#print(G)
G.sort(key = lambda x:x[1], reverse = True) # 총 재생횟수 기준으로 내림차순 정렬한다.
for genre, play in G:   # 각 장르별로 최대 2곡씩 출력
    print(D[genre][1][0]) # 해당 장르 1등 고유번호 출력
    if D[genre][2][0] != -1:
        print(D[genre][2][0])