from tkinter import *
from random import *
colors = ['blue', 'red','cyan','orange','black','white'] # 색상 리스트
class Ball:
    def __init__(self):
        self.x = 0      # x위치
        self.y = 0      # y위치
        self.dx = 2     # x방향
        self.dy = 2     # y방향
        self.color = choice(colors)
w = 600
h = 400
class MainGUI:
    def stop(self):
        self.stopped = True
    def resume(self):
        self.stopped = False
        self.animate()
    def plus(self):
        self.ballList.append(Ball())
    def minus(self):
        self.ballList.pop()
    def faster(self):
        if self.sleep > 2:
            self.sleep -= 2
    def slower(self):
        self.sleep += 2
    def animate(self):
        while not self.stopped:
            self.canvas.after(self.sleep)
            self.canvas.update()
            self.canvas.delete('ball')
            for ball in self.ballList:
                if ball.x < 0:
                    ball.dx = 2
                elif ball.x > w:
                    ball.dx = -2
                if ball.y < 0:
                    ball.dy = 2
                elif ball.y > h:
                    ball.dy = -2
                ball.x += ball.dx
                ball.y += ball.dy
                self.canvas.create_oval(ball.x-5,ball.y-5,ball.x+5,ball.y+5,fill=ball.color, tags='ball')

    def __init__(self):
        self.ballList = []
        self.sleep = 10
        self.stopped = False
        window=Tk()
        window.title('공 튀기기')
        self.canvas = Canvas(window, width = w, height = h, bg = 'white')
        self.canvas.pack()
        frame = Frame(window)
        frame.pack()
        Button(frame, text = '정지', command = self.stop).pack(side = LEFT)
        Button(frame, text = '재시작', command = self.resume).pack(side = LEFT)
        Button(frame, text = '+', command = self.plus).pack(side = LEFT)
        Button(frame, text = '-', command = self.minus).pack(side = LEFT)
        Button(frame, text = '빠르게', command = self.faster).pack(side = LEFT)
        Button(frame, text = '느리게', command = self.slower).pack(side = LEFT)
        self.animate()
        window.mainloop()

MainGUI()