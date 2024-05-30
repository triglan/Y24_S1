class Player:
    def __init__(self, name):
        self.name = name
        self.cards = []
        self.N = 0

    def inHand(self):
        return self.N

    def addCard(self, c):
        self.cards.append(c)
        self.N += 1

    def reset(self):
        self.N = 0
        self.cards.clear()

    def value(self):
        result = 0
        cntV1 = 0
        for card in self.cards:
            if card.value == 1:
                cntV1 += 1
                result += 11
            else:
                result += card.value

        while cntV1 > 0 and result > 21:
            cntV1 -= 1
            result -= 10

        return result