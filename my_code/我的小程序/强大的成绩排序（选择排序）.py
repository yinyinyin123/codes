# -*- coding: utf-8 -*-
"""
Created on Tue Oct 20 14:56:09 2015

@author: yinyin
"""

list1=[[129,12,34,12,56,67],[130,34,12,34,41,3],[129,12,34,12,56,66],[130,23,34,12,67,2],[129,25,31,65,76,12],[156,34,32,21,4,78],[55,34,21,34,23,12],[129,12,34,13,56,67]]
def  paixu(n,list1):
    c=len(list1)
    if  n==len(list1)-1:
        print  list1
        return
    else:
        max_=list1[0]
        for  i  in  range(c-n):
            
            if  max_[0]<list1[i][0]:
                max_=list1[i]
                print  max_
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
paixu(0,list1)


                            
            
            
            
    
    
    
    
    