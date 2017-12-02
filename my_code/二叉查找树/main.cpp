#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node{
    int data;
    node *left,*right;
}node,*Tree;
void creat(Tree &T,int data)
{
    if( T == NULL )
    {
        T = (node *)malloc(sizeof(node));
        T->data = data;
        T->left=NULL;
        T->right=NULL;
    }
    else
    {
        if(T->data > data)
        {
            creat(T->left , data);
        }
        else
        {
            creat(T->right , data);
        }
    }
}
void create(Tree &T)
{
    int data;
    cin>>data;
    while(data != 0)
    {
        creat(T,data);
        cin>>data;
    }
}
void print(Tree T)
{
    if(T != NULL)
    {
        print(T->left);
        cout<<T->data<<" ";
        print(T->right);
    }
}
void my_insert(Tree &T , int data)
{
    cout<<"insert "<<data<<endl;
    creat(T , data);
    print(T);
}
node* left_of_right(Tree T)
{
    if(T==NULL)
    {
       return T;
    }
    else
    {
        while(T->left!=NULL)
        {
            T=T->left;
        }
        return T;
    }
}
Tree R;
node *ptr;
node * father(Tree T,node *p)
{
    if(T->data>p->data)
    {
        ptr=T;
        father(T->left,p);
    }
    else if(T->data<p->data)
    {
        ptr=T;
        father(T->right,p);
    }
    else
    {
        return ptr;
    }
}
void delet(Tree &T , int data)
{
    if(T==NULL)
    {
        cout<<"no this data";
    }
    else if(T->data==data)
    {
        node *pr;
        if(T->left==NULL && T->right==NULL)
        {
            ptr=T;
            pr=father(R,T);
            if(pr==T)
            {
                T=NULL;
            }
            else if(pr->data>data)
            {
                pr->left=NULL;
            }
            else
            {
                pr->right=NULL;
            }
        }
        else if(T->left==NULL && T->right!=NULL)
        {
            T=T->right;
        }
        else if(T->right==NULL && T->left!=NULL)
        {
            T=T->left;
        }
        else if(T->right!=NULL && T->left!=NULL)
        {
            pr=left_of_right(T->right);
            T->data=pr->data;
            delet(pr,pr->data);

        }
    }
    else
    {
        if(T->data>data)
        {
            delet(T->left,data);
        }
        else
        {
            delet(T->right,data);
        }
    }
}
int main()
{
    Tree  T;
    T=NULL;
    create(T);
    print(T);
    cout<<endl;
    my_insert(T,11);
    cout<<endl;
    //cout<<left_of_right(T->right)->data;

    for(int i=1;i<=11;i++)
    {
        R=T;
        delet(T,i);
        cout<<"detele the element "<<i<<".. the tree is";
        print(T);
        cout<<endl;
    }
}
