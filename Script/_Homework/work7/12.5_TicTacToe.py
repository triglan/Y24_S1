from tkinter import *
class MainGUI:
    def pressed(self,r,c):
        if not self.done and self.matrix[r][c]['text'] == ' ': # 종료가 아니고 누른 버튼이 비어있어야 함.'
            if self.turn:       #True면 X차례
                self.matrix[r][c]['image']=self.imageX
                self.matrix[r][c]['text']='X'
            else:           #O차례
                self.matrix[r][c]['image']=self.imageO
                self.matrix[r][c]['text']='O'
            self.turn = not self.turn       #플레이어 토글
            ch = self.check()
            if ch != ' ':#빙고 성공
                self.done = True
                self.explain.set(ch+'가 승리!')
            elif self.turn:     #빙고 실패이고, X차례 이면
                self.explain.set('X차례')
            else:               #빙고 실패이고  O 차례 이면
                self.explain.set('O 차례')
    def check(self): #빙고 여부를 체크하고 빙고 성공이면 해당 플레이어 X or O를 반환하고 빙고 실패이면 ' '반환
        for i in range(3):
            # 각 행의 3개가 같으냐?
            ch = self.matrix[i][0]['text']
            if ch != ' ' and ch == self.matrix[i][1]['text'] and ch == self.matrix[i][2]['text']: ## 빙고쥬?
                return ch # 빙고 성공한 플레이어 ch를 반환
            ch = self.matrix[0][i]['text']
            if ch != ' ' and ch == self.matrix[1][i]['text'] and ch == self.matrix[2][i]['text']: ## 빙고쥬?
                return ch # 빙고 성공한 플레이어 ch를 반환
        ch = self.matrix[0][0]['text']
        if ch!= ' 'and ch == self.matrix[1][1]['text'] and ch == self.matrix[2][2]['text']:
            return ch
        ch = self.matrix[0][2]['text']
        if ch!= ' 'and ch == self.matrix[1][1]['text'] and ch == self.matrix[2][0]['text']:
            return ch
        return ' '

    def refresh(self):
        self.done = False   # 게임 종료 변수
        self.turn = True    # 번갈아가면서 플레이어를 토글
        self.explain.set('X 차례')
        for r in range(3):
            for c in range(3):
                self.matrix[r][c]['image']=self.imageE
                self.matrix[r][c]['text']=' '
    def __init__(self):
        self.done = False       #게임 종료 변수
        self.turn = True        #번갈아가면서 플레이어를 토글
        window = Tk()
        window.title('틱택토')
        frame1 = Frame(window)
        frame1.pack()
        self.imageX = PhotoImage(file='pybook/image/x.gif')
        self.imageO = PhotoImage(file='pybook/image/o.gif')
        self.imageE = PhotoImage(file='pybook/image/empty.gif')
        self.matrix = []    # 3x3 버튼
        for r in  range(3): # r = 0,1,2
            self.matrix.append([])  #빈 리스트 추가
            for c in range(3):
                self.matrix[r].append(Button(frame1,image=self.imageE,text=' ',
                                             command = lambda row = r, col = c : self.pressed(row,col)))
                self.matrix[r][c].grid(row = r, column = c)
        frame2 = Frame(window)
        frame2.pack()
        self.explain = StringVar()
        self.explain.set('x 차례')
        Label(frame2, textvariable=self.explain).pack(side=LEFT)
        Button(frame2, text='재시작', command=self.refresh).pack(side = LEFT)
        window.mainloop()
MainGUI()

