# -*- coding: utf-8 -*-
"""
Created on Mon Nov 02 14:49:13 2015

@author: yinyin
"""
i=1
dictionary={}
while  i<=100:
    the_danchi=raw_input()
    list1=the_danchi.split()
    for a  in  list1:
        if dictionary.has_key(a):
            dictionary[a].add(i)
        else:
            dictionary[a]=set()
            dictionary[a].add(i)
    i+=1
list4=[]

for keys  in  dictionary:
    list4.append(keys)
list4.sort()
for  the_danchi1 in list4:
    list3=list(dictionary[the_danchi1])
    list3.sort()
    a=the_danchi1+': '
    for  i in  range(len(list3)-1):
        a+= str(list3[i])+', '
    a+=str(list3[len(list3)-1])
    print  a
your_danchi=raw_input()
list9=[]
o=''
if  your_danchi[:3]=='OR:':
    list6=your_danchi[3:].split()
    for  i  in list6:
        if  dictionary.has_key(i):
            list8=list(dictionary[i])
            list9+=list8    
    list10=list(set(list9))
    list10.sort()
    for  i in range(len(list10)-1):
        o+=str(list10[i])+', '
    o+=str(list10[len(list10)-1])
    print  o
elif  your_danchi[:4]=='AND:':
    list5=your_danchi[4:].split()
    for  i  in  list5:
        if  not dictionary.has_key(i):
            print  'None'
            break
    else:
        if len(list5)==1:
            f=list(dictionary[list5[0]])
            f.sort()
            for  i  in  range(len(f)-1):
                o+=str(f[i])+', '
            o+=str(f[len(f)-1])
            print  o
        else:
            for   i  in  range(len(list5)-1):
                c=dictionary[list5[i]]&dictionary[list5[i+1]]
                if   c!=set([]):
                    dictionary[list5[i+1]]=c
                else:
                    print  'None'
                    break
            else:
                list7=list(c)
                e=''
                list7.sort()
                for  i in range(len(list7)-1):
                    e+=str(list7[i])+', '
                e+=str(list7[len(list7)-1])
                print  e
else:
    list5=your_danchi.split()
    for  i  in  list5:
        if  not dictionary.has_key(i):
            print  'None'
            break
    else:
        if len(list5)==1:
            f=list(dictionary[list5[0]])
            f.sort()
            for  i  in range(len(f)-1):
                o+=str(f[i])+", "
            o+=str(f[len(f)-1])
            print  o
                
        else:
            for   i  in  range(len(list5)-1):
                c=dictionary[list5[i]]&dictionary[list5[i+1]]
                if   c!=set([]):
                    dictionary[list5[i+1]]=c
                else:
                    print  'None'
                    break
            else:
                list7=list(c)
                e=''
                list7.sort()
                for  i in range(len(list7)-1):
                    e+=str(list7[i])+', '
                e+=str(list7[len(list7)-1])
                print  e
    
    
  
            
        
    
    
    
    
    
    
    
    
    
   
        
    
    
    
    



    

    
    






 
 


