#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node{
    int data;
    node *left,*right;
    int height;
}Node,*AVL;
int get_the_height(AVL L)
{
    if(L==NULL)
    {
        return 0;
    }
    else
    {
        if(get_the_height(L->left)>get_the_height(L->right))
            return 1+get_the_height(L->left);
        else
            return 1+get_the_height(L->right);
    }
}
node *rightrightRotation(AVL &L)  //ÓÒ ÓÒ
{
    node *p;
    p=L->right;
    L->right=p->left;
    p->left=L;
    return p;
}
node *leftleftRotation(AVL &L) //×ó ×ó
{
    node *p;
    p=L->left;
    L->left=p->right;
    p->right=L;
    return p;
}
node *leftrightRotation(AVL &L)// ×ó ÓÒ
{
     L->left=rightrightRotation(L->left);
     return  leftleftRotation(L);
}
node *rightleftRotation(AVL &L)  //ÓÒ ×ó
{
     L->right=leftleftRotation(L->right);
     return rightrightRotation(L);
}
void insert_AVL(int data,AVL &L)
{
    if(L==NULL)
    {
        L=(node *)malloc(sizeof(node));
        L->data=data;
        L->left=NULL;
        L->right=NULL;
    }
    else if(L->data>data)
    {
        insert_AVL(data,L->left);
        if(get_the_height(L->left)-get_the_height(L->right)==2)
        {

            if(data<L->left->data)     //×ó  ×ó
               L=leftleftRotation(L);
            else
               L=leftrightRotation(L);  //×ó ÓÒ
        }
    }
    else if(L->data<data)
    {
        insert_AVL(data,L->right);
        if(get_the_height(L->right)-get_the_height(L->left)==2)
        {
            if(data<L->right->data)
            {
                 L=rightleftRotation(L);   //ÓÒ ×ó
            }
            else
            {
                L=rightrightRotation(L);   //ÓÒ×ÓÊ÷µÄ ÓÒ
            }
        }
    }
}
void create_AVL(AVL &L)
{
    int data;
    cin>>data;
    while(data)
    {
        insert_AVL(data,L);
        cin>>data;
    }
}
void print_the_AVL(AVL L)
{
    if(L!=NULL)
    {
        print_the_AVL(L->left);
        cout<<L->data<<" ";
        print_the_AVL(L->right);
    }
}
int find_the_data(int data,AVL L)
{
    if(L==NULL)
    {
        cout<<"no this data"<<endl;
        return 0;
    }
    if(data==L->data)
    {
        cout<<"find it"<<endl;
        return 0;
    }
    else if(data>L->data)
        find_the_data(data,L->right);
    else if(data<L->data)
        find_the_data(data,L->left);
}
node* the_max_node(AVL L)
{
    while(L->right!=NULL)
        L=L->right;
    return L;
}
node * the_min_node(AVL L)
{
    while(L->left!=NULL)
        L=L->left;
    return L;
}
void tidy1(AVL &L,node *p)
{
    if(L->right==p)
    {
        L->right=p->right;
    }
    else
    {
        node *ptr;
        ptr=L->right;
        while(ptr->left!=p)
            ptr=ptr->left;
        ptr->left=p->right;
    }
}
void tidy(AVL &L,node *p)
{
    if(L->left==p)
        L->left=p->left;
    else
    {
        node *pr;
        pr=L->left;
        while(pr->right!=p)
            pr=pr->right;
        pr->right=p->left;
    }
}
node* delete_the_AVL(int data,AVL &L)
{
    if(L!=NULL)
    {
        if(L->data==data)
        {
            if(L->left!=NULL && L->right!=NULL)
            {
                if(get_the_height(L->left)>get_the_height(L->right))
                {
                    node *p,*pr;
                    p=the_max_node(L->left);
                    L->data=p->data;
                    tidy(L,p);
                }
                else
                {
                   node *p,*pr;
                   p=the_min_node(L->right);
                   L->data=p->data;
                   tidy1(L,p);
                }
            }
            else
            {
                node *ptr;
                ptr=L;
                if(L->left!=NULL)
                    L=L->left;
                else if(L->right!=NULL)
                    L=L->right;
                free(ptr);
                return NULL;
            }
        }
        else if(data>L->data)
        {
            L->right=delete_the_AVL(data,L->right);
            if (get_the_height(L->left) -get_the_height(L->right) == 2)
            {
                if (get_the_height(L->left->right)>get_the_height(L->left->left))
                    L = rightleftRotation(L);
                else
                    L = leftleftRotation(L);
            }
        }
        else if(data<L->data)
        {
            L->left= delete_the_AVL(data,L->left);

            if (get_the_height(L->right) - get_the_height(L->left) == 2)
            {

                if (get_the_height(L->right->left)>get_the_height(L->right->right))
                    L= leftrightRotation(L);
                else
                    L = rightrightRotation(L);
            }
        }
        return L;
    }
    return NULL;
}
int main()
{
    node *p;
    AVL L=NULL;
    create_AVL(L);
    print_the_AVL(L);
    cout<<endl;
    cout<<13 ;
    find_the_data(13,L);
    cout<<12 ;
    find_the_data(12,L);
    delete_the_AVL(13,L);
    print_the_AVL(L);
    cout<<endl;
    delete_the_AVL(10,L);
    print_the_AVL(L);
    return 0;
}
