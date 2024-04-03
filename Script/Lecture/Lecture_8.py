x = 0.2
print(x, 'test')
print(x,'test', sep='###')

import sys
print('welcom to', sep='~', end = '!', file = sys.stderr)

# 텍스트창에 쓰기
f=open('text.txt', 'w')
print('file write', file = f)
f.close()

for x in range(1,6):
    print(x,'*',x,'=',str(x*x).rjust(3))

for x in range(1,6):
    print(x,'*',x,'=',str(x*x).zfill(3))

for x in range(1,6):
    print('{0} x {0} = {1:5.2f}'.format(x,x*x))

for x in range(1,6):
    print('{0} x {0} = {1:#x}'.format(x,x*x))

for x in range(1,6):#2진수
    print('{0} x {0} = {1:#b}'.format(x,x*x))

for x in range(1,6):#아스키코드
    print('{0} x {0} = {1:c}'.format(x,x*x))

for x in range(1,6):#
    print('{0} x {0} = {1:e}'.format(x,x*x))

f = open('text.txt', 'w')#파일에 쓰기 모드로 전환
f.write('plow deep\nwhile sluggards sleep')
f.close()

f = open('text.txt', 'w')#?? 어케여냐
f.read()
f.tell()
f.seek(0)
f.readline()
f.readline()
f.seek(0)
f.readlines()

import pickle
colors = ['red', 'green', 'black', [1,2,3]]
f=open('file_colors', 'wb')
pickle.dump(colors.f)
f.close()
del colors

f=open('file_colors', 'rb')
colors = pickle.load(f)
print(colors)
f.close()