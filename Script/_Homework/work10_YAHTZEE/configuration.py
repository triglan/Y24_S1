from dice import *
class Configuration:
    configs = ["Category","Ones", "Twos","Threes","Fours","Fives","Sixes",
    "Upper Scores","Upper Bonus(35)","Three of a kind", "Four of a kind", "Full House(25)",
    "Small Straight(30)", "Large Straight(40)", "Yahtzee(50)","Chance","Lower Scores", "Total"]

    @staticmethod
    def getConfigs(): # 정적 메소드: 객체생성 없이 사용 가능
        return Configuration.configs
    def score(row, d): # 정적 메소드: 객체생성 없이 사용 가능
    # row = 0이면 Ones, row=2이면 Threes가 득점되야함. row=6이면 UpperScore이므로 유저가 누를 수 없음으로 -1반환
    # row = 8이면 'Three of a kind' 계산
        if (row>=0 and row<=6):
            return Configuration.scoreUpper(d,row+1)
        elif (row==8):
            return Configuration.scoreThreeOfAKind(d)
        elif (row==9):
            return Configuration.scoreFourOfAKind(d)
        elif (row==10):
            return Configuration.scoreFullHouse(d)
        elif (row==11):
            return Configuration.scoreSmallStraight(d)
        elif (row==12):
            return Configuration.scoreLargeStraight(d)
        elif (row==13):
            return Configuration.scoreYahtzee(d)
        elif (row==14):
            return Configuration.sumDie(d)
        else:
            return -1

    def scoreUpper(d, num):  # 정적 메소드: 객체생성 없이 사용 가능
        sum = 0
        for i in range(5):
            if d[i].getRoll()==num:
                sum+= num
        return sum

    def scoreThreeOfAKind(d): # 5개 주사위 중에서 3개가 같으냐? 족보를 만족하면 5개 주사위 눈금의 합을 반환
        counts = [0] * 6
        for die in d:
            counts[die.getRoll() - 1] += 1
        if max(counts) >= 3:
            return Configuration.sumDie(d)
        return 0

    def scoreFourOfAKind(d): # 4개같? 주사위 눈금 합 반환
        counts = [0] * 6
        for die in d:
            counts[die.getRoll() - 1] += 1
        if max(counts) >= 4:
            return Configuration.sumDie(d)
        return 0

    def scoreFullHouse(d): # 3/2같? 25점 반환
        counts = [0] * 6
        for die in d:
            counts[die.getRoll() - 1] += 1
        if 3 in counts and 2 in counts:
            return 25
        return 0

    def scoreSmallStraight(d):#30점?
        rolls = sorted(set(die.getRoll() for die in d))
        if len(rolls) >= 4:
            if all(item in rolls for item in [1, 2, 3, 4]) or \
                    all(item in rolls for item in [2, 3, 4, 5]) or \
                    all(item in rolls for item in [3, 4, 5, 6]):
                return 30
        return 0


    def scoreLargeStraight(d): # 40?
        rolls = sorted(set(die.getRoll() for die in d))
        if rolls == [1, 2, 3, 4, 5] or rolls == [2, 3, 4, 5, 6]:
            return 40
        return 0

    def scoreYahtzee(d): #50점반환
        for i in range(4):
            if d[i].getRoll() != d[i+1].getRoll():
                return 0

    def sumDie(d): # chance 카테고리 혹은 트리플/포카드 족보일 경우에는 5개의 주사위 눈금의 합
        sum=0
        for i in range(5):
            sum += d[i].getRoll()
        return sum