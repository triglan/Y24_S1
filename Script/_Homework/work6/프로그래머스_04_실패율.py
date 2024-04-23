def solution(N, stages):
    answer = []
    failure = {}
    decominator_user = len(stages);

    # 실패율 구하기
    for i in range(1, N + 1):
        numerator_user = stages.count(i)

        # 스테이지에 도달한 유저가 없을 때의 예외처리
        if numerator_user == 0:
            failure[i] = 0
        else:
            failure[i] = numerator_user / decominator_user
            decominator_user -= stages.count(i)

    # 내림차순 정렬
    # key와 value중 value를 기준으로 정렬한다.
    answer = sorted(failure, key=lambda x: failure[x], reverse=True)
    return answer