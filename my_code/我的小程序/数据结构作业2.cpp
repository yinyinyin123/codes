#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cmath>
using namespace std;
struct node{
    char a;
    node *next;
};
struct link{
    int b;
    link *nex;
};
struct sta{
   link *first;
   link *last;
};
struct stac{
   node *first;
   node *last;
};
void print(stac S)
{
    struct node *p=S.last;
    if(S.first==NULL)
        printf("empty");
    while(p!=NULL)
    {
        printf("%c",p->a);
        p=p->next;
    }
}
int  change(stac &S,char b[],int i,int j,int c[])
{
    S.first=NULL;
    S.last=NULL;
    int cc;
    float bb;
    struct node *pr=S.first;
    struct node *p=NULL;
    struct node *pp=NULL;
    struct node *ptr=S.last;
    int u=1,m=0,opp=0,cpp,h=j-i;
    while(u<=j)
    {
        if(b[u]=='+' || b[u]=='-' || b[u]==')' || b[u]=='(' || b[u]=='*' || b[u]=='\\')
        {
            if(b[u]=='+' || b[u]=='-' )
                cpp=1;
            if(b[u]=='*' || b[u]=='\\')
                cpp=2;
            if(b[u]=='(')
                cpp=3;
            if(b[u]==')')
                cpp=4;
            if(cpp>opp)
            {
                p=(struct node *)malloc(sizeof(struct node));
                if(S.first==NULL)
                {
                    S.first=p;
                    S.last=S.first;
                    p->next=NULL;
                    p->a=b[u];
                    printf("%c 入栈\n",p->a);
                }
                else if(S.last==NULL)
                {
                    S.last=p;
                    p->next=S.first;
                    p->a=b[u];
                    printf("%c 入栈\n",p->a);
                }
                else
                {
                    p->next=S.last;
                    p->a=b[u];
                    printf("%c 入栈\n",p->a);
                    S.last=p;
                }
                pp=S.last;
                if(b[u]=='(')
                {
                    opp=0;
                    h--;
                    u++;

                    continue;
                }
                if(b[u]==')')
                {



                    pp=pp->next;

                    h--;
                    while(pp->a!='(')
                    {
                        c[m]=pp->a+0-'0';
                        m++;
                        pp=pp->next;
                    }
                    while(S.last->a!='(')
                    {

                        printf("%c 出栈\n",S.last->a);
                        S.last=S.last->next;
                    }

                    if(S.last->next==NULL)
                    {
                        if(S.first!=NULL)
                           printf("%c 出栈\n",S.first->a);
                        S.first=NULL;
                        S.last=NULL;
                        opp=0;
                    }
                    else
                    {

                       printf("%c 出栈\n",S.last->a);
                       S.last=S.last->next;
                       if(S.last->a=='+' || S.last->a=='-')
                         opp=1;
                       else
                         opp=2;
                    }
                    u++;
                    continue;
                }
                opp=cpp;
            }
            else
            {
                if(S.last==NULL)
                {
                    c[m]=S.first->a+0-'0';
                    printf("%c 出栈\n",S.first->a);
                    m++;
                    S.first->a=b[u];
                    printf("%c 入栈\n",b[u]);
                    if(b[u]=='+' || b[u]=='-')
                        opp=1;
                    else if(b[u]=='*' || b[u]=='\\')
                        opp=2;
                }
                else
                {

                    c[m]=S.last->a+0-'0';
                    printf("%c 出栈\n",S.last->a);
                    m++;
                    S.last->a=b[u];
                    printf("%c 入栈\n",b[u]);
                    if(S.last->next->a=='+' && S.last->next->a!='(' || S.last->next->a=='-' && S.last->next->a!='(')
                    {
                        c[m]=S.last->next->a+0-'0';
                        m++;
                        printf("%c 出栈\n",S.last->a);
                        S.last=S.last->next;
                        S.last->a=b[u];
                        printf("%c 入栈\n",b[u]);
                        opp=1;
                        continue;
                    }
                    opp=1;

                }

            }

        }

        else
        {
            cc=u;

            bb=0;


            while(cc<j && b[cc+1]=='1' || cc<j && b[cc+1]=='2' || cc<j && b[cc+1]=='3' || cc<j && b[cc+1]=='4'  || cc<j && b[cc+1]=='5'  ||  cc<j && b[cc+1]=='6' || cc<j && b[cc+1]=='7' || cc<j && b[cc+1]=='8' || cc<j && b[cc+1]=='9' || cc<j && b[cc+1]=='0')
            {
                cc++;
                h--;
            }

            while(u<=cc)
            {
                bb+=(b[u]+0-'0')*pow(10,cc-u);

                u++;
            }

            c[m]=bb;


            m++;
            u--;
        }
        u++;
    }

    if(S.last==NULL)
    {
        c[m]=S.first->a+0-'0';
        printf("%c 出栈\n",S.first->a);
        m++;

    }
    while(S.last!=NULL)
    {
        c[m]=S.last->a+0-'0';
        m++;
        printf("%c 出栈\n",S.last->a);
        S.last=S.last->next;

    }
    return h;
}
void printa(int h,int  c[])
{
    int i;
    char ch;
    for(i=0;i<=h;i++)
    {
        if(c[i]>=0)
          printf("%d ",c[i]);
        else
        {
            ch=c[i]+'0'-0;
            printf("%c ",ch);
        }
    }
}
void operate(sta &a,int ab,int c[])
{
    a.first=NULL;
    a.last=NULL;
    struct link *pr=a.first;
    struct link *p=NULL;
    struct link *pp=NULL;
    struct link *ptr=a.last;
    int i,mas=0;
    for(i=0;i<=ab;i++)
    {
        p=(struct link  *)malloc(sizeof(struct link));
        if(a.first==NULL)
        {
            a.first=p;
            a.first->nex=NULL;
            a.first->b=c[i];
        }
        else if(a.last==NULL)
        {
            a.last=p;
            a.last->nex=a.first;
            a.last->b=c[i];
        }
        else
        {
             p->nex=a.last;
             p->b=c[i];
             a.last=p;
        }
        if(a.last!=NULL && a.last->b==-5)
        {
            mas=a.last->nex->b+a.last->nex->nex->b;
            if(a.last->nex->nex==a.first)
            {
                a.last=NULL;
                a.first->b=mas;
                a.first->nex=NULL;
            }
            else
            {
                a.last=a.last->nex->nex;
                a.last->b=mas;
            }
        }
        else if(a.last!=NULL && a.last->b==-6)
        {
            mas=a.last->nex->b*a.last->nex->nex->b;
            if(a.last->nex->nex==a.first)
            {
                a.last=NULL;
                a.first->b=mas;
                a.first->nex=NULL;
            }
            else
            {
                a.last=a.last->nex->nex;
                a.last->b=mas;
            }
        }
        else if(a.last!=NULL && a.last->b==-3)
        {
            mas=a.last->nex->nex->b-a.last->nex->b;
            if(a.last->nex->nex==a.first)
            {
                a.last=NULL;
                a.first->b=mas;
                a.first->nex=NULL;
            }
            else
            {
                a.last=a.last->nex->nex;
                a.last->b=mas;
            }
        }
    }
    printf("%d",mas);
}
int main()
{
    char a[20];
    int c[100];
    stac Stack;
    sta Stack1;
    int r;
    int u;
    freopen("nimei.txt","r",stdin);
    cin>>a;
    r=change(Stack,a,1,22,c);
    printf("中錣表达式转换为后缀表达式为");
    printa(r,c);
    printf("\n算数表达式的结果为");
    operate(Stack1,r,c);
    return 0;
}


