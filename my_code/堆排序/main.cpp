#include <iostream>
#include<malloc.h>

using namespace std;

typedef struct node
{
    int data;
    node *left,*right;
}node,*Tree;
Tree p[10];
int top=-1,i=-1,iq=-1;
void creat_tree(Tree &T,int buf[])  //建立完全二叉树
{
    while(i<=12)
    {
        node *pr;
        if(top==-1)
        {
            T=(node *)malloc(sizeof(node));
            top++;
            i++;
            T->data=buf[i];
            T->left=NULL;
            T->right=NULL;
            p[top]=T;
        }
        else
        {
            iq++;
            pr=p[iq];
            if(i<=12)
            {
                pr->left=(node*)malloc(sizeof(node));
                i++;
                pr->left->data=buf[i];
                pr->left->left=NULL;
                pr->left->right=NULL;
                top++;
                p[top]=pr->left;
            }
            if(i<=12)
            {
                pr->right=(node *)malloc(sizeof(node));
                i++;
                pr->right->data=buf[i];
                pr->right->left=NULL;
                pr->right->right=NULL;
                top++;
                p[top]=pr->right;
            }
        }
    }
}
void print_tree(Tree T)
{
    if(T!=NULL)

    {
        cout<<T->data<<" ";
        print_tree(T->left);
        print_tree(T->right);
    }
}
void change_tree(Tree &T) //将完全二叉树树转换为堆
{
    int a;
    if(T->left!=NULL)
    {
         change_tree(T->left);

         if(T->right!=NULL)
         {
             change_tree(T->right);
             if(T->data<T->left->data || T->data<T->right->data)
             {
                 if(T->left->data<T->right->data)
                 {
                     a=T->right->data;
                     T->right->data=T->data;
                     T->data=a;
                 }
                 else
                 {
                     a=T->left->data;
                     T->left->data=T->data;
                     T->data=a;
                 }
             }
             change_tree(T->left);
             change_tree(T->right);
         }
         else
         {
             if(T->data<T->left->data)
             {
                 a=T->left->data;
                 T->left->data=T->data;
                 T->data=a;
             }
             change_tree(T->left);
         }
    }
}
int arr[5]={1,1,1,1,1};
int top1=-1;
int find_the_data(Tree &T,int a[])   //在无序序列中找到最后一个数
{
    int j;
    node *pptr,*T1=T;
    for(j=top1;j>=0;j--)
    {
        if(arr[j]==1)
        {
            pptr=T1;
            T1=T1->right;
        }
        else
        {
            pptr=T1;
            T1=T1->left;
        }
    }
    if(pptr->left==T1)
    {
        pptr->left=NULL;
    }
    else
        pptr->right=NULL;
    return T1->data;
}
void  heapsort(Tree &T)
{
     int m,i,d;
     int ptr;
     for(i=14;i>=1;i--)
     {
         m=i;
         cout<<T->data<<" ";
         while(m!=1)
         {
             d=m%2;
             top1++;
             if(d==0)
                arr[top1]=0;
             else
                arr[top1]=1;
             m=m/2;
         }
         if(top1!=-1)
         {
            ptr=find_the_data(T,arr);
            top1=-1;
            T->data=ptr;
            change_tree(T);   //建立新堆
         }

     }

}
int main()
{
    Tree T=NULL;
    int buf[14]={5,6,4,7,3,8,2,9,1,10,12,13,14,0};
    creat_tree(T,buf);
    change_tree(T);
    heapsort(T);
}
