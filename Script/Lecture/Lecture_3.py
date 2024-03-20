def userURIBuilder(server,port,**user): #별이 2개 붙은 인자는 가변 인자. 사전 형식 인자다.
    str = 'http://'+server+':'+port+'/?'
    for key in user.keys():
        str += key + '=' + user[key] + '&'
    return str

userURIBuilder('test.com', '8080', id = 'userid', passwd = '1234',
               name = 'mike', age= '20')


#lambda 함수
g =lambda x,y : x*y
print(g(2,3))
(lambda x: x*x)(3)
globals()

def testLambda(g):
    g(1,2,3)
testLambda(lambda a,b,c : print(a,b,c))

print(list(zip('abc', [1,2,3], ('가','나','다'))))# zip : 첫번쨰 원소끼리 합치고 두번쨰 원소끼리 합치고...라는 뜻

l = ['apple', 'banana', 'orange', 'kiwi']
l.sort()
print(l)
l.sort(key = lambda x:x[-1]) # 마지막 원소를 기준으로 정렬
print(l)

#재귀함수
def factorial(x):
    if x==1:
        return 1
    return x*factorial(x-1)
print(factorial(10))
print(factorial(100))

def hanoi(ndisks, startPeg=1, endPeg =3):
    if ndisks:
        hanoi(ndisks-1, startPeg, 6-startPeg-endPeg)
        print(startPeg,'번 기둥의', ndisks, '번 원반을', endPeg, '번 기둥에 옮깁니다.')
        hanoi(ndisks-1, 6-startPeg-endPeg, endPeg)

hanoi(4)
