def BtoDec(L,b): #b진수 정수 리스트 L을 10진수로 변경해서 반환 L = [3,3,1,2] b=4
    # result = (((0*4 + 3)*4 + 3)*4 + 1)*4 + 2
    result = 0
    for i in L: #L=[3,3,1,2], b=4
        result = result * b + i
    return result

[b, N, M] = [eval(s) for s in input().split()] # [4,4,2]
#b, N, M = map(eval, input().split())
Nlist = [eval(s) for s in input().split()] #Nlist = [3,3,1,2]

Mlist = [eval(s) for s in input().split()] # Mlist = [3,0]
N10 = BtoDec(Nlist, b) #10진수로 변경
M10 = BtoDec(Mlist, b) #10진수로 변경
P = N10*M10             # 곱셈
Plist = []              # 곱셈한 결과를 b진수 리스트로 만듦
while P:
    Plist.insert(0, P % b)
    P //= b
print(len(Plist))
for i in Plist:#print(Plist)
    print(i, end = ' ')
print()