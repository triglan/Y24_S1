from tkinter import *
from tkinter import font
from winsound import *
from Card import *
from Player import *
from Configuration import *
import random


class TexasHoldemPoker:
    def __init__(self):
        self.window = Tk()
        self.window.title("Texas Holdem Poker")
        self.window.geometry("800x600")
        self.window.configure(bg="green")
        self.fontstyle = font.Font(self.window, size=24, weight='bold', family='Consolas')
        self.fontstyle2 = font.Font(self.window, size=16, weight='bold', family='Consolas')
        self.setupButton()
        self.setupLabel()

        self.player = Player("player")
        self.dealer = Player("dealer")
        self.field = Player("field")
        self.betMoney = 10
        self.playerMoney = 990
        self.nCardsDealer = 0
        self.nCardsPlayer = 0
        self.nCardsField = 0
        self.LcardsPlayer = []
        self.LcardsDealer = []
        self.LcardsField = []
        self.deckN = 0
        self.turn = 0
        self.window.mainloop()

    def setupButton(self):
        self.Check = Button(self.window, text="Check", width=6, height=1, font=self.fontstyle2,
                            command=self.pressedCheck)
        self.Check.place(x=50, y=500)
        self.Bx1 = Button(self.window, text="Bet x1", width=6, height=1, font=self.fontstyle2, command=self.pressedBx1)
        self.Bx1.place(x=150, y=500)
        self.Bx2 = Button(self.window, text="Bet x2", width=6, height=1, font=self.fontstyle2, command=self.pressedBx2)
        self.Bx2.place(x=250, y=500)
        self.Deal = Button(self.window, text="Deal", width=6, height=1, font=self.fontstyle2, command=self.pressedDeal)
        self.Deal.place(x=600, y=500)
        self.Again = Button(self.window, text="Again", width=6, height=1, font=self.fontstyle2,
                            command=self.pressedAgain)
        self.Again.place(x=700, y=500)

        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'disabled'
        self.Again['bg'] = 'gray'

    def setupLabel(self):
        self.LbetMoney = Label(text="$10", width=6, height=1, font=self.fontstyle, bg="green",
                               fg="yellow")
        self.LbetMoney.place(x=200, y=450)
        self.LplayerMoney = Label(text="You have $990", width=15, height=1, font=self.fontstyle, bg="green",
                                  fg="yellow")
        self.LplayerMoney.place(x=500, y=450)
        self.LplayerStatus = Label(text="", width=25, height=1, font=self.fontstyle, bg="green", fg="cyan")
        self.LplayerStatus.place(x=100, y=400)
        self.LdealerStatus = Label(text="", width=25, height=1, font=self.fontstyle, bg="green", fg="cyan")
        self.LdealerStatus.place(x=100, y=100)
        self.LgameStatus = Label(text="", width=15, height=1, font=self.fontstyle, bg="green", fg="red")
        self.LgameStatus.place(x=500, y=300)

    def pressedCheck(self):
        self.Check["state"] = "disabled"
        self.Check["bg"] = "gray"
        self.Bx1["state"] = "disabled"
        self.Bx1["bg"] = "gray"
        self.Bx2["state"] = "disabled"
        self.Bx2["bg"] = "gray"
        self.Deal["state"] = "active"
        self.Deal["bg"] = "white"

    def pressedBx1(self):
        if self.playerMoney >= self.betMoney:
            self.playerMoney -= self.betMoney
            self.LplayerMoney.configure(text="You have $" + str(self.playerMoney))
            self.betMoney *= 2
            self.LbetMoney.configure(text="$" + str(self.betMoney))
            self.Check["state"] = "disabled"
            self.Check["bg"] = "gray"
            self.Bx1["state"] = "disabled"
            self.Bx1["bg"] = "gray"
            self.Bx2["state"] = "disabled"
            self.Bx2["bg"] = "gray"
            self.Deal["state"] = "active"
            self.Deal["bg"] = "white"
            PlaySound('BlackJack Resource/sounds/chip.wav', SND_FILENAME)

    def pressedBx2(self):
        if self.playerMoney >= self.betMoney * 2:
            self.playerMoney -= self.betMoney * 2
            self.LplayerMoney. configure(text="You have $" + str(self.playerMoney))
            self.betMoney *= 3
            self.LbetMoney.configure(text="$" + str(self.betMoney))
            self.Check["state"] = "disabled"
            self.Check["bg"] = "gray"
            self.Bx1["state"] = "disabled"
            self.Bx1["bg"] = "gray"
            self.Bx2["state"] = "disabled"
            self.Bx2["bg"] = "gray"
            self.Deal["state"] = "active"
            self.Deal["bg"] = "white"
            PlaySound('BlackJack Resource/sounds/chip.wav', SND_FILENAME)

    def pressedDeal(self):
        if self.turn == 0:
            self.player.reset()
            self.dealer.reset()
            self.field.reset()
            self.cardDeck = [i for i in range(52)]
            random.shuffle(self.cardDeck)
            self.deckN = 0

            self.hitPlayer(self.nCardsPlayer)
            self.hitDealerDown(self.nCardsDealer)
            self.hitPlayer(self.nCardsPlayer)
            self.hitDealerDown(self.nCardsDealer)

            self.Check["state"] = "active"
            self.Check["bg"] = "white"
            self.Bx1["state"] = "active"
            self.Bx1["bg"] = "white"
            self.Bx2["state"] = "active"
            self.Bx2["bg"] = "white"
            self.Deal['state'] = 'disabled'
            self.Deal['bg'] = 'gray'
            PlaySound('BlackJack Resource/sounds/cardFlip1.wav', SND_FILENAME)
        elif self.turn == 1:
            self.hitField(self.nCardsField)
            self.hitField(self.nCardsField)
            self.Check["state"] = "active"
            self.Check["bg"] = "white"
            self.Bx1["state"] = "active"
            self.Bx1["bg"] = "white"
            self.Bx2["state"] = "active"
            self.Bx2["bg"] = "white"
            self.Deal['state'] = 'disabled'
            self.Deal['bg'] = 'gray'
            PlaySound('BlackJack Resource/sounds/cardFlip1.wav', SND_FILENAME)
        elif self.turn <= 4:
            self.hitField(self.nCardsField)
            self.Check["state"] = "active"
            self.Check["bg"] = "white"
            self.Bx1["state"] = "active"
            self.Bx1["bg"] = "white"
            self.Bx2["state"] = "active"
            self.Bx2["bg"] = "white"
            self.Deal['state'] = 'disabled'
            self.Deal['bg'] = 'gray'
            PlaySound('BlackJack Resource/sounds/cardFlip1.wav', SND_FILENAME)
        else:
            self.checkWinner()

        self.turn += 1

    def pressedAgain(self):
        for card in self.LcardsPlayer:
            card.destroy()
        for card in self.LcardsDealer:
            card.destroy()
        for card in self.LcardsField:
            card.destroy()

        self.Check["state"] = "active"
        self.Check["bg"] = "white"
        self.Bx1["state"] = "active"
        self.Bx1["bg"] = "white"
        self.Bx2["state"] = "active"
        self.Bx2["bg"] = "white"
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = "gray"
        self.Again['state'] = 'disabled'
        self.Again['bg'] = 'gray'

        self.betMoney = 10
        self.playerMoney -= 10
        self.nCardsDealer = 0
        self.nCardsPlayer = 0
        self.nCardsField = 0
        self.LcardsPlayer = []
        self.LcardsDealer = []
        self.LcardsField = []
        self.deckN = 0
        self.turn = 0

        self.LbetMoney.configure(text="$10")
        self.LplayerMoney.configure(text="You have $" + str(self.playerMoney))
        self.LplayerStatus.configure(text="")
        self.LdealerStatus.configure(text="")
        self.LgameStatus.configure(text="")

    def hitPlayer(self, n):
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1
        self.player.addCard(newCard)
        self.nCardsPlayer += 1
        p = PhotoImage(file="BlackJack Resource/cards/" + newCard.fileName())
        self.LcardsPlayer.append(Label(self.window, image=p))

        self.LcardsPlayer[self.player.inHand() - 1].image = p
        self.LcardsPlayer[self.player.inHand() - 1].place(x=50 + n * 80, y=350)

    def hitDealerDown(self, n):
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1
        self.dealer.addCard(newCard)
        self.nCardsDealer += 1
        p = PhotoImage(file="BlackJack Resource/cards/b2fv.png")
        self.LcardsDealer.append(Label(self.window, image=p))

        self.LcardsDealer[self.dealer.inHand() - 1].image = p
        self.LcardsDealer[self.dealer.inHand() - 1].place(x=50 + n * 80, y=60)

    def hitField(self, n):
        if self.turn == 0:
            return
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1
        self.field.addCard(newCard)
        self.nCardsField += 1
        p = PhotoImage(file="BlackJack Resource/cards/" + newCard.fileName())
        self.LcardsField.append(Label(self.window, image=p))

        self.LcardsField[self.field.inHand() - 1].image = p
        self.LcardsField[self.field.inHand() - 1].place(x=250 + n * 80, y=200)

    def checkWinner(self):
        for i in range(self.nCardsDealer):
            p = PhotoImage(file="BlackJack Resource/cards/" + self.dealer.cards[i].fileName())
            self.LcardsDealer[i].configure(image=p)
            self.LcardsDealer[i].image = p

        # 카드 리스트 만들기
        playerCardList = []
        dealerCardList = []
        fieldCardList = []
        for i in self.player.cards:
            playerCardList.append(i.value - 1 + i.x * 13)
        for i in self.dealer.cards:
            dealerCardList.append(i.value - 1 + i.x * 13)
        for i in self.field.cards:
            fieldCardList.append(i.value - 1 + i.x * 13)

        playerResult = jogbo.score(playerCardList, fieldCardList)
        dealerResult = jogbo.score(dealerCardList, fieldCardList)

        if playerResult[0] > dealerResult[0]:
            self.LgameStatus.configure(text="WIN")
            self.playerMoney += self.betMoney * 2
            PlaySound('BlackJack Resource/sounds/win.wav', SND_FILENAME)
        elif playerResult[0] < dealerResult[0]:
            self.LgameStatus.configure(text="LOSE")
            PlaySound('BlackJack Resource/sounds/wrong.wav', SND_FILENAME)
        else:
            if playerResult[1] > dealerResult[1]:
                if dealerResult[1] == 1:
                    self.LgameStatus.configure(text="LOSE")
                    PlaySound('BlackJack Resource/sounds/wrong.wav', SND_FILENAME)
                else:
                    self.LgameStatus.configure(text="WIN")
                    self.playerMoney += self.betMoney * 2
                    PlaySound('BlackJack Resource/sounds/win.wav', SND_FILENAME)
            elif playerResult[1] < dealerResult[1]:
                if playerResult[1] == 1:
                    self.LgameStatus.configure(text="WIN")
                    self.playerMoney += self.betMoney * 2
                    PlaySound('BlackJack Resource/sounds/win.wav', SND_FILENAME)
                else:
                    self.LgameStatus.configure(text="LOSE")
                    PlaySound('BlackJack Resource/sounds/wrong.wav', SND_FILENAME)
            else:
                self.LgameStatus.configure(text="DRAW")
                self.playerMoney += self.betMoney
                PlaySound('BlackJack Resource/sounds/win.wav', SND_FILENAME)

        self.LplayerStatus.configure(text=jogbo.configs[playerResult[0]] + str(playerResult[1]))
        self.LdealerStatus.configure(text=jogbo.configs[dealerResult[0]] + str(dealerResult[1]))
        self.betMoney = 0
        self.LplayerMoney.configure(text="You have $" + str(self.playerMoney))
        self.LbetMoney.configure(text="$" + str(self.betMoney))

        self.Check["state"] = "disabled"
        self.Check["bg"] = "gray"
        self.Bx1["state"] = "disabled"
        self.Bx1["bg"] = "gray"
        self.Bx2["state"] = "disabled"
        self.Bx2["bg"] = "gray"
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'active'
        self.Again['bg'] = 'white'


TexasHoldemPoker()
