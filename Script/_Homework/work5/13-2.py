file_name = input('파일 이름 : ')
f = open(file_name)
S = f.read()
f.close()
print('문자 : ', len(S))
print('단어 : ', len(S.split()))
print('행 : ', len(S.split('\n')))