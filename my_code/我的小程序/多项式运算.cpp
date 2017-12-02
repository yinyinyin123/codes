#include <stdio.h>
#include <stdlib.h>

struct link {             //初始化
    int xishu;
    int zhishu;
    struct link *next;
};
struct link *put_in(struct link *head)  //建立链表 并将其初始化
{
    struct link *p=NULL;
    int xishu,zhishu;
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
        scanf("%d",&xishu);
        scanf("%d",&zhishu);
        p->xishu=xishu;
        p->zhishu=zhishu;
        p->next=NULL;
    }while(getchar()!='\n');
    return head;
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
struct link *make(struct link *head,int lengh) //排序
{
    struct link  *p=NULL;
    struct link  *pr;
    int i,j,ma,zhishu,t,s;
    for(i=1;i<=lengh;i++)
    {
        p=head;
        for(j=1;j<lengh;j++)
        {
           pr=p->next;
           if(p->zhishu > pr->zhishu)
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
void print(struct link *head)   //打印链表
{
    struct link *p=head;
    while(p!=NULL)
    {
        printf("%d*",p->xishu);
        printf("X**");
        printf("%d\n",p->zhishu);
        p=p->next;
    }
}
int main()
{
   struct link *head=NULL;
   struct link *head1=NULL;
   int leng;
   head=put_in(head);
   head1=put_in(head1);
   head=multip(head,head1);
   leng=lengh(head);
   head=make(head,leng);
   print(head);
   getchar();
   return 0;
}
