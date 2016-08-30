#!/usr/bin/python
import tkinter
from tkinter import *
from tkinter import font

top = tkinter.Tk()
top.title("NOTEPAD")
top.geometry('+%d+%d' % (0,0))
top.geometry('%dx%d' % (1824, 920))
#top.attributes('-fullscreen', True)
#top.attributes('-zoomed', True)
font.families()
text = Text(top, width=1624, height=920)
text.configure(font='Helvetica 20')
text.place(x=0, y=0)

text.pack()

text.focus_set()

top.mainloop()
