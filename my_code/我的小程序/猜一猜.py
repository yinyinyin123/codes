# -*- coding: utf-8 -*-
"""
Created on Sat Jan 16 20:34:01 2016

@author: yinyin
"""

import  random

a=random.randint(0,100)
c=raw_input()
b=int(c)
while b!=a:
    if b>a:
        print 'your figure is too big'
    else:
        print 'your figure is too small'
    b=int(raw_input())
print  'good,you  guess  it'
