import serial
from tkinter import *
from tkinter.colorchooser import *

def pickColor():
    color = askcolor()

    red = (color[0][0])/255
    green = (color[0][1])/255
    blue = (color[0][2])/255

    k = 1 - max(red, green, blue)
    cyan = (1 - red - k) / (1 - k)
    magenta = (1 - green - k) / (1 - k)
    yellow = (1 - blue - k) / (1 - k)

    print("C: ", cyan, "M: ", magenta, "Y: ", yellow, "K: ", k)

root = Tk()
root.title('Color Chooser')
screen = Canvas(root, width=800, height=800)
screen.pack()
Button(text='Select Color', command=pickColor).pack()
mainloop()
