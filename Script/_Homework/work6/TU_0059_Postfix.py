E = input() # E = ab+cd+e-a+-
# 왼쪽부터 한문자씩 읽어서 문자가 알파벳 (피연산자) 이면 스택에 넣는다.
# Stack : Last-in FirstOut []<-, []->
# 아니고 문자가 연산자(+/-)이면 스택에서 피연산자 b와 a를 꺼내서, '('+ a + 연산자 + b + ')'을 만들어서 스택에 넣는다.
S = []
for c in E:
    if c.isalpha(): # 문자가 알파벳이면
        S.append(c)
    else:
        b = S.pop()
        a = S.pop()
        S.append('(' + a + c + b + ')')
print(S.pop())