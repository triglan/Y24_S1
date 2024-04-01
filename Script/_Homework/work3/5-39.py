sales = 1
Goal = 25000000
commission = 0
while commission < Goal:
    sales += 1
    if sales > 10000000:
        commission = 5000000*0.08 + 5000000*0.1 + (sales - 10000000)*0.12
    elif sales > 5000000:
        commission = 5000000*0.08 + (sales - 5000000)*0.1
    else:
        commission = sales * 0.08
print("연봉 3천만원이 되기위한 최소 매출액 :", sales)
