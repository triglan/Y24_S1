T = eval(input())
for _ in range(T):
    N = eval(input())
    profit = 0
    for i in range(N): # N반복
        # input() : '500 800 200', input().split(): ['500', '800', '200'] -> [500, 800, 200]
        L = [eval(s) for s in input().split()]
        M = max(L)
        if M > 0:
            profit += M
    print(profit)