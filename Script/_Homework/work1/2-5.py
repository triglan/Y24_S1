subtotal, rate = eval(input("소계와 팁비율을 입력하세요 : "))
tip = subtotal * rate / 100
total = subtotal + tip
print("팁 : ", int(tip*100)/100, "총액 : ", int(total*100)/100)