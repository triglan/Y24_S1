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
        total = 0
        ace = 0
        for i in range(self.N):
            total += self.cards[i].getValue()
            if self.cards[i].getValue() == 1:
                ace += 1

        while total + 10 <= 21 and ace > 0:
            total += 10
            ace -= 1

        return total