minutes = eval(input("분에 대한 숫자 입력 : "))
days = minutes // (24*60)
years = days // 365
print(minutes, "분은 약 ", years, "년", days % 365, '일 입니다.')