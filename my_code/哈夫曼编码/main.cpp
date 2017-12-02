#include<iostream>
#include<fstream>
#include<malloc.h>
#include<string>

using namespace std;
typedef struct{
   char a;
   int number=0;
   string s;
   char m[2000];
   int num=-1;
}Q;
typedef struct node{
  char a;
  char p[2000];
  float b;
  node *lchild=NULL;
  node *rchild=NULL;
}node,*Node;
Q T[10000];
Node O[20000];
int o=-1;
int u=-1;
void paixu(Node O[],int i)
{
    int j,o1,k;
    float m,fl;
    char ch;
    node *ptr,*pptr;
    for(j=0;j<i;j++)
    {
        m=O[j]->b;

        k=j;
        for(o1=j;o1<=i;o1++)
        {
            if(O[o1]->b>m)
            {
                k=o1;
                m=O[o1]->b;
            }
        }
        if(j!=k)
        {
            fl=O[j]->b;
            O[j]->b=O[k]->b;
            O[k]->b=fl;
            ch=O[j]->a;
            O[j]->a=O[k]->a;
            O[k]->a=ch;
            ptr=O[j]->lchild;
            O[j]->lchild=O[k]->lchild;
            O[k]->lchild=ptr;
            pptr=O[j]->rchild;
            O[j]->rchild=O[k]->rchild;
            O[k]->rchild=pptr;
        }
    }
}
int c=0;
char a[200];
int yu;

int bianma(node *p)
{
    int i;
    if(p->lchild!=NULL)
    {
        u++;
        a[u]='0';
        bianma(p->lchild);
        a[u]='1';
        bianma(p->rchild);
        u--;
    }
    else
    {
        yu=p->a+20-'0';
        for(o=0;o<=u;o++)
        {
           T[yu].m[o]=a[o];
        }
        T[yu].num=u;
        cout<<p->a<<"      ";
        for(i=0;i<=T[yu].num;i++)
        {
            cout<<T[yu].m[i];
        }
        cout<<endl;
     }
}
void printa(node *p)
{
    if(p!=NULL)
    {
        printf("%f %c\n",p->b,p->a);
        printa(p->lchild);
        printa(p->rchild);
    }
}
node * nima(Node O[],int i)
{
    node *pr;
    while(i!=0)
    {
        paixu(O,i);
        pr=(node *)malloc(sizeof(node));
        pr->a='#';
        pr->b=O[i]->b+O[i-1]->b;
        pr->lchild=O[i-1];
        pr->rchild=O[i];
        O[i-1]=pr;
        i--;
    }
    cout<<"二叉树结构(先序)"<<endl;
    printa(pr);
    cout<<"哈夫曼编码"<<endl;
    bianma(pr);
    return pr;


}
int z[20000];
int z1=-1;
void zhuan(int a[])
{
    int i=0;
    int j=0;
    ofstream out;
    out.open("nima.txt");
    while(i<=z1)
    {
        for(j=0;j<=T[a[i]].num;j++)
        {
            out<<T[a[i]].m[j];
        }
        i++;
    }
    out.close();

}
void yima(node *p)
{
    ifstream in;
    string s;
    int b;
    node *pr;
    pr=p;

    in.open("nima.txt");

    while(getline(in,s))
    {

        b=0;
        while(s[b]!='\0')
        {

            while(pr->lchild!=NULL)
            {
                if(s[b]=='0')
                    pr=pr->lchild;
                else
                    pr=pr->rchild;
                b++;
            }

            cout<<pr->a;
            pr=p;

        }

    }
}
int main()
{
    string s;
    ifstream in;
    char c;
    int u;
    node *p,*pre;
    node *ptr;
    int d,b,max_char=0;
    in.open("nimei.txt");
    while(getline(in,s))
    {
        b=0;

        while(s[b]!='\0')
        {
            z1++;
            d=s[b]+0-'0';
            z[z1]=d+20;
            T[d+20].a=s[b];
            T[d+20].number++;
            b++;
            max_char++;
        }
    }
    printf("各类字符的频率(%%)\n");

    for(b=0;b<=999;b++)
    {
        if(T[b].number!=0)
        {
            o++;
            p=(node *)malloc(sizeof(node));
            p->a=T[b].a;
            p->b=100*float(T[b].number)/max_char;
            O[o]=p;
            printf("%c  %f\n",O[o]->a,O[o]->b);
        }

    }
    ptr=nima(O,o);
    printa(ptr);
    zhuan(z);
    in.close();
    yima(ptr);
    for(u=0;u<=o;u++)
    {
        free(O[u]);
    }
    printf("ok");
    return 1;
}
