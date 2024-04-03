def cal_days(today):
    y,m,d = dict(int, today.split('.'))
    return (y - 2000)

def solution(today, terms, privacies):
    print(len(privacies))
    y,m,d = today.split()
    print(y,m,d)


    answer = []
    return answer

solution("2022.05.19", ["A 6", "B 12", "C 3"], ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"])
