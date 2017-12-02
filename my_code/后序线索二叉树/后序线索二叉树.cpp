#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct node{
   node *left,*right,*father;
   char data;
   int lflag,rflag;
}node,*Tree;
node  *pre=NULL;
void create(Tree &T,node *pre)
{
    char data;
    cin>>data;
    if(data!='#')
    {
        T=(node*)malloc(sizeof(node));
        T->left=NULL;
        T->right=NULL;
        T->father=NULL;
        T->data=data;
        if(pre!=NULL)
            T->father=pre;
        create(T->left,T);
        create(T->right,T);
    }
}
node *pree=NULL;
void after_T(Tree &T)
{
    if(T != NULL)
    {
        after_T(T->left);
        after_T(T->right);
        if(T->left!=NULL)
            T->lflag=1;
        else
            T->lflag=0;
        if(T->right!=NULL)
            T->rflag=1;
        else
            T->rflag=0;
        if(pree!=NULL)
        {
            if(pree->rflag==0)
                pree->right=T;
            if(T->lflag==0)
                T->left=pree;
        }
        pree=T;
    }
}
int after_order_print(Tree T)
{
    node *p=T;
    node *pr;
    while(p)
    {
        while(true)
        {
            while(p->lflag!=0)
                p=p->left;
            while(p->rflag!=0)
                p=p->right;
            if(p->lflag==0)
                break;
        }
        while(p && p->rflag==0)
        {
            cout<<p->data<<" ";
            pr=p;
            p=p->right;
        }
        if(p==T)
        {
            cout<<p->data;
            return 0;
        }
        while(p && p->right==pr)
        {
            cout<<p->data<<" ";
            pr=p;
            p=p->father;
        }
        if(p)
        {
            if(p->rflag==0)
            {
                cout<<p->data<<" ";
                p=p->right;
            }
            else
                p=p->right;
        }
    }
}
int main()
{
    Tree T;
    create(T,pre);
    after_T(T);
    after_order_print(T);
    return 0;
}
