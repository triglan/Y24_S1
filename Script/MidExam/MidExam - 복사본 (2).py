d = eval(input())
i = 1
d += 1
#for i in range(d):
while(i < d):
    for _ in range(d - i - 1):
        print('. ', end = '')


    x = i
    while(x > 1):
        print(x, end = ' ')
        x -= 1

    x = 1
    while(x < i + 1):
        if x == i:
            print(x, end = '')
        else:
            print(x, end=' ')
        x += 1


    for t in range(d - i - 1):
        if t == d - i - 2:
            print(' .', end = '')
        else:
            print(' .', end = '')

    i += 1
    print()
