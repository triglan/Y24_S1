T = eval(input())
for _ in range(T):
    x, q, y, w, n = input().split()
    isC = False

    if q == '+':
        sum = int(x) + int(y)
        if sum == int(n):
            isC = True
    if q == '-':
        sum = int(x) - int(y)
        if sum == int(n):
            isC = True
    if q == '*':
        sum = int(x) * int(y)
        if sum == int(n):
            isC = True
    if q == '/':
        sum = int(x) / int(y)
        if sum == int(n):
            isC = True

    if isC:
        print("correct")
    else:
        print("wrong answer")