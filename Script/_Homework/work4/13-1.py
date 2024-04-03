file_name = input('파일 이름 : ')
removeS = input('제거할 문자열 : ')
f = open(file_name)#읽기 모드로 파일 오픈
S = f.read() # 한꺼번에 문자열로 읽는다.
newS = S.replace(removeS, '') #문자열은 업데이트가 안됨
f.close()
f=open(file_name, 'w')
f.write(newS)
f.close()
print('완료')

