from tkinter import *
class MainGUI:
    def display(self):
        self.canvas.delete('shape')
        if self.v.get() == 1:
            if self.filled.get() == 1:
                self.canvas.create_rectangle(20,20,600-20,200-20, fill = 'red', tags = 'shape')
            else:
                self.canvas.create_rectangle(20,20,600-20,200-20, tags = 'shape')
        else:
            if self.filled.get() == 1:
                self.canvas.create_oval(20,20,600-20,200-20, fill = 'red', tags = 'shape')
            else:
                self.canvas.create_oval(20,20,600-20,200-20, tags = 'shape')
    def __init__(self):
        window = Tk()
        window.title('라디오 버튼 체크 버튼')
        self.canvas = Canvas(window, width = 600, height = 200, bg = 'white')
        self.canvas.pack()
        self.canvas.create_rectangle(20,20,600-20,200-20,tags = 'shape')
        frame = Frame(window)
        frame.pack()
        self.v = IntVar()
        Radiobutton(frame,text='직사각형',variable=self.v, value=1, command=self.display).pack(side = LEFT)
        Radiobutton(frame,text='타원',variable=self.v, value=2, command=self.display).pack(side = LEFT)
        self.filled = IntVar()
        Checkbutton(frame,text='채우기',variable=self.filled, command=self.display).pack(side = LEFT)
        window.mainloop()

MainGUI()