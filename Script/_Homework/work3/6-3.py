def reverse(number):
    result = 0
    while number:
        rem = number % 10
        result = result * 10 + rem
        number //= 10
    return result

print(reverse(12345))

def isPalindrome(number):
    if number == reverse(number):
        return True
    else:
        return False

print(isPalindrome(12345))