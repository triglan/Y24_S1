a = 0
#if a & 10/a:
#    print('a=0')
if a and 10/a:# 왼쪽 먼저 계산하기 때문에 에러가 나지 않음
    print('a=0')

value = 5
while value > 0:
    print(value)
    value -= 1

l = ['apple',100,15.23]
for i in l:
    print(i,type(i))

# d = {'appple': 100, 'orange' : 200, 'banana' : 300}
# print(d['apple'], '\t',d[0])
#
# for k, v in d.items():
#     print(k,v)

l = [10,20,30]
iterator = iter(l)
for i in iterator:
    print(i)


for n in [1,2]:
    print('--{0} 단--'.format(n))
    for i in [1,2,3,4,5,6,7,8,9]:
        print('{0:4.1f} x{1:4.1f} = {2:4.1f}'.format(n,i,n*i))

L = [1,2,3,4,5,6,7,8,9,10]
for i in L:
    if i>5:
        break
    print(i)

list(range(10))
list(range(5, 10))
list(range(10,0,-1))
list(range(10,20,2))

for i in range(10,20,2):
    print(i)

for _ in range(10):
    print('*',end='')

L = ['apple', 'orange', 'banana']
for i in range(len(L)):
    print('Index:{0}, Value:{1}'.format(i, L[i]))

L = [100, 15.5 ,'apple']
for i in enumerate(L):
    print(i)

deck = [i for i in range(52)]

l=[1,2,3,4,5]
[i**2 for i in l]
t = ('apple', 'banana', 'orange')
[len(i) for i in t]
d = {100: 'apple', 200: 'banana', 300 : 'orange'}
[v.upper() for v in d.values()]
#[i**3 for i in range()]

l = ['apple', 'banana', 'orange', 'kiwi']
[i for i in l if len(i) > 5]
['banana', 'orange']
L1 = [3,4,5]
L2 = [1/5, -0.5, 4]
#[x*y = for x in L1 for y in l2]

#L = [eval(s) for s in input('정수들 입력 : ')'split()']

L=[1,2,3]
def Add10(i):
    return i+10

for i in map(Add10, L):
    print(i)

    list(map(lambda x:x+10, L))

    x=[1,2,3]
    y=[2,3,4]

    list(map(eval, input('정수를 입력').split()))

L = [10,20,30]
# list(filter(lambda x: x < 30)):
#     print("ok")

x = [10,20,30]
Y=['A','B','C']
#R = list(zip(X,Y))
x2, y2 = zip(*R)
print(x2, y2)

X=[10,20,30,40]
Y='ABC'
Z=(1.5,2.5,3.5,4.5)
list(zip(X,Y,Z))

l = ['apple', 'orange', 'banana']
'+'.join(l)
print(l)




















