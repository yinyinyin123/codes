#include <iostream>
#include<malloc.h>

using namespace std;

typedef struct node{
   char data;
   node *left,*right;
}node,*Tree;
int get_the_position(char ch,char mid[],int i,int j)
{
    int a;
    for(a=i;a<=j;a++)
    {
        if(mid[a]==ch)
            return a;
    }
    return -1;
}
int  k=0,k2=7; //先序和后序遍历的下标
void pre_mid_creat_tree(char pre[],char mid[],int i,int j,Tree &T)
{
    T=(node*)malloc(sizeof(node));
    int a;
    a=get_the_position(pre[k],mid,i,j);
    if(a==-1)
    {
         T=NULL;
    }
    else if(a==i || a==j)
    {
        T->data=pre[k];
        T->left=NULL;
        T->right=NULL;
        k++;
    }
    else
    {
        T->data=pre[k];
        T->left=NULL;
        T->right=NULL;
        k++;
        pre_mid_creat_tree(pre,mid,i,a,T->left);
        pre_mid_creat_tree(pre,mid,a,j,T->right);
    }
}
void las_mid_creat_tree(char las[],char mid[],int i,int j,Tree &T)
{
    T=(node*)malloc(sizeof(node));
    int a;
    a=get_the_position(las[k2],mid,i,j);
    if(a==-1)
    {
         T=NULL;
    }
    else if(a==i || a==j)
    {
        T->data=las[k2];
        T->left=NULL;
        T->right=NULL;
        k2--;
    }
    else
    {
        T->data=las[k2];
        T->left=NULL;
        T->right=NULL;
        k2--;
        las_mid_creat_tree(las,mid,a,j,T->right);
        las_mid_creat_tree(las,mid,i,a,T->left);
    }
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
int main()
{
    Tree T;
    T=NULL;
    char pre[8]={'A','B','D','H','E','C','F','G'};
    char mid[8]={'H','D','B','E','A','F','C','G'};
    char las[8]={'H','D','E','B','F','G','C','A'};
    pre_mid_creat_tree(pre,mid,0,7,T);
    print(T);
    cout<<endl;
    las_mid_creat_tree(las,mid,0,7,T);
    print(T);
}
