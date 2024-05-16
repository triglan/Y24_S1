class Player:
    def __init__(self, name):
        self.name = name
        self.cards = []
        self.N = 0
    def inHand(self):
        return self.N
    def addCard(self,c):
        self.cards.append(c)
        self.N += 1
    def reset(self):
        self.N = 0
        self.cards.clear()
    def value(self):#ace는 1혹은 11로 모두 사용 가능, 호출하면 몇번 카드인지 검사
        sum = 0
        for n in self.cards:
            sum += n.getValue()
        if sum > 21:
            for n in self.cards:
                if n.getValue() == 1:
                    sum -= 10
                if sum <= 21:
                    break
                    #일단 11로 계산한 후 21이 넘어가면 1로 정정
                    #card // 13, 0은 1 or 11의 value