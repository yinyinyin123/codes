#include<iostream>
#include<malloc.h>

using namespace std;


typedef struct node{
    char data;
    node *left,*right;
}node,*Tree;

typedef struct{
   node*  pin[30];
   int  front,rear;
}quene;

void create(Tree &T)
{
    char data;
    cin>>data;
    if(data!='#')
    {
        T=(node*)malloc(sizeof(node));
        T->data=data;
        T->left=NULL;
        T->right=NULL;
        create(T->left);
        create(T->right);
    }
}

void preorder(Tree T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        preorder(T->left);
        preorder(T->right);
    }
}
void beworder(Tree T)
{
    if(T!=NULL)
    {
        beworder(T->left);
        cout<<T->data<<" ";
        beworder(T->right);

    }
}
void afterorder(Tree T)
{
    if(T!=NULL)
    {
        afterorder(T->left);
        afterorder(T->right);
        cout<<T->data<<" ";
    }
}
int get_the_height(Tree T)
{
    if(T==NULL)
        return 0;
    else
    {
        if(get_the_height(T->left)>=get_the_height(T->right))
        {
            return 1+get_the_height(T->left);
        }
        else
            return 1+get_the_height(T->right);
    }
}
void push(node *p , quene &Q)
{
    Q.pin[Q.rear]=p;
    Q.rear++;
}
node *pop(quene &Q)
{
    Q.front++;
    return Q.pin[Q.front-1];
}
bool empty(quene Q)
{
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}
void order(Tree T , quene &Q)
{
    node *p;
    push(T,Q);
    while(!empty(Q))
    {
        p=pop(Q);
        cout<<p->data<<" ";
        if(p->left!=NULL)
        {
            push(p->left,Q);
        }
        if(p->right!=NULL)
        {
            push(p->right,Q);
        }
    }

}
int main()
{
     Tree T;
     T=NULL;
     create(T);
     quene Q;
     Q.front=0;
     Q.rear=0;
     preorder(T);
     cout<<endl;
     beworder(T);
     cout<<endl;
     afterorder(T);
     cout<<endl;
     cout<<get_the_height(T);
     cout<<endl;
     order(T,Q);
     return 0;

}
