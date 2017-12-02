#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct node{
   node *left,*right,*father;
   int data;
}node,*Tree;
typedef struct Queue{
    node*  buf[20];
    int front,rear;
}Queue;
void inque(Queue &Q,node *p)
{
    Q.buf[Q.front]=p;
    Q.front++;
}
node *outque(Queue &Q)
{
    Q.rear++;
    return Q.buf[Q.rear-1];
}
void chushi(Queue &Q)
{
    Q.front=0;
    Q.rear=0;
}
void make(Tree &T)
{
    if(T->father!=NULL)
    {
        int m;
        if(T->data<T->father->data)
        {
            m=T->data;
            T->data=T->father->data;
            T->father->data=m;
            make(T->father);
        }
    }
}
void creat(Tree &T,Queue &Q)
{
    int data;
    node *p,*pr,*ptr;
    cin>>data;
    while(data!=0)
    {
        p=outque(Q);
        pr=(node*)malloc(sizeof(node));
        pr->data=data;
        pr->left=NULL;
        pr->right=NULL;
        pr->father=p;
        p->left=pr;
        inque(Q,pr);
        make(pr);
        cin>>data;
        if(data!=0)
        {
            ptr=(node*)malloc(sizeof(node));
            ptr->data=data;
            ptr->left=NULL;
            ptr->right=NULL;
            ptr->father=p;
            p->right=ptr;
            inque(Q,ptr);
            make(ptr);
            cin>>data;
        }


    }
}
void create(Tree &T,Queue &Q)
{
    node *p;
    T=(node*)malloc(sizeof(node));
    cin>>T->data;
    T->left=NULL;
    T->father=NULL;
    T->right=NULL;
    inque(Q,T);
    creat(T,Q);
}
void print(Tree T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        print(T->left);
        print(T->right);
    }
}
void insert(Tree &T,Queue &Q,int data)
{
    node *p,*pr;
    p=(node*)malloc(sizeof(node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    pr=Q.buf[((Q.front+1)/2)-1];
    p->father=pr;
    if(Q.front%2!=0)
        pr->left=p;
    else
        pr->right=p;
    make(p);
    inque(Q,p);
}
void delet(Tree &T,Queue Q)
{
    node *p,*pr;
    if(T->left!=NULL && T->right!=NULL)
    {
        if(T->left->data>T->right->data)
        {
            T->data=T->right->data;
            delet(T->right,Q);
        }
        else
        {
            T->data=T->left->data;
            delet(T->left,Q);
        }

    }
    else
    {
        if(T->right==NULL && T->left!=NULL)
        {
            T->data=T->left->data;
            T->left=NULL;
        }
        if(T->right==NULL && T->left==NULL)
        {
            if(T==Q.buf[Q.front-1])
            {
                 if(Q.front%2!=0)
                    T->father->right=NULL;
                 else
                    T->father->left=NULL;
            }
            else
            {
                T->data=Q.buf[Q.front-1]->data;
                p=Q.buf[Q.front-1];
                if(Q.front%2!=0)
                    p->father->right=NULL;
                 else
                    p->father->left=NULL;

            }
        }
    }

}
int main()
{
    int data;
    Tree T;
    Queue Q;
    chushi(Q);
    create(T,Q);
    print(T);
    cout<<"²åÈëÔªËØ:";
    cin>>data;
    cout<<endl;
    insert(T,Q,data);
    print(T);
    cout<<endl;
    delet(T,Q);
    print(T);
    return 0;
}
