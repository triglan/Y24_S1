class Player:
    UPPER = 6 # upper category 6개
    LOWER = 7 # lower category 7개
    def __init__(self,name):
        self.name = name
        self.scores=[0 for i in range(self.UPPER+self.LOWER)] #13개category점수
        #13개 category 사용여부
        self.used=[False for i in range(self.UPPER+self.LOWER)]
    def setScore(self, score, index): # index 카테고리 점수를 기입
        self.scores[index] = score
    def setAtUsed(self, index): # index 카테고리 선택 설정
        self.used[index] = True
    def getUpperScore(self): #상위 6개 점수 합 계산 후 반환
        sum = 0
        for i in range(self.UPPER):
            sum += self.scores[i]
        self.upperScore = sum
        return self.upperScore
    def getLowerScore(self):
        sum = 0
        for i in range(self.LOWER):
            sum += self.scores[self.UPPER+i]
        self.lowerScore = sum
        return self.lowerScore
    def getUsed(self):
        return self.used
    def getTotalScore(self):
        if self.upperScore > 63:
            self.totalScore = self.upperScore + self.lowerScore + 35
        else:
            self.totalScore = self.upperScore + self.lowerScore
        return self.totalScore
    def toString(self):
        return self.name
    def allLowerUsed(self): #lower category 7개 모두 사용되었는가 ?
        for i in range(self.LOWER):
            if (self.used[self.UPPER+i] == False):
                return False
        return True
    def allUpperUsed(self): #upper category 6개 모두 사용되었는가 ?
    #UpperScores, UpperBonus 계산에 활용
        for i in range(self.UPPER):
            if (self.used[i] == False):
                return False
        return True