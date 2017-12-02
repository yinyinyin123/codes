#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct node{
   int data;
   node *left;
   node *right;
}Node,*BST;
void insert_BST(int data,BST &T)
{
    if(T==NULL)
    {
        T=(node *)malloc(sizeof(node));
        T->data=data;
        T->left=NULL;
        T->right=NULL;
    }
    else if(data<T->data)
        insert_BST(data,T->left);
    else if(data>T->data)
        insert_BST(data,T->right);
}
void create_BST(BST &T)
{
    int data;
    cin>>data;
    while(data)
    {
        insert_BST(data,T);
        cin>>data;
    }
}
void print_BST(BST T)  //中序遍历 即 按从小到大排序
{
    if(T!=NULL)
    {
        print_BST(T->left);
        cout<<T->data<<" ";
        print_BST(T->right);
    }
}
void find_data(BST T,int data)  // 查询元素在不
{
    if(T==NULL)
        cout<<"no data in the BST";
    else if(data==T->data)
        cout<<"find it";
    else if(data>T->data)
        find_data(T->right,data);
    else if(data<T->data)
        find_data(T->left,data);
}
int delete_data_extra(BST &T)  //删除时附带
{
    node *p;
    int m;
    while(T->left!=NULL)
        T=T->left;
    m=T->data;
    p=T;
    if(T->right!=NULL)
        T=T->right;
    free(p);
    return m;
}
void delete_data(int data,BST &T)   //删除元素
{
    if(T!=NULL)
    {
        if(data<T->data)
            delete_data(data,T->left);
        else if(data>T->data)
            delete_data(data,T->right);
        else
        {
            if(T->right==NULL)
                T=T->left;
            else if(T->left==NULL)
                T=T->right;
            else
            {
                T->data=delete_data_extra(T->right);
            }
        }
    }
    else
        cout<<"no this data";
}
node* insert_data(BST &T,int i)    //插入元素
{
    if(T==NULL)
    {
        node *p;
        p=(node *)malloc(sizeof(node));
        p->data=i;
        p->left=NULL;
        p->right=NULL;
        T=p;
    }
    else
    {
        if(T->data>i)
            insert_data(T->left,i);
        else if(T->data<i)
            insert_data(T->right,i);
    }
}
int main()
{
    BST T=NULL;
    create_BST(T);
    find_data(T,13);
    cout<<endl;
    delete_data(13,T);
    find_data(T,13);
    cout<<endl;
    print_BST(T);
    cout<<endl;
    insert_data(T,12);
    print_BST(T);
    cout<<endl;
    return 0;
}



