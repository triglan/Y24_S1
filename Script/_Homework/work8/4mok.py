from tkinter import *
class MainGUI:
    def check(self): # 3개 연속인 것을 찾으면 O/X를 반환하고 아니면 빈문자열 반환
        for i in range(6): # 가로 4개 체크
            for j in range(4):
                player = self.matrix[i][j]['text']
                if player != ' ' and player == self.matrix[i][j + 1]['text']\
                        and player == self.matrix[i][j+2]['text'] and player == self.matrix[i][j+3]['text']:
                    return player
        for i in range(3): # 세로 4개 체크
            for j in range(7):
                player = self.matrix[i][j]['text']
                if player != ' ' and player == self.matrix[i + 1][j]['text']\
                    and player == self.matrix[i + 2][j]['text'] and player == self.matrix[i + 3][j]['text']:
                    return player
        for i in range(3): # 대각선 좌 우
            for j in range(4):
                player = self.matrix[i][j]['text']
                if player != ' ' and player == self.matrix[i + 1][j + 1]['text']\
                        and player == self.matrix[i + 2][j + 2]['text'] and player == self.matrix[i + 3][j + 3]['text']:
                    return player
        for i in range(3): # 대각선 우 좌
            for j in range(3, 7):# col = 3,4,5,6
                player = self.matrix[i][j]['text']
                if player != ' ' and player == self.matrix[i + 1][j - 1]['text']\
                        and player == self.matrix[i + 2][j - 2]['text'] and player == self.matrix[i + 3][j - 3]['text']:
                    return player
        return ''

    def findRow(self, col):
        for row in range(5, -1, -1):
            if self.matrix[row][col]['text'] == ' ':
                return row
        return 6
    def pressed(self, c):
        r = self.findRow(c)
        if not self.done and self.matrix[r][c]['text'] == ' ':  # 종료가 아니고 누른 버튼이 비어있어야 함.'
            if self.turn:  # True면 X차례
                self.matrix[r][c]['image'] = self.imageX
                self.matrix[r][c]['text'] = 'X'
            else:  # O차례
                self.matrix[r][c]['image'] = self.imageO
                self.matrix[r][c]['text'] = 'O'
            self.turn = not self.turn  # 플레이어 토글
            if self.check() != '':  # 빙고 성공
                self.done = True
                self.explain.set('플레이어'+ self.check() + '가 승리!')
            elif self.turn:  # 빙고 실패이고, X차례 이면
                self.explain.set('X차례')
            else:  # 빙고 실패이고  O 차례 이면
                self.explain.set('O 차례')
    def refresh(self):
        for i in range(6):
            for j in range(7):
                self.matrix[i][j]['image']=self.imageE
                self.matrix[i][j]['text']=' '
        self.done = False
        self.explain.set('X 차례')
        self.turn = True

    def __init__(self):
        window = Tk()
        window.title('사목게임')
        frame = Frame(window)
        frame.pack()
        self.matrix = []
        self.imageX = PhotoImage(file='pybook/image/x.gif')
        self.imageO = PhotoImage(file='pybook/image/o.gif')
        self.imageE = PhotoImage(file='pybook/image/empty.gif')
        self.turn = True  # 3x3 버튼
        self.done = False
        for i in range(6):  # r = 0,1,2
            self.matrix.append([])  # 빈 리스트 추가
            for j in range(7):
                self.matrix[i].append(Button(frame, image=self.imageE, text=' ',\
                                             command=lambda col=j : self.pressed(col)))
                self.matrix[i][j].grid(row=i, column=j)

        frame1 = Frame(window)
        frame1.pack()
        self.explain = StringVar()
        self.explain.set('x 차례')
        self.label = Label(frame1, textvariable=self.explain)
        self.label.pack(side=LEFT)
        Button(frame1, text='재시작', command=self.refresh).pack(side=LEFT)

        window.mainloop()

MainGUI()
