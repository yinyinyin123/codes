# -*- coding: utf-8 -*-
"""
Created on Fri Nov 27 12:07:30 2015

@author: yinyin
"""

from  Tkinter  import  *
root=Tk()
frame1=Frame(root,width=400,height=10)
frame2=Frame(root,width=100,height=500)
t=Text(frame1)
t.pack()
def  ha1():
    t.insert(END,'1')
def  ha2():
    t.insert(END,'2')
def  ha3():
    t.insert(END,'3')
def  ha4():
    t.insert(END,'4')
def  ha5():
    t.insert(END,'5')
def  ha6():
    t.insert(END,'6')
def  ha7():
    t.insert(END,'7')
def  ha8():
    t.insert(END,'8')
def  ha9():
    t.insert(END,'9')
def  ha0():
    t.insert(END,'0')
def  ha_sum():
    t.insert(END,'+')
def  ha_jian():
    t.insert(END,'-')
def  ha_cheng():
    t.insert(END,'*')
def  ha_chu():
    t.insert(END,'/')
def  calculate():
    global t
    a=t.get(0.0,END)
    list1=a.split('+')
    for  i  in  range(len(list1)):
        if  '-' in  list1[i]:
            list2=list1[i].split('-')
            for  r  in  range(len(list2)):
                m=1
                if  '*' in  list2[r]  and  '/'  in list2[r]:
                    list3=list2[r].split('*')
                    for  l in  range(len(list3)):
                        if   '/'  in  list3[l]:
                            list4=list3[l].split('/')
                            q=float(list4[0])
                            for  g in range(1,len(list4)):
                                q=q/float(list4[g])
                            list3[l]=str(q)
                    for  t in list3:
                        m=m*float(t)
                    list2[r]=m
                if  '/'  in  list2[r]  and  '*'  not in list2[r]:
                    list9=list2[r].split('/')
                    oo=float(list9[0])
                    for  h in  range(1,len(list9)):
                        oo/=float(list9[h])
                        list2[r]=str(oo)
                else:
                    list10=list2[r].split('*')
                    ii=1
                    for   tt  in  range(len(list10)):
                        ii*=float(list10[tt])
                    list2[r]=ii
            c=float(list2[0])
            for  y  in  range(1,len(list2)):
                c-=float(list2[y])
            list1[i]=str(c)
        else:
            if  '/'  in list1[i]  and '*'  in list1[i]:
                list5=list1[i].split('*')
                for  d in range(len(list5)):
                    if  '/' in  list5[d]:
                        list6=list5[d].split('/')
                        mm=float(list6[0])
                        for  b in  range(1,len(list6)):
                            mm/=float(list6[b])
                        list5[d]=mm
                yy=1
                for  u in range(len(list5)):
                    yy*=float(list5[u])
                list1[i]=str(yy)
            if  '/'  in  list1[i]  and  '*'  not in list1[i]:
                list7=list1[i].split('/')
                n=float(list7[0])
                for j in range(1,len(list7)):
                    n/=float(list7[j])
                list1[i]=str(n)
    for  i in  range(len(list1)):
        if   '*' in list1[i]:
            list4=list1[i].split('*')
            u=1
            for  o in  list4:
                u*=float(o)
            list1[i]=u
    p=0
    for  i  in  range(len(list1)):
        p+=float(list1[i])
    f=float(p)
    t.delete(0.0,END)
    t.insert(END,f)
button_1=Button(frame2,text='1',command=ha1)
button_1.place(relx=0,rely=0.1,width=30,height=30)
button_2=Button(frame2,text='2',command=ha2)
button_2.place(relx=0.3,rely=0.1,width=30,height=30)
button_3=Button(frame2,text='3',command=ha3)
button_3.place(relx=0.6,rely=0.1,width=30,height=30)
button_4=Button(frame2,text='4',command=ha4)
button_4.place(relx=0,rely=0.2,width=30,height=30)
button_5=Button(frame2,text='5',command=ha5)
button_5.place(relx=0.3,rely=0.2,width=30,height=30)
button_6=Button(frame2,text='6',command=ha6)
button_6.place(relx=0.6,rely=0.2,width=30,height=30)
button_7=Button(frame2,text='7',command=ha7)
button_7.place(relx=0,rely=0.3,width=30,height=30)
button_8=Button(frame2,text='8',command=ha8)
button_8.place(relx=0.3,rely=0.3,width=30,height=30)
button_9=Button(frame2,text='9',command=ha9)
button_9.place(relx=0.6,rely=0.3,width=30,height=30)
button_0=Button(frame2,text='0',command=ha0)
button_0.place(relx=0.3,rely=0.4,width=30,height=30)
button_sum=Button(frame2,text='+',command=ha_sum)
button_sum.place(relx=0,rely=0.5,width=40,height=30)
button_jian=Button(frame2,text='-',command=ha_jian)
button_jian.place(relx=0.4,rely=0.5,width=40,height=30)
button_cheng=Button(frame2,text='*',command=ha_cheng)
button_cheng.place(relx=0,rely=0.6,width=40,height=30)
button_chu=Button(frame2,text='/',command=ha_chu)
button_chu.place(relx=0.4,rely=0.6,width=40,height=30)
button=Button(frame2,text='计算',command=calculate)
button.place(relx=0.25,rely=0.7,width=40,height=40)
frame1.pack()
frame2.pack()
root.mainloop()
