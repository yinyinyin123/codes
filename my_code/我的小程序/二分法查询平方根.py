# -*- coding: utf-8 -*-
"""
Created on Sat Dec 12 15:57:20 2015

@author: yinyin
"""

import math

a=raw_input()
b=int(a)
c=math.sqrt(b)

low=0
high=b
while  abs((low+high)/2.0-c)>0.0000000000000001:
    if  (low+high)/2.0>c:
        high=(low+high)/2.0
    else:
        low=(low+high)/2.0
print (low+high)/2.0



