weight = eval(input("몸무게(파운드) : "))
height = eval(input("키 인치 : "))
wkg = weight * 0.45359237
hm = height * 0.02547
bmi = wkg/(hm**2)
print("BMI : ", bmi)