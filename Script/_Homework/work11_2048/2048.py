from tkinter import *
from tkinter import messagebox
import random

class Game2048:
    bg_color = {
        2: '#eee4da', 4: '#ede0c8', 8: '#edc850',
        16: '#edc53f', 32: '#f67c5f', 64: '#f65e3b',
        128: '#edcf72', 256: '#edcc61', 512: '#f2b179',
        1024: '#f59563', 2048: '#edc22e'
    }
    color = {
        2: '#776e65', 4: '#f9f6f2', 8: '#f9f6f2',
        16: '#f9f6f2', 32: '#f9f6f2', 64: '#f9f6f2',
        128: '#f9f6f2', 256: '#f9f6f2', 512: '#776e65',
        1024: '#f9f6f2', 2048: '#f9f6f2'
    }
    # nxn self.gridCell 2차원 숫자 격자중에서 비어있는 셀의 위치(r, c)들을 골라서 cells에 넣고
    # 그 중에서 랜덤하게 선택해서 숫자 2를 설정한다.
    def random_cell(self):
        cells = []
        for r in range(self.n):
            for c in range(self.n):
                if self.gridCell[r][c] == 0:
                    cells.append((r, c))

        (r, c) = random.choice(cells)
        self.gridCell[r][c] = 2

    # nxn 2차원 라벨의 숫자색과 배경색을 칠한다.
    def paintGrid(self):
        for r in range(self.n):
            for c in range(self.n):
                if self.gridCell[r][c] == 0:
                    self.board[r][c].configure(text='', bg='azure4')
                else:
                    self.board[r][c].configure(text=str(self.gridCell[r][c]), bg=self.bg_color[self.gridCell[r][c]],
                                               fg=self.color[self.gridCell[r][c]])

    def compressGrid(self):
        self.compress = False
        temp = [[0] * self.n for _ in range(self.n)]
        for r in range(self.n):
            cnt = 0
            for c in range(self.n):
                if self.gridCell[r][c] != 0:
                    temp[r][cnt] = self.gridCell[r][c]
                    if cnt != c:
                        self.compress = True
                    cnt += 1
        self.gridCell = temp

    # 좌우 인접셀이 같으면 좌측셀 x = 2, 우측셀은 0으로 설정
    def mergeGrid(self):
        self.merge = False
        for r in range(self.n):
            for c in range(self.n - 1):
                if self.gridCell[r][c] == self.gridCell[r][c + 1] and self.gridCell[r][c] != 0:
                    self.gridCell[r][c] *= 2
                    self.gridCell[r][c + 1] = 0
                    self.score += self.gridCell[r][c]
                    self.merge = True

    def reverse(self):
        for r in range(self.n):
            self.gridCell[r].reverse()

    def transpose(self):
        self.gridCell = [list(t) for t in zip(*self.gridCell)]
    def can_merge(self):
        for r in range(self.n):
            for c in range(self.n - 1):
                if self.gridCell[r][c] == self.gridCell[r][c+1]:
                    return True
        for r in range(self.n-1):
            for c in range(self.n):
                if self.gridCell[r][c] == self.gridCell[r+1][c]:
                    return True
    def link_keys(self, event):
        if self.end or self.won:
            return
        self.compress = False
        self.merge = False
        self.moved = False
        key = event.keysym
        if key == 'Up':
            self.transpose()
            self.compressGrid()
            self.mergeGrid()
            self.moved = self.compress or self.merge
            self.compressGrid()
            self.transpose()
        elif key == 'Down':
            self.transpose()
            self.reverse()
            self.compressGrid()
            self.mergeGrid()
            self.moved = self.compress or self.merge
            self.compressGrid()
            self.reverse()
            self.transpose()
        elif key == 'Left':
            self.compressGrid()
            self.mergeGrid()
            self.moved = self.compress or self.merge
            self.compressGrid()
        elif key == 'Right':
            self.reverse()       #모든 숫자 행 reverse
            self.compressGrid()
            self.mergeGrid()
            self.moved = self.compress or self.merge
            self.compressGrid()
            self.reverse()       #모든 숫자 행 reverse

        else:
            pass
        self.random_cell()
        self.paintGrid()
        #승리 검사
        flag = False
        for r in range(self.n):
            for c in range(self.n):
                if self.gridCell[r][c] == 2048:
                    messagebox.showinfo('2048', 'You Won!!!')
                    self.won = True
                    return
        #종료 검사
        flag = False
        for r in range(self.n):
            for c in range(self.n):
                if self.gridCell[r][c] == 0:
                    flag = True
                    break
        if not (flag or self.can_merge()):      #빈셀이 없고, merge할 수 없다면 종료
            self.end = True
            messagebox.showinfo('2048','score='+str(self.score))
            return
        if self.moved:
            self.random_cell()         #움직인 경우에만 랜덤 2 생성
        self.paintGrid()                #다시 한번 2차원 라벨 색칠

    def __init__(self, size):
        self.n = size
        self.window = Tk()
        self.window.title('2048 Game')

        self.gameArea = Frame(self.window, bg= 'azure3')    # 게임판 프레임
        self.gridCell = [[0]*self.n for _ in range(self.n)] # nxn 2차원 숫자 격자셀
        self.compress = False   # 좌로 압축 여부
        self.merge = False      # 좌우 같은 인접셀 merge 여부
        self.moved = False      # compress or merge
        self.end = False        # 게임 종료
        self.won = False        # 게임 승리
        self.score = 0          # 게임 점수

        self.board = []        # nxn 2차원 라벨

        for r in range(self.n):
            rows = []
            for c in range(self.n):
                l = Label(self.gameArea, text='', bg='azure4', font=('arial', 22, 'bold'), width=4, height=2)
                l.grid(row=r,column=c,padx=7,pady=7)        # r행 c열 격자 라벨 생성, padx=7, pady=7, 좌, 상 7포인트 간격
                rows.append(l)
            self.board.append(rows)

        self.gameArea.pack()

        self.random_cell()      # 랜덤한 위치에 숫자 2생성
        self.random_cell()      # 랜덤한 위치에 숫자 2생성
        self.paintGrid()        # nxn 2차원 라벨의 숫자와 배경색을 칠한다.
        self.window.bind('<Key>', self.link_keys)



        self.window.mainloop()

Game2048(4)

