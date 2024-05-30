import random


class jogbo:
    configs = ['No Pair', 'One Pair', 'Two Pair', 'Triple', 'Straight', 'Back Straight', 'Mountain', 'Flush',
               'Full House', 'Four Cards', 'Straight Flush', 'Back Straight Flush', 'Royal Straight Flush']

    @staticmethod
    def Same_Pattern_Straight_list(playerCards, fieldCards):
        pattern_f = fieldCards[0] // 13
        list = [-1] * 7

        # 깔린 패
        for i, v in enumerate(fieldCards):
            pattern = v // 13
            if pattern_f == pattern:  # 첫번째 등록해놨던 패턴 정보와 현재의 패턴 정보가 같다면 리스트에 값을 추가한다.
                list[i] = v % 13

        # 손 패
        for i, v in enumerate(playerCards):
            pattern = v // 13
            if pattern_f == pattern:  # 첫번째 등록해놨던 패턴 정보와 현재의 패턴 정보가 같다면 리스트에 값을 추가한다.
                list[i + 5] = v % 13
        return list

    @staticmethod
    def Straight_list(playerCards, fieldCards):
        list = [-1] * 7

        # 깔린 패
        for i, v in enumerate(fieldCards):
            list[i] = v % 13

        # 손 패
        for i, v in enumerate(playerCards):
            list[i + 5] = v % 13
        return list

    @staticmethod
    def Same_Num_list(playerCards, fieldCards):
        list = [0] * 13
        # 깔린 패
        for v in fieldCards:
            list[v % 13] += 1
        # 손 패
        for v in playerCards:
            list[v % 13] += 1
        return list

    @staticmethod
    # 같은 무늬 A, 10, J, Q, K
    def Royal_Straight_Flush(list):
        # list에 A, 10, J, Q, K가 모두 있다면 True를 리턴
        # list는 Same_Pattern_Straight_list() 함수를 호출하고 반환 받은값
        if 0 in list and 9 in list and 10 in list and 11 in list and 12 in list:
            return [True, 1]
        return [False, -1]

    @staticmethod
    # 같은 무늬 A, 2, 3, 4, 5
    def Back_Straight_Flush(list):
        # list에 A, 2, 3, 4, 5가 모두 있다면 True를 리턴
        # list는 Same_Pattern_Straight_list() 함수를 호출하고 반환 받은값
        if 0 in list and 1 in list and 2 in list and 3 in list and 4 in list:
            return [True, 1]
        return [False, -1]

    @staticmethod
    # 같은 무늬 5개의 숫자 연속
    def Straight_Flush(list):
        # list는 Same_Pattern_Straight_list() 함수를 호출하고 반환 받은값
        for i in range(13):
            if i in list and i + 1 in list and i + 2 in list and i + 3 in list and i + 4 in list:
                return [True, i + 4 + 1]
        return [False, - 1]

    @staticmethod
    # 같은 숫자의 카드가 4장
    def Four_of_a_kind(list):
        # list는 Same_Num_list() 함수를 호출하고 반환 받은 값
        if 4 in list:
            for i, v in enumerate(list):
                if v == 4:
                    return [True, i + 1]
        return [False, -1]

    @staticmethod
    # 같은 숫자의 카드 3장 + 같은 숫자의 카드 2장
    def Full_house(list):
        # list는 Same_Num_list() 함수를 호출하고 반환 받은 값
        if 3 in list and 2 in list:
            for i, v in enumerate(list):
                if v == 3:
                    return [True, i + 1]
        return [False, -1]

    @staticmethod
    # 같은 무늬 5장
    def Flush(playerCards, fieldCards):
        list = [0] * 4
        for v in fieldCards:
            list[v // 13] += 1
        for v in playerCards:
            list[v // 13] += 1

        # 5장 이상이면 True 리턴
        if any(n >= 5 for n in list):
            for i, v in enumerate(list):
                if v >= 5:
                    return [True, i + 1]
        return [False, -1]

    @staticmethod
    # A, 10, J, Q, K을 만족
    def Mountain(list):
        # list에 A, 10, J, Q, K가 모두 있다면 True를 리턴
        # list는 Straight_list() 호출하고 반환 받은 값
        if 0 in list and 9 in list and 10 in list and 11 in list and 12 in list:
            return [True, 1]
        return [False, -1]

    @staticmethod
    # A, 2, 3, 4, 5를 만족
    def Back_Straight(list):
        # list는 Straight_list() 호출하고 반환 받은 값
        # list에 A, 2, 3, 4, 5가 모두 있다면 True를 리턴
        if 0 in list and 1 in list and 2 in list and 3 in list and 4 in list:
            return [True, 1]
        return [False, -1]

    @staticmethod
    # 숫자가 5개 연속인지
    def Straight(list):
        # list는 Straight_list() 호출하고 반환 받은 값
        for i in range(13):
            if i in list and i + 1 in list and i + 2 in list and i + 3 in list and i + 4 in list:
                return [True, i + 4 + 1]
        return [False, -1]

    @staticmethod
    # 같은 숫자의 카드가 3장 만족
    def Three_of_a_kind(list):
        # list는 Same_Num_list() 함수를 호출하고 반환 받은 값
        if 3 in list:
            for i, v in enumerate(list):
                if v == 3:
                    return [True, i + 1]
        return [False, -1]

    @staticmethod
    # 같은 숫자의 카드가 2장인 경우가 2개 존재
    def Two_pair(list):
        # list는 Same_Num_list() 함수를 호출하고 반환 받은 값
        count = 0
        maxValue = -1
        for idx, v in enumerate(list):
            if v == 2:
                count += 1
                if maxValue < idx + 1 and maxValue != 1:
                    maxValue = idx + 1


        if count >= 2:
            return [True, maxValue]
        return [False, -1]

    @staticmethod
    # 같은 숫자의 카드가 2장인 경우가 1개 존재
    def One_pair(list):
        # list는 Same_Num_list() 함수를 호출하고 반환 받은 값
        if 2 in list:
            for i, v in enumerate(list):
                if v == 2:
                    return [True, i + 1]
        return [False, -1]

    @staticmethod
    def highCard(playerCards):
        result = []
        for i in playerCards:
            result.append(i % 13 + 1)

        return max(result)

    @staticmethod
    def score(playerCards, fieldCards):
        listType1 = jogbo.Same_Pattern_Straight_list(playerCards, fieldCards)
        listType2 = jogbo.Straight_list(playerCards, fieldCards)
        listType3 = jogbo.Same_Num_list(playerCards, fieldCards)

        # 로얄 스트레이트 플러시
        if jogbo.Royal_Straight_Flush(listType1)[0]:
            return 12, jogbo.Royal_Straight_Flush(listType1)[1]

        # 백스트레이트 플러시
        if jogbo.Back_Straight_Flush(listType1)[0]:
            return 11, jogbo.Back_Straight_Flush(listType1)[1]

        # 스트레이트 플러시
        if jogbo.Straight_Flush(listType1)[0]:
            return 10, jogbo.Straight_Flush(listType1)[1]

        # 포카드
        if jogbo.Four_of_a_kind(listType3)[0]:
            return 9, jogbo.Four_of_a_kind(listType3)[1]

        # 풀하우스
        if jogbo.Full_house(listType3)[0]:
            return 8, jogbo.Full_house(listType3)[1]

        # 플러시
        if jogbo.Flush(playerCards, fieldCards)[0]:
            return 7, jogbo.Flush(playerCards, fieldCards)[1]

        # 마운틴
        if jogbo.Mountain(listType2)[0]:
            return 6, jogbo.Mountain(listType2)[1]

        # 백스트레이트
        if jogbo.Back_Straight(listType2)[0]:
            return 5, jogbo.Back_Straight(listType2)[1]

        # 스트레이트
        if jogbo.Straight(listType2)[0]:
            return 4, jogbo.Straight(listType2)[1]

        # 트리플
        if jogbo.Three_of_a_kind(listType3)[0]:
            return 3, jogbo.Three_of_a_kind(listType3)[1]

        # 투페어
        if jogbo.Two_pair(listType3)[0]:
            return 2, jogbo.Two_pair(listType3)[1]

        # 원페어
        if jogbo.One_pair(listType3)[0]:
            return 1, jogbo.One_pair(listType3)[1]

        return 0, jogbo.highCard(playerCards)


card = [i for i in range(52)]
random.shuffle(card)

in_c = card[:5]
# in_c = [0,0,2,3,4] # 깔린 패
c = [0, 0]  # 손패
# print(in_c, c)
#
#
# listType1 = jogbo.Same_Pattern_Straight_list(c, in_c)
# listType2 = jogbo.Straight_list(c, in_c)
# listType3 = jogbo.Same_Num_list(c, in_c)
#
# print("로티플 : ", jogbo.Royal_Straight_Flush(listType1))
# print("백티플 : ", jogbo.Back_Straight_Flush(listType1))
# print("스티플 : ", jogbo.Straight_Flush(listType1))
#
# print("포카드 : ", jogbo.Four_of_a_kind(listType3))
# print("풀하우스 : ", jogbo.Full_house(listType3))
#
# print("플러쉬 : ", jogbo.Flush(c, in_c))
#
# print("마운틴 : ", jogbo.Mountain(listType2))
# print("백스트레이트 : ", jogbo.Back_Straight(listType2))
# print("스트레이트 : ", jogbo.Straight(listType2))
#
# print("트리플 : ", jogbo.Three_of_a_kind(listType3))
# print("투페어 : ", jogbo.Two_pair(listType3))
# print("원페어 : ", jogbo.One_pair(listType3))


# print(jogbo.score(c, in_c))
