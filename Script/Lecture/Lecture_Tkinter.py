from tkinter import*
from io import BytesIO
import urllib
import urllib.request
from PIL import Image, ImageTk
window = Tk()
window.getmetry('500x500 + 500*200')
url = 'http://tong.visitkorea.or.kr/cms/resource/74/2396274_image2_1.JPG'
with urllib.request.urlopen(url) as u:
    raw_data = u.read()
im=Image.open(Bytes10(raw_data))
image = ImageTk.PhotoImage(im)
Label(window, image = image, height = 400, width = 400)

window.mainloop()