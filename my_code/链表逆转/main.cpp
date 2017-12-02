#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node{
   int data;
   node *next;
}node,*List;

void create(List &L , int data)
{
    node *p,*pr;
    if(L == NULL)
    {
        L=(node*)malloc(sizeof(node));
        L->data=data;
        L->next=NULL;
    }
    else
    {
        p=L;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        pr=(node*)malloc(sizeof(node));
        pr->next=NULL;
        pr->data=data;
        p->next=pr;
    }

}

void creat(List &L)
{
     int data;
     cin>>data;
     while(data != 0)
     {
         create(L , data);
         cin>>data;
     }
}

void print(List L)
{
    node *p;
    p=L;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
node* reverse(List &L)
{
    node *p,*pr,*ptr;
    p=L;
    pr=p->next;
    p->next=NULL;
    while(pr!=NULL)
    {
        ptr=pr->next;
        pr->next=p;
        if(ptr==NULL)
            return pr;
        p=pr;
        pr=ptr;
    }
}
int main()
{
   List L;
   L = NULL;
   creat(L);
   print(L);
   cout<<endl;
   L=reverse(L);
   print(L);
}
