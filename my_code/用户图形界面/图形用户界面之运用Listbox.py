# -*- coding: utf-8 -*-
"""
Created on Wed Nov 18 18:42:47 2015

@author: yinyin
"""


from  Tkinter  import  *
root=Tk()
def  hello():
    t.insert(END,'1+2*3')
    list1=t.get(0.0,END)
    list2=list1.split()
    a=list2[0]
    b=0
    list1=a.split('+')
    print  list1
    for  i in  range(len(list1)):
        e=1
        if  '*' in  list1[i]:
            c=list1[i].split('*')
            print  c
            for r in c:
                e=e*(int(r))
            list1[i]=e
    print  list1
    for  u  in  list1:
        b+=int(u)
    print  b
        
        
        
        

 


    
        

    
t=Text(root)
button=Button(root,command=hello)
t.pack()
button.pack(side='bottom')
root.mainloop()
