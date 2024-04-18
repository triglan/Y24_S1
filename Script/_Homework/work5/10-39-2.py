from tkinter import *
from random import *
from tkinter.messagebox import *

class MainGUI:
    def refresh(self): # 랜덤한 4장의 카드이미지를 label에 전달한다
        shuffle(self.deck)
        #카드 덱에서 앞에 4개 인덱스를 사용해서 imageList 에서 가져와서 labeList에 전달한다.
        for i in range(4):
            self.labelList[i]['image'] = self.imageList[self.deck[i]]
    def verify(self):
        # 랜덤 이미지 라벨 4개의 숫자를 추출
        fourCards = [self.deck[i]%13 + 1 for i in range(4)]
        fourCards.sort()

        #입력 수식에서 숙자를 추출
        expression = self.E.get()
        expression = expression.replace('(', ' ')
        expression = expression.replace(')', ' ')
        expression = expression.replace('+', ' ')
        expression = expression.replace('-', ' ')
        expression = expression.replace('*', ' ')
        expression = expression.replace('/', ' ')
        numbers = expression.split()
        numbers=expression.split()
        numbers = [eval(s) for s in numbers]
        #print(numbers)
        if fourCards == numbers:
            if(eval(self.E.get())) == 24:
                showinfo('ㅇㅇ','마즘')
            else:
                showinfo('ㄴㄴ', self.E.get()+'아닌데?')
        else:
            showinfo('ㄴㄴ', '보이는 카드로 사용해야한다.')
    def __init__(self):
        window = Tk()
        window.title('24점 게임')
        Button(window, text='새로고침', command=self.refresh).pack()#버튼을 재사용하지 않을거니까 pack
        #52장 카드 이미지 (PhotoImage) 리스트 구성
        self.imageList = [PhotoImage(file='pybook/image/card/'+str(i)+'.gif')
                          for i in range(1, 53)]
        self.deck = [i for i in range(52)] # deck = [0,1,2,...,51]
        frame1 = Frame(window)
        frame1.pack()
        self.labelList = [] #라벨 리스트 (4개 라벨을 갖도록)
        for i in range(4):
            self.labelList.append(Label(frame1, image = self.imageList[i]))
            self.labelList[i].pack(side=LEFT)
        frame2=Frame(window)
        frame2.pack()
        Label(frame2,text='수식 입력:').pack(side=LEFT)
        self.E = Entry(frame2) #여기다 팩을하면 안된다. 팩의 결과닊
        self.E.pack(side=LEFT)
        Button(frame2,text='확인',command=self.verify).pack(side=LEFT)
        window.mainloop()
MainGUI()
