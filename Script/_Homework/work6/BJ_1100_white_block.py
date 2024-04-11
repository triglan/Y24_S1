d = []
count = 0
flag = True
for _ in range(8):
    d = input()
    for i in range(8):
        if flag:
            if i%2 == 0 and d[i] == 'F':
                count += 1
        else:
            if i%2 == 1 and d[i] == 'F':
                count += 1
    flag = not flag

print(count)
