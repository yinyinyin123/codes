from  Tkinter  import *
def   callback():
    print  "clicked  at"
root=Tk()
menu=Menu(root)
root.config(menu=menu)
filemenu=Menu(menu)
menu.add_cascade(label='File',menu=filemenu)
filemenu.add_command(label="New",command=callback)
filemenu.add_command(label="open...",command=callback)
filemenu.add_separator()
filemenu.add_command(label="Exit",command=callback)
helpmenu=Menu(menu)
menu.add_cascade(label="Help",menu=helpmenu)
helpmenu.add_command(label="About...",command=callback)
mainloop()


