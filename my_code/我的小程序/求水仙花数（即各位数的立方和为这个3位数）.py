# -*- coding: utf-8 -*-
"""
Created on Sat Nov 28 19:15:02 2015

@author: yinyin
"""

for   a in range(100,1000):
    b=a/100
    c=(a/10)%10
    d=a%10
    if  c==0 and  d!=0:
        if  b**3+d**3==a:
            print  a
    if  c!=0  and d==0:
        if  b**3+c**3==a:
            print  a
    if  c!=0  and  d!=0:
        if  b**3+c**3+d**3==a:
            print  a
    else:
        if  b**3==a:
            print  a
        
    