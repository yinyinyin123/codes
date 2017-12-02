# -*- coding: utf-8 -*-
"""
Created on Fri Nov 27 20:09:49 2015

@author: yinyin
"""

from  Tkinter  import  *
root = Tk()
root.title('3阶行列式计算')


def  ha():
    d=en1.get()
    b=en2.get()
    c=en3.get()
    a=[]
    list1=d.split()
    list2=[]
    for i  in  list1:
        list2.append(int(i))
    a.append(list2)
    list3=b.split()
    list4=[]
    for i  in  list3:
        list4.append(int(i))
    a.append(list4)
    list5=c.split()
    list6=[]
    for i  in  list5:
        list6.append(int(i))
    a.append(list6)
    b=0
    for  x in range(3):
        for  y in range(3):
            if  y!=x:
                for  z  in range(3):
                    if  z!=x  and  z!=y:
                        if  x>y  and  y>z:
                            b+=(-1)**(3)*(a[0][x]*a[1][y]*a[2][z])
                        if  x>y  and  y<z and z>x:
                            b+=(-1)**(1)*(a[0][x]*a[1][y]*a[2][z])
                        if  x<y  and  y<z:
                            b+=a[0][x]*a[1][y]*a[2][z]
                        if  x<y and  y>z and z>x:
                            b+=(-1)**(1)*(a[0][x]*a[1][y]*a[2][z])
                        if  x<y and  y>z and  z<x:
                            b+=a[0][x]*a[1][y]*a[2][z]
                        if  x>y and  y<z and  z<x:
                            b+=a[0][x]*a[1][y]*a[2][z]
    root.destroy()
    subroot=Tk()
    label=Label(subroot,text=str(b),bg='red')
    label.pack()
    subroot.mainloop()
     
        
        
label1=Label(root,text='第一行')
label2=Label(root,text='第二行')
label3=Label(root,text='第三行')
en1=Entry(root)
en2=Entry(root)
en3=Entry(root)
button=Button(root,text='计算',command=ha)
label1.pack()
en1.pack()
label2.pack()
en2.pack()
label3.pack()
en3.pack()
button.pack()
root.mainloop()