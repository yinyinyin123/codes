#include <stdio.h>
#include <stdlib.h>

struct link {             //��ʼ��
    float xishu;
    float zhishu;
    struct link *next;
};
struct link *put_in(struct link *head,int i)  //�������� �������ʼ��
{
    struct link *p=NULL;
    float xishu,zhishu;
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
        scanf("%f",&xishu);
        scanf("%f",&zhishu);
        p->xishu=i*xishu;
        p->zhishu=zhishu;
        p->next=NULL;
    }while(getchar()!='\n');
    return head;
}
int lengh(struct link *head)   //��ȡ������
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
void print(struct link *head)   //��ӡ����
{
    struct link *p=head;
    while(p!=NULL)
    {
        if(p->xishu>0)
             printf("+%.1f*",p->xishu);
        else
             printf("%.1f*",p->xishu);
        printf("X**");
        printf("%.1f",p->zhishu);
        p=p->next;
    }
}
struct link *append(struct link *head,struct link *head1)  //�ϲ�����������ӣ�
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

struct link *multip(struct link *head,struct link *head1)  //�˷�
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

struct link *make(struct link *head,int lengh,int flag) //����
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
    struct link *p=head;
    struct link *pr=head1;
    struct link *ptr=head2;
    struct link *ptrr=NULL;
    float a;
    int b,leng;
    printf("��Ϊ");
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
           printf("+%.1fx**%d",a,b);
        if(a<0)
           printf("%.1fx**%d",a,b);
        if(head->next!=NULL)
            head=head->next;
        else
            exit(0);
        p=head;
    }
    printf("\n��ʽ");
    print(head);
    return head;
}
int main()
{
   struct link *head=NULL;
   struct link *head1=NULL;
   struct link *head2=NULL;
   int leng;
   int a=4;
   if(a==1)           //  �ӷ�
   {
       head=put_in(head1,1);
       head1=put_in(head1,1);
       head=append(head,head1);
       leng=lengh(head);
       head=make(head,leng,1);
       print(head);
   }
   if(a==2)                   //����
   {
       head=put_in(head1,1);
       head1=put_in(head1,-1);
       head=append(head,head1);
       leng=lengh(head);
       head=make(head,leng,1);
       print(head);
   }
   if(a==3)                //�˷�
   {
       head=put_in(head1,1);
       head1=put_in(head1,1);
       head=multip(head,head1);
       leng=lengh(head);
       head=make(head,leng,1);
       print(head);
   }
   if(a==4)             //����
   {
       head=put_in(head1,1);
       head1=put_in(head1,1);
       head=division(head,head1,head2);
   }
   getchar();
   return 0;
}
