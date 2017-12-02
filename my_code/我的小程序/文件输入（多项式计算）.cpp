#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

struct link {             //初始化
    float xishu;
    float zhishu;
    struct link *next;
};
void print(struct link *head)   //打印链表
{
    struct link *p=head;
    int i=0;
    freopen("daan.txt","w",stdout);

    while(p!=NULL)
    {
        if(p->xishu>0)
        {
                 cout<<"+"<<p->xishu<<"*";
                 i++;
        }
        else if(p->xishu<0)
        {
                 cout<<"-"<<p->xishu<<"*";
                 i++;
        }
        else
        {

            p=p->next;
            continue;
        }
        cout<<"X**";
        cout<<p->zhishu;
        p=p->next;
    }
    if(i==0)
    {
        cout<<0;
    }
}
struct link *put_in(struct link *head,int i)  //建立链表 并将其初始化
{
    struct link *p=NULL;
    float xishu,zhishu;

    char a;
    int j=1;
    freopen("zhi.txt","r",stdin);
    do
    {
        struct link *pr=head;
        p=(struct link *)malloc(sizeof(struct link ));
        if(p==NULL)
        {
            exit(0);
        }
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            while(pr->next!=NULL)
            {
                pr=pr->next;
            }
            pr->next=p;
        }
        cin>>xishu;
        cin>>zhishu;
        p->xishu=i*xishu;
        p->zhishu=zhishu;
        p->next=NULL;
    }while(a!='\n');
    print(head);
    return head;
}
int lengh(struct link *head)   //获取链表长度
{
    struct link *p=head;
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
   return i;
}

struct link *append(struct link *head,struct link *head1)  //合并俩个链表（相加）
{
    struct link *pr=head;
    struct link *p=head1;
    while(pr->next!=NULL)
    {
        pr=pr->next;
    }
    pr->next=p;
    return head;
}

struct link *multip(struct link *head,struct link *head1)  //乘法
{
    struct link *p=NULL;
    struct link *ptrhead=NULL;
    struct link *pp=ptrhead;
    struct link *pr=head;
    struct link *ptr=head1;
    while(pr!=NULL)
    {
        while(ptr!=NULL)
        {
            struct link *pp=ptrhead;
            p=(struct link *)malloc(sizeof(struct link));
            if(ptrhead==NULL)
            {
                ptrhead=p;
            }
            else
            {
                while(pp->next!=NULL)
                {
                    pp=pp->next;
                }
                pp->next=p;
            }
            p->next=NULL;
            p->xishu=(pr->xishu)*(ptr->xishu);
            p->zhishu=pr->zhishu+ptr->zhishu;
            ptr=ptr->next;
        }
        pr=pr->next;
        ptr=head1;
    }
    return ptrhead;
}

struct link *make(struct link *head,int lengh,int flag) //排序
{
    struct link  *p=NULL;
    struct link  *pr;
    int i,j;
    float t,s;
    for(i=1;i<=lengh;i++)
    {
        p=head;
        for(j=1;j<lengh;j++)
        {
           pr=p->next;
           if(flag*p->zhishu > flag*pr->zhishu)
           {
               t=p->zhishu;
               p->zhishu=pr->zhishu;
               pr->zhishu=t;
               s=p->xishu;
               p->xishu=pr->xishu;
               pr->xishu=s;
           }
           if(p->zhishu==pr->zhishu)
           {
               p->xishu=p->xishu+pr->xishu;
               p->next=pr->next;
               lengh--;
           }
           p=p->next;
        }
    }
    return head;
}
struct link *division(struct link *head,struct link *head1,struct link *head2)
{
    freopen("daan.txt","w",stdout);
    struct link *p=head;
    struct link *pr=head1;
    struct link *ptr=head2;
    struct link *ptrr=NULL;
    float a;
    int b,leng;
    printf("商为");
    leng=lengh(head);
    p=make(head,leng,-1);
    leng=lengh(head1);
    pr=make(head1,leng,-1);
    while(pr->xishu==0 )
    {
        printf("ok");
       if(pr->next==NULL)
        {
            cout<<"不允许除式为0";
            exit(0);
        }
        pr=pr->next;
    }
    if(p->zhishu<pr->zhishu)
    {
        cout<<0;
    }
    while(p->zhishu>=pr->zhishu)
    {


        b=p->zhishu - pr->zhishu;
        a=(float)(p->xishu)/pr->xishu;
        ptr=(struct link *)malloc(sizeof(struct link));
        ptr->xishu=(-1)*a;
        ptr->zhishu=b;
        ptr->next=NULL;
        ptrr=multip(head1,ptr);
        head=append(head,ptrr);
        leng=lengh(head);
        head=make(head,leng,-1);
        if(a>0)
          cout<<"+"<<a<<"x"<<"**"<<b;
        if(a<0)
            cout<<a<<"x"<<"**"<<b;
        if(head->next!=NULL)
            head=head->next;
        else
            exit(0);
        p=head;
    }
    cout<<"余式";
    print(head);
    return head;
}
int main()
{
   struct link *head=NULL;
   struct link *head1=NULL;
   struct link *head2=NULL;
   int leng;
   int oo;
   int a=3;  //建立链表 并将其初始化

   struct link *p=NULL;
   float xishu,zhishu;
   int j=1,flag=0,flag1=0,ba;
   int i=1;
   freopen("zhi.txt","r",stdin);
    cin>>oo;
    do
    {
        flag++;
        struct link *pr=head;
        p=(struct link *)malloc(sizeof(struct link ));
        if(p==NULL)
        {
            exit(0);
        }
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            while(pr->next!=NULL)
            {
                pr=pr->next;
            }
            pr->next=p;
        }
        cin>>xishu;
        cin>>zhishu;
        p->xishu=xishu;
        p->zhishu=zhishu;
        p->next=NULL;
    }while(flag<oo);
    cin>>ba;
   if(a==4)
        i=1;
    else if (a==3)
        i=1;
    else if(a==2)
        i=-1;
    else if(a==1)
        i=1;
    do
    {
        flag1++;
        struct link *pr=head1;
        p=(struct link *)malloc(sizeof(struct link ));
        if(p==NULL)
        {
            exit(0);
        }
        if(head1==NULL)
        {
            head1=p;
        }
        else
        {
            while(pr->next!=NULL)
            {
                pr=pr->next;
            }
            pr->next=p;
        }
        cin>>xishu;
        cin>>zhishu;
        p->xishu=i*xishu;
        p->zhishu=zhishu;
        p->next=NULL;
    }while(flag1<ba);






   if(a==1)           //  加法
   {

       head=append(head,head1);
       leng=lengh(head);
       head=make(head,leng,1);
       print(head);

   }
   if(a==2)                   //减法
   {

       head=append(head,head1);
       leng=lengh(head);
       head=make(head,leng,1);
       print(head);
   }
   if(a==3)                //乘法
   {

       head=multip(head,head1);
       leng=lengh(head);
       head=make(head,leng,1);
       print(head);
   }
   if(a==4)             //除法
   {

       head=division(head,head1,head2);
   }
   getchar();
   return 0;
}
