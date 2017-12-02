# -*- coding: utf-8 -*-
"""
Created on Thu Nov 19 12:48:01 2015

@author: yinyin
"""
list3=[]
a=raw_input()
list2=a.split()
for  str2 in  list2:
    list3.append(int(str2))
def   select(n,list3):
    if  n==len(list3)-1:
        print  list3  
        return  
    else:
        min_=list3[n]
        y=-1
        for i in  range(n,len(list3)):
            if  min_>list3[i]:
                min_=list3[i]
                y=i
                t=list3[y]
        if  y!=-1:
            del  list3[y]
            list3.insert(n,t)
        select(n+1,list3)
select(0,list3)
  