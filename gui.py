import serial
from tkinter import *
from tkinter.colorchooser import *

def pickColor():
    color = askcolor()

    red = (color[0][0])/255
    green = (color[0][1])/255
    blue = (color[0][2])/255

    cyan = (1 - red)
    magenta = (1 - green)
    yellow = (1 - blue)

    cmy = [cyan, magenta, yellow]
    ArduinoSerial.write(cmy)

ArduinoSerial = serial.Serial('com18', 9600)
root = Tk()
root.title('Color Chooser')
screen = Canvas(root, width=800, height=800)
screen.pack()
Button(text='Select Color', command=pickColor).pack()
mainloop()
