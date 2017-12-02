#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node{
    char data;
    node *left,*right;
    int lflag,rflag;
}node,*Tree;


node *pre=NULL;

void creat(Tree &T)
{
    char data;
    cin>>data;
    if(data != '#')
    {
        T=(node*)malloc(sizeof(node));
        T->left = NULL;
        T->right = NULL;
        cin>>T->lflag>>T->rflag;
        T->data=data;
        if(pre != NULL)
        {
            if(pre->rflag==0)
                pre->right=T;
            if(T->lflag==0)
                T->left=pre;
        }
        pre=T;
        creat(T->left);
        creat(T->right);
    }
}
void preorder(Tree T)
{
    if(T != NULL)
    {
        cout<<T->data<<" ";
        if(T->lflag==1)
            preorder(T->left);
        else
            preorder(T->right);
    }
}
int main()
{
    Tree T;
    T=NULL;
    creat(T);
    cout<<"preorder:";
    preorder(T);
    return 0;
}
