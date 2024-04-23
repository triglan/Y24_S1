#W방 H층
T = eval(input())
for _ in range(T):
    H, W, C = map(int, input().split())
    cnt = 0
    for x in range(W):
        for y in range(H):
           cnt+=1
           if cnt == C:
               print(100 * (y+1) + (x+1))
               y,x = H,W