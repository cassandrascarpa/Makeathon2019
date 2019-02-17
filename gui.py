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
#    ArduinoSerial.write(str.encode(cmy))
    exit()

#ArduinoSerial = serial.Serial('/dev/ttyUSB0', 9600)
root = Tk()
root.title('Color Chooser')
screen = Canvas(root, width=800, height=800)
screen.pack()
img = PhotoImage(file="logo.gif")
panel = Label(root, image = img)
panel.place(x=0, y=0, relwidth=1, relheight=1)
lbl = Label(root, text="Paint Mixer", font=("Arial Bold", 50))
lbl.place(x=200, y=100)
Button(text='Select Color', command=pickColor, height=60, width=60).pack()
mainloop()
