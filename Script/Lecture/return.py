def intersect(prelist, postlist):
    retList = []
    for x in prelist:
        if x in postlist and x not in retList:
            retList.append(x)
    return retList

list1 = "SPAM"
list2 = "EGG"
intersect(list1, list2)

print(intersect(list1, ['H', 'A', 'M']))
tup1 = ('B', 'E', 'E', 'F')

print(intersect(list2, tup1))
# 튜플과 리스트 모드 사용 됐다.

x= 10
def sum2(x,y):
    x = 1
    return x+y
b=20
sum2(x.b) # 21
x # 10

def change(x):
    x[0] = 'H'

#def change(x):
#   x = x[:] #입력받은 인자 강제 복사 -> 실제 주소는 변경안됨
#   x[0] = 'H'

w = ['J', 'A', 'M']
T = ['J', 'A', 'M']
s = 'JAM'
t = ('J', 'A', 'M')
#change(s) -> 오류남 읽을 순 있지만 쓸 순 없어
#change(t) ->
change(w) # -> 읽고 쓸 수 있음