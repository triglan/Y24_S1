num = eval(input("0과 1000사이의 숫자 입력 : "))
one = num % 10
ten = (num // 10) % 10
hund = (num // 100)
print("자릿수의 합 : ", one + ten + hund)