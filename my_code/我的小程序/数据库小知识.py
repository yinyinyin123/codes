# -*- coding: utf-8 -*-
"""
Spyder Editor

This temporary script file is located here:
C:\Users\yinyin\.spyder2\.temp.py
"""

import  sqlite3
cx = sqlite3.connect(':memory:')#建立数据库
cu=cx.cursor()#建立游标
cu.execute("create table catalog (id ,pid ,name ,nickname)")#建立数据库的第一行    
for t in[(0,10,'abc','Yu'),(1,20,'cba','Xu')]:
    cx.execute("insert into catalog values (?,?,?,?)", t)#想数据库中输入数据
cu.execute("select name  from catalog")     #在数据库中查询
list1=cu.fetchall()#列出查询结果
print  list1

cu.execute("update catalog set name='Boy' where id = 0")#更新数据库
cu.execute("delete from catalog where id = 1")#删除数据库中数据
cx.commit()#提交，新的数据库形成

    

       


    

    
       
    
    
        

    
    
    
    
    


