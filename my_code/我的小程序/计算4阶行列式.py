# -*- coding: utf-8 -*-
"""
Created on Fri Nov 27 21:15:55 2015

@author: yinyin
"""

from  Tkinter  import  *
root = Tk()
root.title('3阶行列式计算')


def  ha():
    d=en1.get()
    b=en2.get()
    c=en3.get()
    f=en4.get()
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
    list7=f.split()
    list8=[]
    for i in  list7:
        list8.append(int(i))
    a.append(list8)
    b=0
    for  x in range(4):
        for  y in range(4):
            if  y!=x:
                for  z  in range(4):
                    if  z!=x  and  z!=y:
                        for  s in range(4):
                            if  s!=x and  s!=y and  s!=z:
                            
                    
                                if  x>y>z>s:
                                    b+=(-1)**(6)*(a[0][x]*a[1][y]*a[2][z]*a[3][s])
                                if  x>y>s>z:
                                    b+=(-1)**(1)*(a[0][x]*a[1][y]*a[2][z]*a[3][s])
                                if  x>s>y>z:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  x>s>z>y:
                                    b+=(-1)**(1)*(a[0][x]*a[1][y]*a[2][z]*a[3][s])
                                if  x>z>s>y:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  x>z>y>s:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  y>x>z>s:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  y>x>s>z:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  y>s>z>x:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  y>s>x>z:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  y>z>s>x:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  y>z>x>s:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  s>x>y>z:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  s>x>z>y:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  s>z>y>x:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  s>z>x>y:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  s>y>x>z:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  s>y>z>x:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  z>y>s>x:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  z>y>x>s:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  z>s>x>y:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  z>s>y>x:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  z>x>y>s:
                                    b+=a[0][x]*a[1][y]*a[2][z]*a[3][s]
                                if  z>x>s>y:
                                    b+=-a[0][x]*a[1][y]*a[2][z]*a[3][s]
   
   
   
   
   
   
   
   
   
    root.destroy()
    subroot=Tk()
    label=Label(subroot,text=str(b),bg='red')
    label.pack()
    subroot.mainloop()
     
        
        
label1=Label(root,text='第一行')
label2=Label(root,text='第二行')
label3=Label(root,text='第三行')
label4=Label(root,text='第四行')
en1=Entry(root)
en2=Entry(root)
en3=Entry(root)
en4=Entry(root)
button=Button(root,text='计算',command=ha)
label1.pack()
en1.pack()
label2.pack()
en2.pack()
label3.pack()
en3.pack()
label4.pack()
en4.pack()
button.pack()

root.mainloop()