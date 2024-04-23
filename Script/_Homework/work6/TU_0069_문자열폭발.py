# 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
# 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
# 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
# string = input()  # 전체 문자열
# bomb = input()  # 폭발 문자열
#
# lastChar = bomb[-1]  # 폭발 문자열의 마지막 글자
# stack = []
# length = len(bomb)  # 폭발 문자열의 길이
#
# for char in string:
#     stack.append(char)
#     if char == lastChar and ''.join(stack[-length:]) == bomb:
#         del stack[-length:]
#
# print(''.join(stack))

s = input()
b = input()
stack = []

for c in s:
    stack.append(c)
    #문자가 bomb이랑 같은지 확인하라
    if stack[-len(b):]