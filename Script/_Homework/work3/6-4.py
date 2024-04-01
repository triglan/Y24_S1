def reverse(num):
    result = 0
    while num:
        result = result*10 + num%10
        num = num // 10
    return result

number = eval(input("숫자 입력 : "))
print(number, "의 reverse : ", reverse(number))