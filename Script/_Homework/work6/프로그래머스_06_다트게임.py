import re


def solution(dartResult):
    score = []
    # 라운드마다 점수 나누기 -> 정규표현식 사용
    p = re.compile('(\d*)([SDT])([*#]?)')
    result = p.findall(dartResult)

    bonus = {'S': 1, 'D': 2, 'T': 3}
    options = {'': 1, '*': 2, '#': -1}

    for i, res in enumerate(result):
        if i > 0 and res[2] == '*':
            score[i - 1] = score[i - 1] * options[res[2]]
        score.append(int(res[0]) ** bonus[res[1]] * options[res[2]])

    return sum(score)