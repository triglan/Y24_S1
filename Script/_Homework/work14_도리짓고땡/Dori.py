from tkinter import *
from tkinter import font
from winsound import *
import random


class Card:
    def __init__(self, number):
        self.value = number % 10 + 1
        self.idx = number // 10 + 1

    def fileName(self):
        return str(self.value) + '.' + str(self.idx) + '.gif'


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


class Configuration:
    @staticmethod
    def made(cards):
        if len(cards) < 5:
            return False

        for i in range(len(cards)):
            for j in range(i + 1, len(cards)):
                for k in range(j + 1, len(cards)):
                    if (cards[i].value + cards[j].value + cards[k].value) % 10 == 0:
                        return [cards[i], cards[j], cards[k]]
        return False

    @staticmethod
    def made_name(made):
        if made:
            if (made[0].value + made[1].value + made[2].value) % 20 == 0:
                return "메이드"
            else:
                return "메이드"
        return "노메이드"

    @staticmethod
    def Gwang_Ttaeng(cards):
        gwang_cards = [card for card in cards if card.idx == 1]
        if len(gwang_cards) >= 2:
            gwang_values = [card.value for card in gwang_cards]
            if (1 in gwang_values and 8 in gwang_values) or (3 in gwang_values and 8 in gwang_values):
                return "광땡", 10
        return False

    @staticmethod
    def Ttaeng(cards):
        values = [card.value for card in cards]
        for value in range(1, 11):
            if values.count(value) >= 2:
                return f"{value}땡", value
        return False

    @staticmethod
    def kkeut(cards):
        values = [card.value for card in cards]
        kkeut_value = sum(values) % 10
        if kkeut_value <= 8:
            return f"{kkeut_value}끗", kkeut_value
        return False

class Game:
    def __init__(self):
        self.window = Tk()
        self.window.title("drjgd")
        self.window.geometry("800x600")
        self.window.configure(bg="green")
        self.fontstyle = font.Font(self.window, size=24, weight='bold', family='Consolas')
        self.fontstyle2 = font.Font(self.window, size=16, weight='bold', family='Consolas')
        self.fontstyle3 = font.Font(self.window, size=10, family='Consolas')
        self.setupButton()
        self.setupLabel()

        self.player1 = Player("player1")
        self.player2 = Player("player2")
        self.player3 = Player("player3")
        self.dealer = Player("dealer")

        self.P1BetMoney = 0
        self.P2BetMoney = 0
        self.P3BetMoney = 0
        self.playerMoney = 1000

        self.LcardsPlayer1 = []
        self.LcardsPlayer2 = []
        self.LcardsPlayer3 = []
        self.LcardsDealer = []

        # 카드 번호 라벨
        self.LcardsNum1 = []
        self.LcardsNum2 = []
        self.LcardsNum3 = []
        self.LcardsNumD = []

        self.deckN = 0
        self.turn = 0
        self.window.mainloop()

    def setupButton(self):
        self.P1B5 = Button(self.window, text="5만", width=6, height=1, font=self.fontstyle2,
                           command=lambda: self.pressedBet(1, 5))
        self.P1B5.place(x=10, y=500)
        self.P1B1 = Button(self.window, text="1만", width=6, height=1, font=self.fontstyle2,
                           command=lambda: self.pressedBet(1, 1))
        self.P1B1.place(x=100, y=500)
        self.P2B5 = Button(self.window, text="5만", width=6, height=1, font=self.fontstyle2,
                           command=lambda: self.pressedBet(2, 5))
        self.P2B5.place(x=210, y=500)
        self.P2B1 = Button(self.window, text="1만", width=6, height=1, font=self.fontstyle2,
                           command=lambda: self.pressedBet(2, 1))
        self.P2B1.place(x=300, y=500)
        self.P3B5 = Button(self.window, text="5만", width=6, height=1, font=self.fontstyle2,
                           command=lambda: self.pressedBet(3, 5))
        self.P3B5.place(x=410, y=500)
        self.P3B1 = Button(self.window, text="1만", width=6, height=1, font=self.fontstyle2,
                           command=lambda: self.pressedBet(3, 1))
        self.P3B1.place(x=500, y=500)

        self.Deal = Button(self.window, text="Deal", width=6, height=1, font=self.fontstyle2,
                           command=self.pressedDeal)
        self.Deal.place(x=610, y=500)
        self.Again = Button(self.window, text="Again", width=6, height=1, font=self.fontstyle2,
                            command=self.pressedAgain)
        self.Again.place(x=700, y=500)

        self.P1B5["state"] = "disabled"
        self.P1B5["bg"] = "white"
        self.P1B1["state"] = "disabled"
        self.P1B1["bg"] = "white"
        self.P2B5["state"] = "disabled"
        self.P2B5["bg"] = "white"
        self.P2B1["state"] = "disabled"
        self.P2B1["bg"] = "white"
        self.P3B5["state"] = "disabled"
        self.P3B5["bg"] = "white"
        self.P3B1["state"] = "disabled"
        self.P3B1["bg"] = "white"
        self.Deal['state'] = 'active'
        self.Deal['bg'] = 'white'
        self.Again['state'] = 'disabled'
        self.Again['bg'] = 'gray'

    def setupLabel(self):
        # Money
        self.LP1betMoney = Label(text="0만", width=6, height=1, font=self.fontstyle, bg="gray", fg="cyan")
        self.LP1betMoney.place(x=50, y=450)
        self.LP2betMoney = Label(text="0만", width=6, height=1, font=self.fontstyle, bg="gray", fg="cyan")
        self.LP2betMoney.place(x=250, y=450)
        self.LP3betMoney = Label(text="0만", width=6, height=1, font=self.fontstyle, bg="gray", fg="cyan")
        self.LP3betMoney.place(x=450, y=450)
        self.LplayerMoney = Label(text="1000만", width=10, height=1, font=self.fontstyle, bg="gray", fg="blue")
        self.LplayerMoney.place(x=600, y=450)

        self.LP1Config = Label(text="", width=25, height=1, font=self.fontstyle3, bg="green", fg="cyan")
        self.LP1Config.place(x=20, y=290)
        self.LP2Config = Label(text="", width=25, height=1, font=self.fontstyle3, bg="green", fg="cyan")
        self.LP2Config.place(x=210, y=290)
        self.LP3Config = Label(text="", width=25, height=1, font=self.fontstyle3, bg="green", fg="cyan")
        self.LP3Config.place(x=400, y=290)
        self.LdealerConfig = Label(text="", width=25, height=1, font=self.fontstyle3, bg="green", fg="cyan")
        self.LdealerConfig.place(x=300, y=30)

        self.LP1Status = Label(text="", width=6, height=1, font=self.fontstyle, bg="green", fg="red")
        self.LP1Status.place(x=50, y=250)
        self.LP2Status = Label(text="", width=6, height=1, font=self.fontstyle, bg="green", fg="red")
        self.LP2Status.place(x=240, y=250)
        self.LP3Status = Label(text="", width=6, height=1, font=self.fontstyle, bg="green", fg="red")
        self.LP3Status.place(x=430, y=250)

    def pressedBet(self, player, money):
        if self.playerMoney >= money:
            self.playerMoney -= money
            self.LplayerMoney.configure(text=str(self.playerMoney) + "만")
            if player == 1:
                self.P1BetMoney += money
                self.LP1betMoney.configure(text=str(self.P1BetMoney) + "만")
            elif player == 2:
                self.P2BetMoney += money
                self.LP2betMoney.configure(text=str(self.P2BetMoney) + "만")
            elif player == 3:
                self.P3BetMoney += money
                self.LP3betMoney.configure(text=str(self.P3BetMoney) + "만")
            self.Deal["state"] = "active"
            self.Deal["bg"] = "white"
            PlaySound('sounds/chip.wav', SND_FILENAME)

    def pressedDeal(self):
        if self.turn == 0:
            self.player1.reset()
            self.player2.reset()
            self.player3.reset()
            self.dealer.reset()
            self.cardDeck = [i for i in range(40)]
            random.shuffle(self.cardDeck)
            self.deckN = 0

            self.hitPlayer(1, self.player1.N)
            self.hitPlayer(2, self.player2.N)
            self.hitPlayer(3, self.player3.N)
            self.hitDealerDown(self.dealer.N)

            self.P1B5["state"] = "active"
            self.P1B5["bg"] = "white"
            self.P1B1["state"] = "active"
            self.P1B1["bg"] = "white"
            self.P2B5["state"] = "active"
            self.P2B5["bg"] = "white"
            self.P2B1["state"] = "active"
            self.P2B1["bg"] = "white"
            self.P3B5["state"] = "active"
            self.P3B5["bg"] = "white"
            self.P3B1["state"] = "active"
            self.P3B1["bg"] = "white"
            self.Deal['state'] = 'disabled'
            self.Deal['bg'] = 'gray'
            PlaySound('sounds/cardFlip1.wav', SND_FILENAME)
        elif self.turn == 1:
            for _ in range(3):
                self.hitPlayer(1, self.player1.N)
                self.hitPlayer(2, self.player2.N)
                self.hitPlayer(3, self.player3.N)
                self.hitDealerDown(self.dealer.N)
            PlaySound('sounds/cardFlip1.wav', SND_FILENAME)
        elif self.turn == 2:
            self.hitPlayer(1, self.player1.N)
            self.hitPlayer(2, self.player2.N)
            self.hitPlayer(3, self.player3.N)
            self.hitDealerDown(self.dealer.N)
            self.checkWinner()
        else:
            self.checkWinner()

        self.turn += 1

    def pressedAgain(self):
        for card in self.LcardsPlayer1:
            card.destroy()
        for card in self.LcardsPlayer2:
            card.destroy()
        for card in self.LcardsPlayer3:
            card.destroy()
        for card in self.LcardsDealer:
            card.destroy()

        for label in self.LcardsNum1:
            label.destroy()
        for label in self.LcardsNum2:
            label.destroy()
        for label in self.LcardsNum3:
            label.destroy()
        for label in self.LcardsNumD:
            label.destroy()

        self.P1B5["state"] = "disabled"
        self.P1B5["bg"] = "gray"
        self.P1B1["state"] = "disabled"
        self.P1B1["bg"] = "gray"
        self.P2B5["state"] = "disabled"
        self.P2B5["bg"] = "gray"
        self.P2B1["state"] = "disabled"
        self.P2B1["bg"] = "gray"
        self.P3B5["state"] = "disabled"
        self.P3B5["bg"] = "gray"
        self.P3B1["state"] = "disabled"
        self.P3B1["bg"] = "gray"
        self.Deal['state'] = 'active'
        self.Deal['bg'] = 'white'
        self.Again['state'] = 'disabled'
        self.Again['bg'] = 'gray'

        self.P1BetMoney = 0
        self.P2BetMoney = 0
        self.P3BetMoney = 0

        self.LcardsPlayer1 = []
        self.LcardsPlayer2 = []
        self.LcardsPlayer3 = []
        self.LcardsDealer = []

        self.LcardsNum1 = []
        self.LcardsNum2 = []
        self.LcardsNum3 = []
        self.LcardsNumD = []

        self.deckN = 0
        self.turn = 0

        self.LP1betMoney.configure(text="0만")
        self.LP2betMoney.configure(text="0만")
        self.LP3betMoney.configure(text="0만")
        self.LplayerMoney.configure(text=str(self.playerMoney) + "만")

        self.LP1Status.configure(text="")
        self.LP1Config.configure(text="")
        self.LP2Status.configure(text="")
        self.LP2Config.configure(text="")
        self.LP3Status.configure(text="")
        self.LP3Config.configure(text="")

        self.LdealerConfig.configure(text="")

        PlaySound('sounds/ding.wav', SND_FILENAME)

    def hitPlayer(self, player, n):
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1

        if player == 1:
            self.player1.addCard(newCard)
            p = PhotoImage(file="GodoriCards/" + newCard.fileName())
            self.LcardsPlayer1.append(Label(self.window, image=p))

            self.LcardsPlayer1[self.player1.inHand() - 1].image = p
            self.LcardsPlayer1[self.player1.inHand() - 1].place(x=20 + n * 30, y=350)

            self.LcardsNum1.append(Label(self.window, text=str(newCard.value), bg='green', fg='white'))
            self.LcardsNum1[self.player1.inHand() - 1].place(x=20 + n * 30, y=320)
        elif player == 2:
            self.player2.addCard(newCard)
            p = PhotoImage(file="GodoriCards/" + newCard.fileName())
            self.LcardsPlayer2.append(Label(self.window, image=p))

            self.LcardsPlayer2[self.player2.inHand() - 1].image = p
            self.LcardsPlayer2[self.player2.inHand() - 1].place(x=220 + n * 30, y=350)

            self.LcardsNum2.append(Label(self.window, text=str(newCard.value), bg='green', fg='white'))
            self.LcardsNum2[self.player2.inHand() - 1].place(x=220 + n * 30, y=320)
        elif player == 3:
            self.player3.addCard(newCard)
            p = PhotoImage(file="GodoriCards/" + newCard.fileName())
            self.LcardsPlayer3.append(Label(self.window, image=p))

            self.LcardsPlayer3[self.player3.inHand() - 1].image = p
            self.LcardsPlayer3[self.player3.inHand() - 1].place(x=420 + n * 30, y=350)

            self.LcardsNum3.append(Label(self.window, text=str(newCard.value), bg='green', fg='white'))
            self.LcardsNum3[self.player3.inHand() - 1].place(x=420 + n * 30, y=320)

    def hitDealerDown(self, n):
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1
        self.dealer.addCard(newCard)
        p = PhotoImage(file="GodoriCards/cardback.gif")
        self.LcardsDealer.append(Label(self.window, image=p))

        self.LcardsDealer[self.dealer.inHand() - 1].image = p
        self.LcardsDealer[self.dealer.inHand() - 1].place(x=250 + n * 20, y=100)

        self.LcardsNumD.append(Label(self.window, text=str(newCard.value), bg='green', fg='white'))
        self.LcardsNumD[self.dealer.inHand() - 1].place(x=300 + n * 20, y=70)

    def checkWinner(self):
        for i in range(self.dealer.N):
            p = PhotoImage(file="Godoricards/" + self.dealer.cards[i].fileName())
            self.LcardsDealer[i].configure(image=p)
            self.LcardsDealer[i].image = p

        # 딜러 패 확인
        dealerMade = Configuration.made(self.dealer.cards)
        dealer_madeName = None
        dealer_value = None
        if dealerMade != False:
            print(dealerMade, Configuration.made_name(dealerMade))
            dealer_madeName = Configuration.made_name(dealerMade)
            tlist = list(set(self.player1.cards) - set(dealerMade))  # 메이드 패로 사용한 패 제거
            if Configuration.Gwang_Ttaeng(tlist) != False:
                dealer_value = Configuration.Gwang_Ttaeng(tlist)
            elif Configuration.Ttaeng(tlist) != False:
                dealer_value = Configuration.Ttaeng(tlist)
            else:
                dealer_value = Configuration.kkeut(tlist)

            self.LdealerConfig.configure(text=dealer_madeName + str(dealer_value[0]))
        else:
            self.LdealerConfig.configure(text="노메이드")

        # 플레이어1 패 확인 및 승패 확인
        P1made = Configuration.made(self.player1.cards)
        if P1made != False:
            print(P1made, Configuration.made_name(P1made))
            P1madeName = Configuration.made_name(P1made)
            tlist = list(set(self.player1.cards) - set(P1made))  # 메이드 패로 사용한 패 제거
            if Configuration.Gwang_Ttaeng(tlist) != False:
                P1_value = Configuration.Gwang_Ttaeng(tlist)
            elif Configuration.Ttaeng(tlist) != False:
                P1_value = Configuration.Ttaeng(tlist)
            else:
                P1_value = Configuration.kkeut(tlist)

            self.LP1Config.configure(text=P1madeName + str(P1_value[0]))
            if dealerMade == False:
                self.LP1Status.configure(text="승")
                self.playerMoney += self.P1BetMoney * 2
            else:
                if dealer_value[0] == "38광땡" or dealer_value == "광땡":
                    self.LP1Status.configure(text="패")
                elif dealer_value[0][1] == "땡":
                    if P1_value[0][1] == "땡":
                        if P1_value[1] > dealer_value[1]:
                            self.LP1Status.configure(text="승")
                            self.playerMoney += self.P1BetMoney * 2
                        else:
                            self.LP1Status.configure(text="패")
                    else:
                        self.LP1Status.configure(text="패")
                else:
                    if P1_value[0][1] == "땡":
                        self.LP1Status.configure(text="승")
                        self.playerMoney += self.P1BetMoney * 2
                    else:
                        if P1_value[1] > dealer_value[1]:
                            self.LP1Status.configure(text="승")
                            self.playerMoney += self.P1BetMoney * 2
                        else:
                            self.LP1Status.configure(text="패")
        else:
            self.LP1Config.configure(text="노메이드")
            self.LP1Status.configure(text="패")

        # 플레이어2 패 확인 및 승패 확인
        P2Made = Configuration.made(self.player2.cards)
        if P2Made != False:
            print(P2Made, Configuration.made_name(P2Made))
            P2madeName = Configuration.made_name(P2Made)
            tlist = list(set(self.player2.cards) - set(P2Made))  # 메이드 패로 사용한 패 제거
            if Configuration.Gwang_Ttaeng(tlist) != False:
                P2_value = Configuration.Gwang_Ttaeng(tlist)
            elif Configuration.Ttaeng(tlist) != False:
                P2_value = Configuration.Ttaeng(tlist)
            else:
                P2_value = Configuration.kkeut(tlist)

            self.LP2Config.configure(text=P2madeName + str(P2_value[0]))
            if dealerMade == False:
                self.LP2Status.configure(text="승")
                self.playerMoney += self.P2BetMoney * 2
            else:
                if dealer_value[0] == "38광땡" or dealer_value == "광땡":
                    self.LP2Status.configure(text="패")
                elif dealer_value[0][1] == "땡":
                    if P2_value[0][1] == "땡":
                        if P2_value[1] > dealer_value[1]:
                            self.LP2Status.configure(text="승")
                            self.playerMoney += self.P2BetMoney * 2
                        else:
                            self.LP2Status.configure(text="패")
                    else:
                        self.LP2Status.configure(text="패")
                else:
                    if P2_value[0][1] == "땡":
                        self.LP2Status.configure(text="승")
                        self.playerMoney += self.P2BetMoney * 2
                    else:
                        if P2_value[1] > dealer_value[1]:
                            self.LP2Status.configure(text="승")
                            self.playerMoney += self.P2BetMoney * 2
                        else:
                            self.LP2Status.configure(text="패")
        else:
            self.LP2Config.configure(text="노메이드")
            self.LP2Status.configure(text="패")

        # 플레이어3 패 확인 및 승패 확인
        P3Made = Configuration.made(self.player3.cards)
        if P3Made != False:
            print(P3Made, Configuration.made_name(P3Made))
            P3madeName = Configuration.made_name(P3Made)
            tlist = list(set(self.player3.cards) - set(P3Made))  # 메이드 패로 사용한 패 제거
            if Configuration.Gwang_Ttaeng(tlist) != False:
                P3_value = Configuration.Gwang_Ttaeng(tlist)
            elif Configuration.Ttaeng(tlist) != False:
                P3_value = Configuration.Ttaeng(tlist)
            else:
                P3_value = Configuration.kkeut(tlist)

            self.LP3Config.configure(text=P3madeName + str(P3_value[0]))
            if dealerMade == False:
                self.LP3Status.configure(text="승")
                self.playerMoney += self.P3BetMoney * 2
            else:
                if dealer_value[0] == "38광땡" or dealer_value == "광땡":
                    self.LP3Status.configure(text="패")
                elif dealer_value[0][1] == "땡":
                    if P3_value[0][1] == "땡":
                        if P3_value[1] > dealer_value[1]:
                            self.LP3Status.configure(text="승")
                            self.playerMoney += self.P3BetMoney * 2
                        else:
                            self.LP3Status.configure(text="패")
                    else:
                        self.LP3Status.configure(text="패")
                else:
                    if P3_value[0][1] == "땡":
                        self.LP3Status.configure(text="승")
                        self.playerMoney += self.P3BetMoney * 2
                    else:
                        if P3_value[1] > dealer_value[1]:
                            self.LP3Status.configure(text="승")
                            self.playerMoney += self.P3BetMoney * 2
                        else:
                            self.LP3Status.configure(text="패")
        else:
            self.LP3Config.configure(text="노메이드")
            self.LP3Status.configure(text="패")

        self.P1B5["state"] = "disabled"
        self.P1B5["bg"] = "gray"
        self.P1B1["state"] = "disabled"
        self.P1B1["bg"] = "gray"
        self.P2B5["state"] = "disabled"
        self.P2B5["bg"] = "gray"
        self.P2B1["state"] = "disabled"
        self.P2B1["bg"] = "gray"
        self.P3B5["state"] = "disabled"
        self.P3B5["bg"] = "gray"
        self.P3B1["state"] = "disabled"
        self.P3B1["bg"] = "gray"
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'active'
        self.Again['bg'] = 'white'

        PlaySound('sounds/win.wav', SND_FILENAME)


Game()