def to_days(date): # date = 2022.05.19
    year = int(date[:4])
    month = int(date[5:7])
    day = int(date[8:])
    return year * 12 * 28 + month * 28 + day
def solution(today, terms, privacies):
    Today = to_days(today) # 현재 날짜 일수로 변경
    D = {} # D = {'A':6, 'B':12, 'C',:3}
    for s in terms: # terms = {'A 6", "B 12 ", "C 3"
        key = s[0]
        value = int(s[2:])
        D[key] = value # key/value 추가
    answer = []
    for i, privacy in enumerate(privacies):
        if Today >= to_days(privacy[:10]) + D[privacy[-1]] * 28:
            answer.append(i+1)
    return answer

print(solution("2022.05.19", ["A 6", "B 12", "C 3"], ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]))
print(solution("2020.01.01", ["Z 3", "D 5"], ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]))

