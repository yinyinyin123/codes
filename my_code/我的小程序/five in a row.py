


from Tkinter import *

from turtle import *


i=0

a=[]
b=[]


def ha(event):
   
    global  i
   
      

    i+=1
    

    x=event.x/40.0

    y=event.y/40.0

    x1=int(x)

    y1=int(y)

    if  (x1+0.5)<x  and  (y1+0.5)<y  :

       

                

               



        if i%2==0:


           

            
           

            cvs.create_oval((x1+1)*40-15,(y1+1)*40-15,(x1+1)*40+15,(y1+1)*40+15, fill = "red")

            b.append([x1+1,y1+1])
        
        else:
                     
            cvs.create_oval((x1+1)*40-15,(y1+1)*40-15,(x1+1)*40+15,(y1+1)*40+15, fill = "green")

            a.append([x1+1,y1+1])
       
    
             

    if  (x1+0.5)<x  and  (y1+0.5)>y:


      
               if i%2==0:


                 cvs.create_oval((x1+1)*40-15,(y1)*40-15,(x1+1)*40+15,(y1)*40+15, fill = "red")
                 b.append([x1+1,y1])
               else:

                 cvs.create_oval((x1+1)*40-15,(y1)*40-15,(x1+1)*40+15,(y1)*40+15, fill = "green")

                 a.append([x1+1,y1])
               

       

    if  (x1+0.5)>x  and (y1+0.5)<y:


               if i%2==0:
            

                   cvs.create_oval((x1)*40-15,(y1+1)*40-15,(x1)*40+15,(y1+1)*40+15, fill = "red")
                   b.append([x1,y1+1])
               else:
                   
                   cvs.create_oval((x1)*40-15,(y1+1)*40-15,(x1)*40+15,(y1+1)*40+15, fill = "green")

                   a.append([x1,y1+1])
              

    if  (x1+0.5)>x  and  (y1+0.5)>y:

       

               if i%2==0:

                 cvs.create_oval((x1)*40-15,(y1)*40-15,(x1)*40+15,(y1)*40+15, fill = "red")
                 b.append([x1,y1])
               else:
                  cvs.create_oval((x1)*40-15,(y1)*40-15,(x1)*40+15,(y1)*40+15, fill = "green")
      

                  a.append([x1,y1])
    
    nima=[]

   
   
    
   
    op=0
    while op<len(a):
        nima.append(a[op][0]*15+a[op][1])
        op+=1
    nima.sort()
        
    ip=0
    time2=1
    time3=1
    time4=1
    time5=1

    while ip<len(nima)-1:
        
        oop=nima[ip]

        i2=ip+1

        while i2<len(nima):

          if oop+1*time2==nima[i2]:

             time2+=1
           
            

          

        
          if oop+15*time3==nima[i2]:
              time3+=1

          if oop+14*time5==nima[i2]:
            time5+=1
            
          if oop+14*time5!=nima[i2] and oop+14*time5<nima[i2]:
            time5=1

          if oop+15*time3!=nima[i2] and oop+15*time3< nima[i2]:
            
            time3=1

          if  oop+16*time4==nima[i2]:

            time4+=1

          if  oop+16*time4!=nima[i2] and oop+16*time4<nima[i2]:

            time4=1
          elif oop+1*time2!=nima[i2] and oop+1*time2<nima[i2]:

            time2=1

          if  time2==5 or time3==5 or time4==5 or time5==5:

            root3=Tk()
            la=Label(root3,fg='green',bg='white',text='the green win')
            la.pack()
            root3.mainloop()
            
          i2+=1
         

        ip+=1
    

    
    ipp=0
    op1=0
    nima1=[]
    while op1<len(b):
        nima1.append(b[op1][0]*15+b[op1][1])
        op1+=1
    nima1.sort()

    
  

    timer2=1
    timer3=1
    timer4=1
    timer5=1

   

    

    while ipp<len(nima1)-1:
        
        oop=nima1[ipp]

        j=ipp+1

        while  j<len(nima1):

          if oop+1*timer2==nima1[j]:

              timer2+=1

          

        
          if oop+15*timer3==nima1[j]:

              timer3+=1
          if oop+14*timer5==nima1[j]:
              timer5+=1
          if oop+14*timer5!=nima1[j] and oop+14*timer5<nima1[j]:
              timer5=1

          if oop+15*timer3!=nima1[j] and oop+15*timer3<nima1[j]:
            
              timer3=1

          if  oop+16*timer4==nima1[j]:

             timer4+=1

          if  oop+16*timer4!=nima1[j] and oop+16*timer4<nima1[j]:

             timer4=1
          elif oop+1*timer2!=nima1[j] and oop+1*timer2<nima1[j]:
              time2=1
          

          if  timer2==5 or timer3==5 or timer4==5 or timer5==5:

              root4=Tk()
              laa=Label(root4,fg='red',text='the red win')
              laa.pack()
              root4.mainloop()
          j+=1

        ipp+=1
                         

        

            

            
               

     

         
     

            


        

   

    

    

   

      

       
       

        

       

   

root=Tk()

root.title("five in a row")

root.geometry("600x600")

root.resizable(width=False, height=False)

cvs=Canvas(width=600,height=600)

i=0

while i<=600:

    cvs.create_line(i,0,i,800)

    i+=40

j=0

while j<=600:

    cvs.create_line(0,j,600,j)

    j+=40

cvs.bind('<Button-1>',ha)


cvs.pack()





































root.mainloop()
