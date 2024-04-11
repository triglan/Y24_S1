from tkinter import*
import tkinter.messagebox
from tkinter.filedialog import askopenfilename

def openfile():
    fn=askopenfilename()
    filename.set(fn)

def showResult2():
    fn = filename.get()
    try:
        infile = open(fn, 'r')
        counts = [0] * 26
        for line in infile:
            lower_line = line.lower()
            for ch in lower_line:
                if ch.isalpha():
                    counts[ord(ch) - ord('a')] += 1
        width = int(canvas['width'])
        height = int(canvas['height'])
        maxCnt = max(counts)
        heightBar = height * 0.75
        widthBar = width - 20

        for i in range(26):
            canvas.create_rectangle(i*widthBar / 26 + 10, height - heightBar * counts[i] / maxCnt - 20,
                                    (i+1) * widthBar / 26, height - 20)
            canvas.create_text(i*widthBar / 26 + 10 + 0.5 * widthBar / 26, height - 10, text=chr(i + ord('a')))
            canvas.create_text(10 + widthBar + widthBar / 2, height - 20 - 0.9 * counts[i] * (height/maxCnt) - 10,
            text = str(counts[i]))
        infile.close()

    except IOError:
        tkinter.messagebox.showwarning(filename+"파일이 존재하지 않음")

# def showResult():
#     fn = filename.get()
#     try:
#         infile = open(fn, 'r')
#         counts = [0] * 26
#         for line in infile:
#             lower_line = line.lower()
#             for ch in lower_line:
#                 if ch.isalpha():
#                     counts[ord(ch) - ord('a')] += 1
#         for i in range(26):
#             if counts[i] != 0:
#                 text.insert(END, chr(i + ord('a')) + " - " + str(counts[i]) + '번 나타납니다.\n')
#         infile.close()
#     except IOError:
#         tkinter.messagebox.showwarning(filename+"파일이 존재하지 않음")


window = Tk()
window.title('문자의 출현 빈도수')

frame1 = Frame(window)
frame1.pack()

canvas = Canvas(frame1, width=800, height=600)
canvas.pack()

frame2 = Frame(window)
frame2.pack()

Label(frame2, text='파일명을 입력하세요: ').pack(side=LEFT)

filename = StringVar()

Entry(frame2, width=20, textvariable= filename).pack(side=LEFT)

Button(frame2, text="열기", command=openfile).pack(side=LEFT)
Button(frame2, text="결과보기", command=showResult2).pack(side=LEFT)

window.mainloop()
