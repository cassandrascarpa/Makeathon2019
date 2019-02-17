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

    cmy = ",".join([str(cyan), str(magenta), str(yellow)])
    ArduinoSerial.write(str.encode(cmy))
    exit()

ArduinoSerial = serial.Serial('/dev/ttyUSB0', 9600)
root = Tk()
root.title('Color Chooser')
screen = Canvas(root, width=800, height=800)
screen.pack()
Button(text='Select Color', command=pickColor).pack()
mainloop()
