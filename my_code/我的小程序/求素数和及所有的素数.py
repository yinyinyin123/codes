# -*- coding: utf-8 -*-
"""
Created on Thu Nov 19 14:23:26 2015

@author: yinyin
"""

 
def   beautiful(aPrime,list,max):
    for  i  in  xrange(aPrime,max,aPrime):#把素数的倍数变为0
        list[i]=0
def allthePrime(max):
    List = range(0,max)
    prime = []#建立一个新列表
    for i in xrange(2,2000000):
        if  List[i] != 0:
            prime.append(List[i])#将不为0的第一数数加入列表
            beautiful(List[i],List,max)
    return   prime#返回列表
primelist=allthePrime(2000000)