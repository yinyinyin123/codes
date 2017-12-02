#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *left ,*right , *father;
}node,*tree;


void creat_tree(tree &T , int data , node *pre)
{
    if(T == NULL)
    {
        T = new node;
        T->data = data;
        T->left = T->father = T->right = NULL;
        if(pre != NULL)
            T->father = pre;
    }
    else
    {
        if(T->data < data)
            creat_tree(T->right , data , T);
        else
            creat_tree(T->left  , data , T);
    }
}
void creat(tree &T)
{
    int data;
    node *pre = NULL;
    cin>>data;
    while(data != 0)
    {
        creat_tree(T , data , pre);
        cin>>data;
    }
}
void print(tree T)
{
    if(T != NULL)
    {
        cout<<T->data<<" ";
        print(T->left);
        print(T->right);
    }
}
void zig(node *p)
{
    node *temp,*temp1;
    int flag;
    temp1 = p->father->father;
    if(temp1 != NULL)
    {
        if(temp1->left == p->father)
            flag = 1;
        else
            flag = 0;
    }
    if(p->father->left == p)
    {
        temp = p->right;
        p->right = p->father;
        p->father->left = temp;
        p->father->father = p;
        if(temp!=NULL)
           temp->father = p->father;
    }
    else
    {
        temp = p->left;
        p->left = p->father;
        p->father->right = temp;
        p->father->father = p;
        if(temp != NULL)
            temp->father = p->father;
    }
    if(temp1 != NULL)
    {
        p->father = temp1;
        if(flag)
            temp1->left = p;
        else
            temp1->right = p;
    }
    else
        p->father = NULL;
}
void zig_zig(node *p)
{
    zig(p->father);
    zig(p);
}
void zig_zag(node *p)
{
    zig(p);
    zig(p);
}
node* adjust(node *p)
{
    while(p->father != NULL)
    {
        if(p->father->father == NULL)
        {
            cout<<"step 1:"<<endl;
            zig(p);
        }
        else if(p->father->left == p && p->father->father->left == p->father)
        {
            cout<<"step 2:"<<endl;
            zig_zig(p);
        }
        else if(p->father->right == p && p->father->father->right == p->father)
        {
            cout<<"step 3:"<<endl;
            zig_zig(p);
        }
        else if(p->father->right == p && p->father->father->left == p->father)
        {
            cout<<"step 4:"<<endl;
            zig_zag(p);
        }
        else if(p->father->left == p && p->father->father->right == p->father)
        {
            cout<<"step 5:"<<endl;
            zig_zag(p);
        }
        else
            cout<<"hi ! error"<<endl;
    }
    return p;

}
node* find_it(tree &T , int data)
{
    if(T == NULL)
    {
        cout<<"there is no this data";
        return NULL;
    }
    else
    {
        if(T->data > data)
            find_it(T->left , data);
        else if(T->data < data)
            find_it(T->right , data);
        else
        {
            cout<<"find it and now adjust it:"<<endl;
            return adjust(T);
        }
    }
}
void find_data(tree &T)
{
    int data;
    node *p;
    cin>>data;
    while(data != 0)
    {
        p = find_it(T,data);
        if(p != NULL)
          T = p;
        print(T);
        cout<<endl<<"the tree has been adjusted";
        cin>>data;
    }
}
int main()
{
    tree T;
    T = NULL;
    creat(T);
    print(T);
    find_data(T);
    return 0;
}
