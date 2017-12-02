# -*- coding: utf-8 -*-
"""
Created on Fri Nov 20 22:35:45 2015

@author: yinyin
"""
l=[]
dic={}
list2=[]
a=raw_input()
while a!='======':
    list1=a.split(',')
    l.append(list1)
    a=raw_input()
b=raw_input()
w=raw_input()
c=raw_input()
o=raw_input()
list8=[]
for a in l:
    list8.append(int(a[0]))
for  a  in  l:
    dic[a[0]]=[int(a[2])+int(a[3])+int(a[4])+int(a[5])+int(a[6])]+[int(a[2]),int(a[3]),int(a[4]),int(a[5]),int(a[6])]+[a[1]]
    list2.append(dic[a[0]])
def  paixu(n,list1):
    c=len(list1)
    if  n==len(list1)-1:
        return list1
    else:
        max_=list1[0]
        for  i  in  range(c-n):
            if  max_[0]<list1[i][0]:
                max_=list1[i]
            if  max_[0]==list1[i][0] and  max_!=list1[i]:
                if  max_[1]<list1[i][1]:
                    max_=list1[i]
                if  max_[1]==list1[i][1]:
                    if max_[2]<list1[i][2]:
                        max_=list1[i]
                    if max_[2]==list1[i][2]:
                        if  max_[3]<list1[i][3]:
                            max_=list1[i]
                        if  max_[3]==list1[i][3]:
                            if  max_[4]<list1[i][4]:
                                max_=list1[i]
                            if  max_[4]==list1[i][4]:
                                if max_[5]<list1[i][5]:
                                    max_=list1[i]
        b=max_
        list1.remove(b)
        list1.insert(c-n-1,b)
        paixu(n+1,list1)
paixu(0,list2)
list6=list2
list6.reverse()
list3=dic.items()
dic2={}
for i  in  range(len(list6)):
    for  key,value  in list3:
        if  list2[i] == value:
            print  i+1,key,list6[i][6],list6[i][1],list6[i][2],list6[i][3],list6[i][4],list6[i][5],sum(list6[i][1:6]),float(sum(list6[i][1:6]))/5
            dic2[key]=i+1
print '******'
def a(l,f):
    def  swap(list1,a,b):
        i=list1[a]
        list1[a]=list1[b]
        list1[b]=i
        return  list1
    def  paxu(n,list1):
        if  n==len(list1)+1:
            return list1
        else:
            for i  in range(len(list1)-1-n):
                if list1[i][0]>list1[i+1][0]:
                    swap(list1,i,i+1)
                if  list1[i][0]==list1[i+1][0]:
                    if  list1[i][1]>list1[i+1][1]:
                        swap(list1,i,i+1)
                    if  list1[i][1]==list1[i+1][1]:
                        if  list1[i][2]>list1[i][2]:
                            swap(list1,i,i+1)
                        if  list1[i][2]==list1[i][2]:
                            if   list1[i][3]>list1[i+1][3]:
                                swap(list1,i,i+1)
                            if   list1[i][3]==list1[i+1][3]:
                                if  list1[i][4]>list1[i+1][4]:
                                    swap(list1,i,i+1)
                                if  list1[i][4]==list1[i+1][4]:
                                    if  list1[i][5]>list1[i+1][5]:
                                        swap(list1,i,i+1)
            paxu(n+1,list1)
    dic1={}
    list4=[]
    for a in l:
        dic1[a[0]]=[int(a[f])]+[int(a[2])+int(a[3])+int(a[4])+int(a[5])+int(a[6])]+[int(a[3]),int(a[4]),int(a[5]),int(a[6])]+[a[1]]
        list7=dic1.items()
        list4.append(dic1[a[0]])
    paxu(0,list4)
    list5=list4
    list5.reverse()
    for i in range(len(list5)):
        for  key,value1 in list7:
            if  list5[i]==value1:
                print  i+1,key,list5[i][6],list5[i][0]
    print  '******'
if  b=='yuwen':
    a(l,2)
elif b=='shuxue':
    a(l,3)
elif b=='yingyu':
    a(l,4)
elif b=='wuli':
    a(l,5)
else:
    a(l,6)
list8.sort()
e=int(c)
low=0
high=len(list8)-1
if list8[low]==e  or  list8[high]==e:
    print  e,dic[str(e)][6],dic[str(e)][1],dic[str(e)][2],dic[str(e)][3],dic[str(e)][4],dic[str(e)][5],dic[str(e)][0],float(dic[str(e)][0])/5,dic2[str(e)]
    print  '******'
else:
    while  low<high-1:
        d=list8[(low+high)/2]
        if  d>e:
            high=(low+high)/2
        elif d<e:
            low=(low+high)/2
        else:
            print   e,dic[str(e)][6],dic[str(e)][1],dic[str(e)][2],dic[str(e)][3],dic[str(e)][4],dic[str(e)][5],dic[str(e)][0],float(dic[str(e)][0])/5,dic2[str(e)]
            print '******'
            break
   


    
            
                
























