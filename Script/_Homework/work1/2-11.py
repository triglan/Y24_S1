value = eval(input("약정 금액 : "))
rate = eval(input("연이율 % : "))
years = eval(input("약정 기간 : "))
month_rate = rate / 1200
desposit = value/(1+month_rate)**(years*12)
print("최초 예금 : ", int(desposit))