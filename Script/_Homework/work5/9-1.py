from tkinter import *

class MainGUI:
    def up(self):
        self.canvas.move('ball',0,-10)
    def down(self):
        self.canvas.move('ball', 0, 10)
    def left(self):
        self.canvas.move('ball', -10, 0)
    def right(self):
        self.canvas.move('ball', 10, 0)

    def __init__(self):
        window = Tk()
        window.title('공 옮기기')
        self.canvas = Canvas(window, width = 600, height = 400, bg = 'white')
        self.canvas.pack()
        self.canvas.create_oval(10, 10, 30, 30, fill = 'red', tags='ball')
        frame = Frame(window)
        frame.pack()
        Button(frame, text='상', command=self.up).pack(side = LEFT)
        Button(frame, text='하', command=self.down).pack(side = LEFT)
        Button(frame, text='좌', command=self.left).pack(side = LEFT)
        Button(frame, text='우', command=self.right).pack(side = LEFT)
        window.mainloop()

MainGUI()
