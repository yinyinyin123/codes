# -*- coding: utf-8 -*-
"""
Created on Fri Nov 20 17:05:41 2015

@author: yinyin
"""

def  swap(list1,a,b):
    i=list1[a]
    list1[a]=list1[b]
    list1[b]=i
    return  list1
list1=[[129,12,34,12,56,67],[130,34,12,34,41,3],[129,12,34,12,56,66],[130,23,34,12,67,2],[129,25,31,65,76,12],[156,34,32,21,4,78],[55,34,21,34,23,12],[129,12,34,13,56,67]]
def  paxu(n,list1):
    if  n==len(list1)+1:
        print list1
        return
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
paxu(0,list1)
            