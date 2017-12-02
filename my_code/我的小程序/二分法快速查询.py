# -*- coding: utf-8 -*-
"""
Spyder Editor

This temporary script file is located here:
C:\Users\yinyin\.spyder2\.temp.py
"""
a=raw_input()
b=int(a)
list1=[1,2,3,45,62,23,67,36,13,34,25,23,78,24,100,12]
list1.sort()
low=0
high=len(list1)-1
if list1[low]==b  or  list1[high]==b:
    print  'I find it'
else:
    while  low<high-1:
        d=list1[(low+high)/2]
        if  d>b:
            high=(low+high)/2
        elif d<b:
            low=(low+high)/2
        else:
            print  'I find it'
            break
    else:
        print  'no this word'
    

        
        
        
        
        
    
    

       


    

    
       
    
    
        

    
    
    
    
    


