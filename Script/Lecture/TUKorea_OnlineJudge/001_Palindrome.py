def reverse(number):
    result = 0
    while number:
        rem = number % 10
        result = result * 10 + rem
        number //= 10
    return result
def isPalindrome(number):
    if number == reverse(number):
        return True
    else:
        return False
def isPrime(number):
    for i in range(2,int(number**0.5)+1):
        if number % i == 0:
            return False
    return True

N = eval(input())
while True:
    if isPalindrome(N) and isPrime(N):
        print(N)
        break
    N += 1

