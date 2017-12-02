# -*- coding: utf-8 -*-
"""
Created on Mon Nov 23 14:11:44 2015

@author: yinyin
"""
from  Tkinter  import  *
import  sqlite3
aa=sqlite3.connect('C:\\Users\\yinyin\\Desktop\\cu')
bb=aa.cursor()
bb.execute("create  table  catalog (kaohao,xingming,yuwen,shuxue,yingyu,wuli,huaxue,zongchengji)")
root=Tk()
def   wo0():
    def  haha():
        a=en1.get()
        b=en2.get()
        c=en3.get()
        d=en4.get()
        e=en5.get()
        f=en6.get()
        g=en7.get()
        h=en8.get()
        aa.execute("insert into  catalog values (?,?,?,?,?,?,?,?)",(a,b,c,d,e,f,g,h))
        aa.commit()
        bb.execute("select  kaohao from  catalog")
        list1=bb.fetchall()
        print  list1
    subroot=Tk()
    subroot.maxsize(600,600)
    subroot.minsize(600,600)
    label1=Label(subroot,text="输入考号")
    label2=Label(subroot,text="输入姓名")
    label3=Label(subroot,text="输入语文成绩")
    label4=Label(subroot,text="输入数学成绩")
    label5=Label(subroot,text="输入英语成绩")
    label6=Label(subroot,text="输入物理成绩")
    label7=Label(subroot,text="输入化学成绩")
    label8=Label(subroot,text="输入总成绩")
    en1=Entry(subroot)
    en2=Entry(subroot)
    en3=Entry(subroot)
    en4=Entry(subroot)
    en5=Entry(subroot)
    en6=Entry(subroot)
    en7=Entry(subroot)
    en8=Entry(subroot)
    label1.place(relx=0.1,rely=0.1)
    en1.place(relx=0.4,rely=0.1)
    label2.place(relx=0.1,rely=0.2)
    en2.place(relx=0.4,rely=0.2)
    label3.place(relx=0.1,rely=0.3)
    en3.place(relx=0.4,rely=0.3)
    label4.place(relx=0.1,rely=0.4)
    en4.place(relx=0.4,rely=0.4)
    label5.place(relx=0.1,rely=0.5)
    en5.place(relx=0.4,rely=0.5)
    label6.place(relx=0.1,rely=0.6)
    en6.place(relx=0.4,rely=0.6)
    label7.place(relx=0.1,rely=0.7)
    en7.place(relx=0.4,rely=0.7)
    label8.place(relx=0.1,rely=0.8)
    en8.place(relx=0.4,rely=0.8)
    button=Button(subroot,text='确定',command=haha)
    button.place(relx=0.5,rely=0.9)
    subroot.mainloop()
def  wo1():
    bb.execute("select  kaohao  from  catalog")
    list0=bb.fetchall()
    bb.execute("select  xingming  from  catalog")
    list7=bb.fetchall()
    bb.execute("select  zongchengji  from  catalog")
    list8=bb.fetchall()
    dic={}
    list6=[]
    list9=[]
    for  i  in  range(len(list8)):
        list6.append([int(list8[i][0]),list7[i][0]])
        dic[list0[i][0]]=[int(list8[i][0]),list7[i][0]]
    list6.sort()
    list6.reverse()
    for i in range(len(list6)):
        for  key in dic:
            if  list6[i]==dic[key]:
                list9.append(str(i+1)+' '+str(key)+' '+list6[i][1]+' '+str(list6[i][0]))
    cmroot=Tk()
    var = StringVar()
    lb = Listbox(cmroot, height=10, listvariable = var)
    list_item = list9
    for item in list_item:
        lb.insert(END, item)
    scrl = Scrollbar(cmroot)
    scrl.pack(side=RIGHT,fill=Y)
    lb.configure(yscrollcommand = scrl.set)
    lb.pack(side=LEFT)
    scrl['command'] = lb.yview
    cmroot.mainloop()
def  wo2():
    rot=Tk()
    def   yuwen():
        bb.execute("select  yuwen from catalog")
        list1=bb.fetchall()
        bb.execute("select  kaohao  from  catalog")
        list0=bb.fetchall()
        bb.execute("select  xingming  from  catalog")
        list7=bb.fetchall()
        dic={}
        list6=[]
        list9=[]
        for  i  in  range(len(list1)):
            list6.append([int(list1[i][0]),list7[i][0]])
            dic[list0[i][0]]=[int(list1[i][0]),list7[i][0]]
        list6.sort()
        list6.reverse()
        for i in range(len(list6)):
            for  key in dic:
                if  list6[i]==dic[key]:
                    list9.append(str(i+1)+' '+str(key)+' '+list6[i][1]+' '+str(list6[i][0]))
        cmroot=Tk()
        var = StringVar()
        lb = Listbox(cmroot, height=10, listvariable = var)
        list_item = list9
        for item in list_item:
            lb.insert(END, item)
        scrl = Scrollbar(cmroot)
        scrl.pack(side=RIGHT,fill=Y)
        lb.configure(yscrollcommand = scrl.set)
        lb.pack(side=LEFT)
        scrl['command'] = lb.yview
        cmroot.mainloop()
    def  shuxue():
        bb.execute("select  shuxue from catalog")
        list1=bb.fetchall()
        bb.execute("select  kaohao  from  catalog")
        list0=bb.fetchall()
        bb.execute("select  xingming  from  catalog")
        list7=bb.fetchall()
        dic={}
        list6=[]
        list9=[]
        for  i  in  range(len(list1)):
            list6.append([int(list1[i][0]),list7[i][0]])
            dic[list0[i][0]]=[int(list1[i][0]),list7[i][0]]
        list6.sort()
        list6.reverse()
        for i in range(len(list6)):
            for  key in dic:
                if  list6[i]==dic[key]:
                    list9.append(str(i+1)+' '+str(key)+' '+list6[i][1]+' '+str(list6[i][0]))
        cmroot=Tk()
        var = StringVar()
        lb = Listbox(cmroot, height=10, listvariable = var)
        list_item = list9
        for item in list_item:
            lb.insert(END, item)
        scrl = Scrollbar(cmroot)
        scrl.pack(side=RIGHT,fill=Y)
        lb.configure(yscrollcommand = scrl.set)
        lb.pack(side=LEFT)
        scrl['command'] = lb.yview
        cmroot.mainloop()
    def  yingyu():
        bb.execute("select  yingyu from catalog")
        list1=bb.fetchall()
        bb.execute("select  kaohao  from  catalog")
        list0=bb.fetchall()
        bb.execute("select  xingming  from  catalog")
        list7=bb.fetchall()
        dic={}
        list6=[]
        list9=[]
        for  i  in  range(len(list1)):
            list6.append([int(list1[i][0]),list7[i][0]])
            dic[list0[i][0]]=[int(list1[i][0]),list7[i][0]]
        list6.sort()
        list6.reverse()
        for i in range(len(list6)):
            for  key in dic:
                if  list6[i]==dic[key]:
                    list9.append(str(i+1)+' '+str(key)+' '+list6[i][1]+' '+str(list6[i][0]))
        cmroot=Tk()
        var = StringVar()
        lb = Listbox(cmroot, height=10, listvariable = var)
        list_item = list9
        for item in list_item:
            lb.insert(END, item)
        scrl = Scrollbar(cmroot)
        scrl.pack(side=RIGHT,fill=Y)
        lb.configure(yscrollcommand = scrl.set)
        lb.pack(side=LEFT)
        scrl['command'] = lb.yview
        cmroot.mainloop()
    def  wuli():
        bb.execute("select  wuli from catalog")
        list1=bb.fetchall()
        bb.execute("select  kaohao  from  catalog")
        list0=bb.fetchall()
        bb.execute("select  xingming  from  catalog")
        list7=bb.fetchall()
        dic={}
        list6=[]
        list9=[]
        for  i  in  range(len(list1)):
            list6.append([int(list1[i][0]),list7[i][0]])
            dic[list0[i][0]]=[int(list1[i][0]),list7[i][0]]
        list6.sort()
        list6.reverse()
        for i in range(len(list6)):
            for  key in dic:
                if  list6[i]==dic[key]:
                    list9.append(str(i+1)+' '+str(key)+' '+list6[i][1]+' '+str(list6[i][0]))
        cmroot=Tk()
        var = StringVar()
        lb = Listbox(cmroot, height=10, listvariable = var)
        list_item = list9
        for item in list_item:
            lb.insert(END, item)
        scrl = Scrollbar(cmroot)
        scrl.pack(side=RIGHT,fill=Y)
        lb.configure(yscrollcommand = scrl.set)
        lb.pack(side=LEFT)
        scrl['command'] = lb.yview
        cmroot.mainloop()
    def huaxue():
        bb.execute("select  huaxue from catalog")
        list1=bb.fetchall()
        bb.execute("select  kaohao  from  catalog")
        list0=bb.fetchall()
        bb.execute("select  xingming  from  catalog")
        list7=bb.fetchall()
        dic={}
        list6=[]
        list9=[]
        for  i  in  range(len(list1)):
            list6.append([int(list1[i][0]),list7[i][0]])
            dic[list0[i][0]]=[int(list1[i][0]),list7[i][0]]
        list6.sort()
        list6.reverse()
        for i in range(len(list6)):
            for  key in dic:
                if  list6[i]==dic[key]:
                    list9.append(str(i+1)+' '+str(key)+' '+list6[i][1]+' '+str(list6[i][0]))
        cmroot=Tk()
        var = StringVar()
        lb = Listbox(cmroot, height=10, listvariable = var)
        list_item = list9
        for item in list_item:
            lb.insert(END, item)
        scrl = Scrollbar(cmroot)
        scrl.pack(side=RIGHT,fill=Y)
        lb.configure(yscrollcommand = scrl.set)
        lb.pack(side=LEFT)
        scrl['command'] = lb.yview
        cmroot.mainloop()
    button1=Button(rot,text='语文',command=yuwen)
    button2=Button(rot,text='数学',command=shuxue)
    button3=Button(rot,text='英语',command=yingyu)
    button4=Button(rot,text='物理',command=wuli)
    button5=Button(rot,text='化学',command=huaxue)
    button1.pack()
    button2.pack()
    button3.pack()
    button4.pack()
    button5.pack()
    rot.mainloop()
def  wo3():
    mroot=Tk()
    def  ha3():
        pmroot=Tk()
        a=en.get()
        b=int(a)
        dic={}
        list9=[]
        bb.execute("select  id from  catalog")
        list1=bb.fetchall()
        bb.execute("select  xingming from  catalog")
        list2=bb.fetchall()
        bb.execute("select  yuwen from  catalog")
        list3=bb.fetchall()
        bb.execute("select  shuxue from  catalog")
        list4=bb.fetchall()
        bb.execute("select  yingyu from  catalog")
        list5=bb.fetchall()
        bb.execute("select  wuli from  catalog")
        list6=bb.fetchall()
        bb.execute("select  huaxue from  catalog")
        list7=bb.fetchall()
        bb.execute("select  zongchngji from  catalog")
        list8=bb.fetchall()
        list10=[]
        for i  in range(len(list1)):
            if  list3[i][0]>b and list4[i][0]>b and  list5[i][0]>b and list6[i][0]>b and list7[i][0]>b:
                dic[list1[i][0]]=[list8[i][0],list2[i][0]]
                list9.append([list8[i][0],list2[i][0]])
        list9.sort()
        list9.reserve()
        for  i  in  range(len(list9)):
            for  key in dic:
                if  list9[i]==dic[key]:
                    list10.append(str(i+1)+' '+str(list9[i][1])+' '+str(key)+' '+str(list9[i][0]))
        var = StringVar()
        lb = Listbox(pmroot, height=10, listvariable = var)
        list_item = list10
        for item in list_item:
            lb.insert(END, item)
        scrl = Scrollbar(pmroot)
        scrl.pack(side=RIGHT,fill=Y)
        lb.configure(yscrollcommand = scrl.set)
        lb.pack(side=LEFT)
        scrl['command'] = lb.yview
        pmroot.mainloop()
    alabel=Label(mroot,text='输入分数')
    en=Entry(mroot)
    button=Button(mroot,text='查询',command=ha3)
    alabel.pack()
    button.pack()
    mroot.mainloop()
def  wo4():
    root3=Tk()
    def  ha2():
        root4=Tk()
        a=en1.get()
        bb.execute("select  kaohao from  catalog")
        list1=bb.fetchall()
        bb.execute("select  xingming from  catalog")
        list2=bb.fetchall()
        bb.execute("select  yuwen from  catalog")
        list3=bb.fetchall()
        bb.execute("select  shuxue from  catalog")
        list4=bb.fetchall()
        bb.execute("select  yingyu from  catalog")
        list5=bb.fetchall()
        bb.execute("select  wuli from  catalog")
        list6=bb.fetchall()
        bb.execute("select  huaxue from  catalog")
        list7=bb.fetchall()
        bb.execute("select  zongchengji from  catalog")
        list8=bb.fetchall()
        for  i in range(len(list1)):
            if  a==list1[i][0]:
                c=str(a)+' '+str(list2[i][0])+' '+str(list3[i][0])+' '+str(list4[i][0])+' '+str(list5[i][0])+' '+str(list6[i][0])+' '+str(list7[i][0])+' '+str(list8[i][0])
        label2=Label(root4,text=c)
        label2.pack()
        root4.mainloop()
    label1=Label(root3,text='输入考号')
    en1=Entry(root3)
    button1=Button(root3,text='确定',command=ha2)
    label1.pack()
    en1.pack()
    button1.pack()
    root3.mainloop()
def  wo5():
    root5=Tk()
    def  ha2():
        root6=Tk()
        a=en1.get()
        bb.execute("select  xingming from  catalog")
        list1=bb.fetchall()
        bb.execute("select  kaohao from  catalog")
        list2=bb.fetchall()
        bb.execute("select  yuwen from  catalog")
        list3=bb.fetchall()
        bb.execute("select  shuxue from  catalog")
        list4=bb.fetchall()
        bb.execute("select  yingyu from  catalog")
        list5=bb.fetchall()
        bb.execute("select  wuli from  catalog")
        list6=bb.fetchall()
        bb.execute("select  huaxue from  catalog")
        list7=bb.fetchall()
        bb.execute("select  zongchngji from  catalog")
        list8=bb.fetchall()
        for  i in range(len(list1)):
            if  a==list1[i][0]:
                c=str(a)+' '+str(list2[i][0])+' '+str(list3[i][0])+' '+str(list4[i][0])+' '+str(list5[i][0])+' '+str(list6[i][0])+' '+str(list7[i][0])+' '+str(list8[i][0])
        label3=Label(root6,text=c)
        label3.pack()
        root6.mainloop()
    label1=Label(root5,text='输入姓名')
    en1=Entry(root5)
    button1=Button(root5,text='确定',command=ha2)
    label1.pack()
    en1.pack()
    button1.pack()
    root5.mainloop()
def  wo6():
    root1=Tk()
    def  ha():
        d=en.get()
        bb.execute("delete from  catalog where kaohao=? or xingming=?",(d,d))
        aa.commit()
    en=Entry(root1)
    label=Label(root1,text='删除的考号或姓名')
    button=Button(root1,text="确定",command=ha)
    label.pack()
    en.pack()
    button.pack()
    root1.mainloop()
def  wo7():
    root2=Tk()
    def  ha1():
        a=en1.get()
        b=en2.get()
        c=en3.get()
        d=en4.get()
        e=en5.get()
        f=en6.get()
        bb.execute("update  catalog  set yuwen=? where kaohao=?",(b,a))
        bb.execute("update catalog  set shuxue=? where  kaohao=?",(c,a))
        bb.execute("update catalog  set yingyu=?  where  kaohao=?",(d,a))
        bb.execute("update catalog  set wuli=? where  kaohao=?",(e,a))
        bb.execute("update catalog  set huaxue=?  where  kaohao=?",(f,a))
        aa.commit()
    label1=Label(root2,text='需要修改的人的考号')
    label2=Label(root2,text='修改后的语文成绩')
    label3=Label(root2,text='修改后的数学成绩')
    label4=Label(root2,text='修改后的英语成绩')
    label5=Label(root2,text='修改后的物理成绩')
    label6=Label(root2,text='修改后的化学成绩')
    button=Button(root2,text='更新',command=ha1)
    en1=Entry(root2)
    en2=Entry(root2)
    en3=Entry(root2)
    en4=Entry(root2)
    en5=Entry(root2)
    en6=Entry(root2)
    label1.pack()
    en1.pack()
    label2.pack()
    en2.pack()
    label3.pack()
    en3.pack()
    label4.pack()
    en4.pack()
    label5.pack()
    en5.pack()
    label6.pack()
    en6.pack()
    button.pack()
    root2.mainloop()
button0=Button(root,text="输入成绩",command=wo0)
button1=Button(root,text="总成绩查询",command=wo1)
button2=Button(root,text="单科成绩查询",command=wo2)
button3=Button(root,text="分数段查询",command=wo3)
button4=Button(root,text="考号查询",command=wo4)
button5=Button(root,text="姓名查询",command=wo5)
button6=Button(root,text="删除",command=wo6)
button7=Button(root,text="修改",command=wo7)
button0.pack()
button1.pack()
button2.pack()
button3.pack()
button4.pack()
button5.pack()
button6.pack()
button7.pack()

root.mainloop()
aa.commit()













