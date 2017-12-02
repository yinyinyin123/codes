# -*- coding: utf-8 -*-
"""
Created on Sat Dec 12 16:09:36 2015

@author: yinyin
"""
import  math
a=raw_input()
b=int(a)
for  i  in  range(b-1):
    print '',
print   1
for  j in  range(b-2):
    print '',
print  '1 1'
for  z in  range(3,b+1):
    for  a in  range(b-z):
        print  '',
    print  1,
    for  y in  range(1,z-1):
        print  math.factorial(z-1)/(math.factorial(y)*math.factorial(z-y-1)),
    print  1
    
    
    
    
    
        
        
    