from tkinter import *
import tkinter.ttk
window = Tk()
window.title('노트북')
notebook=tkinter.ttk.Notebook(window,width=800,height=600)
notebook.pack()

frame1 = Frame(window)
notebook.add(frame1,text='페이지1')
Label(frame1,text='페이지1의내용',fg='red',font='helvetica 48').pack()

frame2 = Frame(window)
notebook.add(frame2,text='페이지2')
Label(frame2,text='페이지2의내용',fg='blue',font='helvetica 48').pack()

frame3 = Frame(window)
notebook.add(frame3,text='페이지3')
Label(frame3,text='페이지3의내용',fg='orange',font='helvetica 48').pack()

frame4 = Frame(window)
notebook.add(frame4,text='페이지4')
Label(frame4,text='페이지4의내용',fg='magenta',font='helvetica 48').pack()
window.mainloop()
