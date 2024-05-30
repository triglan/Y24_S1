class Card:
    def __init__(self, temp):
        self.value = temp % 13 + 1
        self.x = temp // 13

    def getValue(self):
        if self.value > 10:
            return 10
        else:
            return self.value

    def getSuit(self):
        if self.x == 0:
            self.suit = "Clubs"
        elif self.x == 1:
            self.suit = "Spades"
        elif self.x == 2:
            self.suit = "Hearts"
        else:
            self.suit = "Diamonds"

        return self.suit

    def fileName(self):
        return self.getSuit() + str(self.value) + ".png"