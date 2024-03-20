def sortColumns(m):
    for i in range(len(m)):
        for j in range(len(m[i]) - 1):
            if m[i][j] > m[i][j+1]:
                m[i][j], m[i][j+1] = m[i][j+1], m[i][j]
    return m



matrix = []
for i in range(3):
    s = input("3x3 행렬의 {0}번에 대한 원소를 입력하세요 : ".format(i))
    l = [eval(i) for i in s.split()]
    matrix.append(l)
sortColumns(matrix)
for i in range(3):
    print(matrix[i])


