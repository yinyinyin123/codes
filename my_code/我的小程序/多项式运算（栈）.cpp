#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
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
    while(p!=NULL)
    {
        printf("%c",p->a);
        p=p->next;
    }
}
int  change(stac &S,char b[],int i,int j,char c[])
{
    S.first=NULL;
    S.last=NULL;
    struct node *pr=S.first;
    struct node *p=NULL;
    struct node *pp=NULL;
    struct node *ptr=S.last;
    int u,m=0,opp=0,cpp,h=j-i;
    for(u=1;u<=j;u++)
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
                    p->next=NULL;
                    p->a=b[u];
                }
                else if(S.last==NULL)
                {
                    S.last=p;
                    p->next=S.first;
                    p->a=b[u];
                }
                else
                {
                    p->next=S.last;
                    p->a=b[u];
                    S.last=p;
                }
                pp=S.last;
                if(b[u]=='(')
                {
                    opp=0;
                    h--;
                    continue;
                }
                if(b[u]==')')
                {
                    pp=pp->next;
                    h--;
                    while(pp->a!='(')
                    {
                        c[m]=pp->a;
                        m++;
                        pp=pp->next;
                    }
                    while(S.last->a!='(')
                    {
                        S.last=S.last->next;
                    }
                    if(S.last->next==NULL)
                    {
                        S.first=NULL;
                        S.last=NULL;
                        opp=0;
                    }
                    else
                    {
                       S.last=S.last->next;
                       if(S.last->a=='+' || S.last->a=='-')
                         opp=1;
                       else
                         opp=2;
                    }
                    continue;
                }
                opp=cpp;
            }
             else
            {
                if(S.last==NULL)
                {
                    c[m]=S.first->a;
                    m++;
                    S.first->a=b[u];
                    if(b[u]=='+' || b[u]=='-')
                        opp=1;
                    else if(b[u]=='*' || b[u]=='\\')
                        opp=2;
                }
                else
                {
                    c[m]=S.last->a;
                    m++;
                    S.last->a=b[u];
                    if(S.last->next->a=='+' && S.last->next->a!='(' || S.last->next->a=='-' && S.last->next->a!='(')
                    {
                        c[m]=S.last->next->a;
                        m++;
                        S.last=S.last->next;
                        S.last->a=b[u];
                        opp=1;
                    }

                }
            }
        }
        else
        {
            c[m]=b[u];
            m++;
        }
    }
    if(S.last==NULL)
    {
        c[m]=S.first->a;
        m++;
    }
    while(S.last!=NULL)
    {
        c[m]=S.last->a;
        m++;
        S.last=S.last->next;
    }
    return h;
}
void printa(int h,char c[])
{
    int i;
    for(i=0;i<=h;i++)
    {
        printf("%c",c[i]);
    }
}
void operate(sta &a,int ab,char c[])
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
            a.first->b=c[i]+0-'0';
        }
        else if(a.last==NULL)
        {
            a.last=p;
            a.last->nex=a.first;
            a.last->b=c[i]+0-'0';
        }
        else
        {
             p->nex=a.last;
             p->b=c[i]+0-'0';
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
        else if(a.last!=NULL && a.last->b=='/')
        {
            mas=a.last->nex->b/a.last->nex->nex->b;
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
    char a[200];
    char c[20];
    stac Stack;
    sta Stack1;
    int r;
    int u;
    freopen("nimei.txt","r",stdin);
    cin>>a;
    r=change(Stack,a,1,21,c);
    operate(Stack1,r,c);
    return 0;
}
