# -*- coding: utf-8 -*-
"""
Created on Wed Nov 11 21:48:28 2015

@author: yinyin
""" 
from  Tkinter import  *
a1=raw_input('input  your kaisa:').upper()
b1=raw_input()
def  abc(a1,b1):
    for  i  in range(len(a1)):
        if  a1[i] in  'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            ord1=ord(a1[i])+int(b1)
            if  ord1>90:
                ord1=ord1-26
            if  ord1<65:
                ord1=26+ord1
            a1=a1[:i]+chr(ord1)+a1[i+1:]
    print  a1
abc(a1,b1)
a2=raw_input('input  your  jiami  number:').upper()
b2=raw_input()
for i  in  range(len(a2)):
    if  a2[i]  in  'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        ord2=ord(a2[i])-int(b2)
        if  ord2>90:
            ord2=ord2-26
        if  ord2<65:
            ord2+=26
        a2=a2[:i]+chr(ord2)+a2[i+1:]
print  a2
a3=raw_input()
k=raw_input()
a4=a3.upper()
dicti={}
for i in range(1,26):
    for  a  in  range(len(a4)):
        if  a4[a] in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            ord2=ord(a4[a])+1
            if  ord2>90:
                ord2-=26
            if  ord2<65:
                ord2+=26
            a4=a4[:a]+chr(ord2)+a4[a+1:]
    list1=a4.split()
    dicti[i]=list1
list5=[]
list3=[]
dic={}
f=open('C:\\Users\\yinyin\\Desktop\\dic.txt')
for  lines in f:
    list3.append(lines.strip().upper())
f.close()
list8=dicti.items()
for a,b  in  list8:
    str2=''
    s=0
    for i in  b:
        str2+=i
    for  j in list3:
        if  j in  i:
            s+=1
    list5.append(s)
    dic[a]=s
list10=dic.items()
list11=[]
list5.sort(reverse=True)
list7=list5[:int(k)]
for  i  in list7:
    str3=''
    for  a,s in  list10:
        if  i==s:
            if a  in list11:
                continue
            else:
                for g in  dicti[a]:
                    str3+=g+' '
               
                    list11.append(a)
                print  str3
                break    
   

                
    
    
        


    
            

    
    




    
    




        

        
       
         

        
        
    