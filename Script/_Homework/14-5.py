from tkinter import *
from tkinter.filedialog import askopenfilename
def openFile():
    filenameR = askopenfilename()
    filename.set(filenameR)
def show():
    f = open(filename.get()) # 파일 오픈
    S = f.read()            # 파일을 읽어서 하나의 문자열로 반환
    newS = S.lower()        #소문자로 변경
    histogram = [0] * 26
    for c in newS:          #한글자씩 가져와서
        if c.isalpha():     #알파벳인 경우 histogramp[0]의미가 'a'의 빈도수를 가져야 한다
            histogram[ord(c) - ord('a')] += 1 # ord('a') 문자의 아스키코드를 알려준다.
    for i in range(26):
        if histogram[i]:
            text.insert(END,chr(ord('a') + i) + '-' + str(histogram[i])+'번 나타납니다\n')
window = Tk()
window.title('문자 빈도수 세기')
frame1 = Frame(window)
frame1.pack()
scrollbar = Scrollbar(frame1)
scrollbar.pack(side = RIGHT, fill=Y)
text = Text(frame1, width = 40, height = 10, wrap = WORD, yscrollcommand=scrollbar.set)
text.pack()
scrollbar.config(command=text.yview)
frame2 = Frame(window)
frame2.pack()
Label(frame2, text='파일 입력 " ').pack(side=LEFT)
filename = StringVar() # 변경가능한 문자열 객체
Entry(frame2, width = 20, textvariable=filename).pack(side = LEFT)
Button(frame2, text='열기', command = openFile).pack(side=LEFT)
Button(frame2, text='결과보기', command = show).pack(side=LEFT)


window.mainloop()