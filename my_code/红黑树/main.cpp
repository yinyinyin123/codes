#include <iostream>
#include <malloc.h>

using namespace std;
int black = 0;
int red = 1;

typedef struct node{
    int color,data;
    node *left,*right,*father;
}node,*tree;
typedef struct RBtree{
    tree root;
    tree nil;
}RBtree;
void initialize(RBtree &RB)
{
    RB.nil=(node*)malloc(sizeof(node));
    RB.nil->color = black;
    RB.nil->data = 0;
    RB.nil->left = RB.nil;
    RB.nil->right = RB.nil;
    RB.nil->father = RB.nil;
    RB.root = RB.nil;
}
int leftrotate(RBtree &RB,node *t)
{
    node *p;
    p = t->right;
    if(t->right == RB.nil)
       return 1;
    if(t->father != RB.nil)
    {
        if(t->father->left == t)
            t->father->left = p;
        else
            t->father->right = p;
    }
    else
        RB.root = p;
    p->father = t->father;
    t->right = p->left;
    p->left->father = t;
    p->left = t;
    t->father = p;
    return 1;
}
int rightrotate(RBtree &RB,node *t)
{
    node *p;
    p = t->left;
    if(t->left == RB.nil)
        return 1;
    if(t->father != RB.nil)
    {
        if(t->father->left == t)
            t->father->left = p;
        else
            t->father->right = p;
    }
    else
        RB.root = p;
    p->father = t->father;
    t->left = p->right;
    p->right->father = t;
    p->right = t;
    t->father = p;
    return 1;
}
int insert_fix(RBtree &RB , node *t)
{
    while(t->father->color == red)
    {
        if(t->father->father->left == t->father)
        {
            if(t->father->father->right->color == red)
            {
                t = t->father->father;
                t->left->color = t->right->color = black;
                t->color = red;
            }
            else
            {
                if(t->father->right == t)
                {
                    t = t->father;
                    leftrotate(RB,t);
                }
                t->father->color = black;
                t->father->father->color = red;
                rightrotate(RB,t->father->father);
            }
        }
        else
        {
            if(t->father->father->left->color == red)
            {
                t = t->father->father;
                t->left->color = t->right->color = black;
                t->color = red;
            }
            else
            {
                if(t->father->left == t)
                {
                    t = t->father;
                    rightrotate(RB,t);
                }
                t->father->color = black;
                t->father->father->color = red;
                leftrotate(RB,t);
            }
        }
    }
    RB.root->color = black;
}
node* insert(RBtree &RB , int data)
{
    node *t,*p;
    int flag;
    t = RB.root;p=NULL;
    if(RB.root==RB.nil)
    {
        RB.root=(node*)malloc(sizeof(node));
        RB.root->data = data;
        RB.root->color = black;
        RB.root->father = RB.root->left = RB.root->right =  RB.nil;
        return RB.root;
    }
    while(t != RB.nil)
    {
        p = t;
        if(data < t->data)
        {
            flag = 0;
            t = t->left;
        }
        else
        {
            flag = 1;
            t = t->right;
        }
    }
    t = (node*)malloc(sizeof(node));
    t->data = data;
    t->color = red;
    t->father = p;
    t->left = t->right = RB.nil;
    if(flag==0)
        p->left = t;
    else
        p->right = t;
    insert_fix(RB,t);
}
void print(node *p)
{
    if(p->data != 0)
    {
        print(p->left);
        cout<<p->data<<"("<<p->color<<")"<<" ";
        print(p->right);
    }
}
void create_RB(RBtree &RB)
{
    int data;
    cin>>data;
    while(data != 0)
    {
        insert(RB,data);
        print(RB.root);
        cout<<endl;
        cin>>data;
    }
}
int find(node *p,int data)
{
    while(p->data != 0)
    {
        cout<<p->data<<" ";
        if(p->data == data)
            return 1;
        else if(p->data > data)
            p = p->left;
        else
            p = p->right;
    }
}
void find_the_data(RBtree RB)
{
    int data;
    cout<<"find the data:";
    cin>>data;
    while(data != 0)
    {
        if(find(RB.root,data))
            cout<<"find it";
        else
            cout<<"no this data";
        cout<<endl;
        cin>>data;
    }
}
int main()
{
    RBtree RB;
    initialize(RB);
    create_RB(RB);
    find_the_data(RB);
}
