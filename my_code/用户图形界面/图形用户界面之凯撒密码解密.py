# -*- coding: utf-8 -*-
"""
Created on Mon Nov 16 20:30:00 2015

@author: yinyin
"""
from  Tkinter  import *
def haha():
    top=Tk()
    def helo():
        a3=en1.get().upper()
        b3=en2.get()
        for i  in  range(len(a3)):
            if  a3[i]  in  'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
                ord2=ord(a3[i])-int(b3)
                if  ord2>90:
                    ord2=ord2-26
                if  ord2<65:
                    ord2+=26
                a3=a3[:i]+chr(ord2)+a3[i+1:]
        subroot=Tk()
        label4=Label(subroot,text=a3)
        label4.pack()
        subroot.mainloop()
    label1=Label(top,text='请输入英文')
    en1=Entry(top)
    label2=Label(top,text='请输入密钥')
    en2=Entry(top)
    label3=Label(top,text='填完英文和密钥，请点击确定')
    button=Button(top,text='确定',command=helo)
    label1.pack()
    en1.pack()
    label2.pack()
    en2.pack()
    label3.pack()
    button.pack()
    top.mainloop()
def  gu():
    top=Tk()
    def  ee():
        
        a6=en1.get()
        k=en2.get()
        a4=a6.upper()
        dicti={}
        for i in range(1,26):
            for  a  in  range(len(a4)):
                if  a4[a] in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
                    ord2=ord(a4[a])+1
                    if  ord2>90:
                        ord2-=26
                    if  ord2<65:
                        ord2+=26
                    a4=a4[:a]+chr(ord2)+a4[a+1:]
            list1=a4.split()
            dicti[i]=list1
        list5=[]
        list3=[]
        dic={}
        f=open('C:\\Users\\yinyin\\Desktop\\dic.txt')
        for  lines in f:
            list3.append(lines.strip().upper())
        f.close()
        list8=dicti.items()
        str2=''
        for a,b  in  list8:
            s=0
            for i in  b:
                str2+=i
            for  j in list3:
                if  j in  i:
                    s+=1
            list5.append(s)
            dic[a]=s
        list10=dic.items()
        list11=[]
        list12=[]
        list5.sort(reverse=True)
        list7=list5[:int(k)]
        for  i  in list7:
            str3=''
            for  a,s in  list10:
                if  i==s:
                    if a  in list11:
                        continue
                    else:
                        for g in dicti[a]:
                            str3+=g+' '
                            list11.append(a)
                        list12.append(str3)
                        break
        str4=''
        for  i in range(len(list12)):
            str4+='第'+str(i+1)+'个:'+list12[i]+','
        subroot=Tk()
        label4=Label(subroot,text=str4)
        label4.pack()
        subroot.mainloop()           
    label1=Label(top,text='请输入英文')
    en1=Entry(top)
    label2=Label(top,text='请输入最相近的数目')
    en2=Entry(top)
    label3=Label(top,text='填完英文和数目，请点击确定')
    button=Button(top,text='确定',command=ee)
    label1.pack()
    en1.pack()
    label2.pack()
    en2.pack()
    label3.pack()
    button.pack()
    top.mainloop()     
def  hello():
    top=Tk()
    def  hell():
        a2=en1.get().upper()
        b2=en2.get()
        def  abc(a1,b1):
            for  i  in range(len(a1)):
                if  a1[i] in  'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
                    ord1=ord(a1[i])+int(b1)
                    if  ord1>90:
                        ord1=ord1-26
                    if  ord1<65:
                        ord1=26+ord1
                    a1=a1[:i]+chr(ord1)+a1[i+1:]
            return   a1
        a3=abc(a2,b2)
        subroot=Tk()
        label4=Label(subroot,text=a3)
        label4.pack()
        subroot.mainloop()
    label1=Label(top,text='请输入英文')
    en1=Entry(top)
    label2=Label(top,text='请输入密钥')
    en2=Entry(top)
    label3=Label(top,text='填完英文和密钥，请点击确定')
    button=Button(top,text='确定',command=hell)
    label1.pack()
    en1.pack()
    label2.pack()
    en2.pack()
    label3.pack()
    button.pack()
    top.mainloop()
root=Tk()
button1=Button(root,text='加密',command=hello)
button2=Button(root,text='解密',command=haha)
button3=Button(root,text='破解',command=gu)
button1.pack()
button2.pack()
button3.pack()
root.mainloop()
