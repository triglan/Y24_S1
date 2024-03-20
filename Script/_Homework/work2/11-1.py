def sumColumn(m,columnIndex):
    sum = 0
    for i in range(len(m)):
        sum += m[i][columnIndex]
    return sum

matrix = []
for i in range(3):
    s = input("3x4 행렬의 {0}번에 대한 원소를 입력하세요 : ".format(i))
    l = [eval(i) for i in s.split()]
    matrix.append(l)
for j in range(4):
    print("열 {0}번 원소의 총합은 {1} 입니다".format(j,sumColumn(matrix,j)))

