# -*- coding: utf-8 -*-
"""
Created on Fri Dec 04 15:36:45 2015

@author: yinyin
"""
import  re
from Tkinter  import  *
root=Tk()
def  haha():
    a=en1.get()
    b=en2.get()
    c=en3.get()
    subroot=Tk()
    list1=a.split('=')
    list11=[]
    list3=re.findall('x',list1[0])
    list2=re.findall('.x',list1[0])
    list4=re.findall('.*x',list1[0])
    if  list2==['-x']:
        list11.append(-1)
    elif  list4[0][0]=='-':
        list11.append(-float(list4[0][1]))
    elif  list3!=[] and  list2!=[]:
        list11.append(float(list2[0][0]))
    elif  list3!=[]  and  list2==[]:
        list11.append(1)
    else:
        list11.append(0)
    l1=re.findall('y',list1[0])
    l2=re.findall('-y',list1[0])
    l3=re.findall('\+y',list1[0])
    l4=re.findall('-.y',list1[0])
    l5=re.findall('\+.y',list1[0])
    if   l1==[]:
        list11.append(0)
    elif  l2!=[]:
        list11.append(-1)
    elif  l3!=[]:
        list11.append(1)
    elif  l4!=[]:
        list11.append(-float(l4[0][1]))
    else:
        list11.append(int(l5[0][1]))
    l1=re.findall('z',list1[0])
    l2=re.findall('-z',list1[0])
    l3=re.findall('\+z',list1[0])
    l4=re.findall('-.z',list1[0])
    l5=re.findall('\+.z',list1[0])
    if   l1==[]:
        list11.append(0)
    elif  l2!=[]:
        list11.append(-1)
    elif  l3!=[]:
        list11.append(1)
    elif  l4!=[]:
        list11.append(-float(l4[0][1]))
    else:
        list11.append(int(l5[0][1]))
    list11.append(float(list1[1]))
    list1=b.split('=')
    list18=[]
    list3=re.findall('x',list1[0])
    list2=re.findall('.x',list1[0])
    list4=re.findall('.*x',list1[0])
    if  list2==['-x']:
        list18.append(-1)
    elif  list4[0][0]=='-':
        list18.append(-float(list4[0][1]))
    elif  list3!=[] and  list2!=[]:
        list18.append(float(list2[0][0]))
    elif  list3!=[]  and  list2==[]:
        list18.append(1)
    else:
        list18.append(0)
    l1=re.findall('y',list1[0])
    l2=re.findall('-y',list1[0])
    l3=re.findall('\+y',list1[0])
    l4=re.findall('-.y',list1[0])
    l5=re.findall('\+.y',list1[0])
    if   l1==[]:
        list18.append(0)
    elif  l2!=[]:
        list18.append(-1)
    elif  l3!=[]:
        list18.append(1)
    elif  l4!=[]:
        list18.append(-float(l4[0][1]))
    else:
        list18.append(int(l5[0][1]))
    l1=re.findall('z',list1[0])
    l2=re.findall('-z',list1[0])
    l3=re.findall('\+z',list1[0])
    l4=re.findall('-.z',list1[0])
    l5=re.findall('\+.z',list1[0])
    if   l1==[]:
        list18.append(0)
    elif  l2!=[]:
        list18.append(-1)
    elif  l3!=[]:
        list18.append(1)
    elif  l4!=[]:
        list18.append(-float(l4[0][1]))
    else:
        list18.append(int(l5[0][1]))
    list18.append(float(list1[1]))
    list1=c.split('=')
    list19=[]
    list3=re.findall('x',list1[0])
    list2=re.findall('.x',list1[0])
    list4=re.findall('.*x',list1[0])
    if  list2==['-x']:
        list19.append(-1)
    elif  list4[0][0]=='-':
        list19.append(-float(list4[0][1]))
    elif  list3!=[] and  list2!=[]:
        list19.append(float(list2[0][0]))
    elif  list3!=[]  and  list2==[]:
        list19.append(1)
    else:
        list19.append(0)
    l1=re.findall('y',list1[0])
    l2=re.findall('-y',list1[0])
    l3=re.findall('\+y',list1[0])
    l4=re.findall('-.y',list1[0])
    l5=re.findall('\+.y',list1[0])
    if   l1==[]:
        list19.append(0)
    elif  l2!=[]:
        list19.append(-1)
    elif  l3!=[]:
        list19.append(1)
    elif  l4!=[]:
        list19.append(-float(l4[0][1]))
    else:
        list19.append(int(l5[0][1]))
    l1=re.findall('z',list1[0])
    l2=re.findall('-z',list1[0])
    l3=re.findall('\+z',list1[0])
    l4=re.findall('-.z',list1[0])
    l5=re.findall('\+.z',list1[0])
    if   l1==[]:
        list19.append(0)
    elif  l2!=[]:
        list19.append(-1)
    elif  l3!=[]:
        list19.append(1)
    elif  l4!=[]:
        list19.append(-float(l4[0][1]))
    else:
        list19.append(float(l5[0][1]))
    list19.append(float(list1[1]))
    def  abd(list11,list18,list19):
        r=list11[0]*list18[1]*list19[2]+list11[1]*list18[2]*list19[0]+list11[2]*list18[0]*list19[1]-list11[2]*list18[1]*list19[0]-list11[1]*list18[0]*list19[2]-list11[0]*list18[2]*list19[1]
        return  r
    r1=abd(list11,list18,list19)
    li=list11
    li1=list18
    li2=list19
    a1=li[0]
    li[0]=li[3]
    a2=li1[0]
    li1[0]=li1[3]
    a3=li2[0]
    li2[0]=li2[3]
    r2=abd(li,li1,li2)
    liii1=list11
    liii2=list18
    liii3=list19
    liii1[0]=a1
    liii2[0]=a2
    liii3[0]=a3
    b1=liii1[1]
    liii1[1]=liii1[3]
    b2=liii2[1]
    liii2[1]=liii2[3]
    b3=liii3[1]
    liii3[1]=liii3[3]
    r3=abd(liii1,liii2,liii3)
    l1=list11
    l2=list18
    l3=list19
    l1[1]=b1
    l2[1]=b2
    l3[1]=b3
    l1[2]=l1[3]
    l2[2]=l2[3]
    l3[2]=l3[3]
    r4=abd(l1,l2,l3)
    d='x='+str(float(r2)/r1)
    e='y='+str(float(r3)/r1)
    f='z='+str(float(r4)/r1)
    label1=Label(subroot,text=d)
    label2=Label(subroot,text=e)
    label3=Label(subroot,text=f)
    label1.pack()
    label2.pack()
    label3.pack()
    subroot.mainloop()
en1=Entry(root)
en2=Entry(root)
en3=Entry(root)
button=Button(root,text='解方程组',command=haha)
en1.pack()
en2.pack()
en3.pack()
button.pack()
root.mainloop()
















































    

   





 






        
        
        
        
    




        
        
        
    