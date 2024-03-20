def testT(x, y):
    if x < 0 or x > 200 or y < 0 or y > 100:
        print('외부')
    else:
        slope = -1 / 2
        # y = slope * x + b
        b = y - slope * x
        if 0 <= b <= 100:
            print('내부')
        else:
            print('외부')

while(True):
    x,y = eval(input('x,y 좌표 입력 : '))
    testT(x,y)

