#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct node{

    char data;
    typedef struct B{
        node* arr[10];
    }B;
    B M;
    int num;
}node,*Tree;
typedef struct note{
    char data;
    note *left,*right;
}note,*Nr;
typedef struct Trees{
    Tree  t[10];
}Trees;
int ii;
void create(Tree &T)
{
    T=(node*)malloc(sizeof(node));
    cout<<"输入节点信息和输入儿子个数:";
    cin>>T->data>>T->num;
    for(int m=0 ; m<=9 ; m++)
        T->M.arr[m] = NULL;
    if(T->num != 0)
    {
        for(int j=1 ; j<=T->num ; j++)
            create(T->M.arr[j]);
    }
}
void creat(Trees &T)
{
    cout<<"森林中的树的个数:";
    cin>>ii;
    for(int j=1 ; j<=ii ; j++ )
    {
        cout<<endl<<"make the "<<j<<"st tree";
        create(T.t[j]);
        cout<<"OK";
    }

}
void mak(Tree &T)
{
    for(int j=1 ; j <= T->num  ; j++)
    {
        if(j < T->num)
            T->M.arr[j]->M.arr[0] = T->M.arr[j+1];
        mak(T->M.arr[j]);
    }
}
void ma(Tree T , Nr &N)
{
    if(T != NULL)
    {
        N = (note*)malloc(sizeof(note));
        N->data = T->data;
        N->left = NULL;
        N->right = NULL;
        ma(T->M.arr[1],N->left);
        ma(T->M.arr[0],N->right);
    }
}
void make(Trees &T , Nr  &N)
{
    for(int j=1 ; j<ii ; j++)
    {
        T.t[j]->M.arr[0]=T.t[j+1];
    }
    for(int m=1 ; m<=ii ; m++)
        mak(T.t[m]);
    ma(T.t[1],N);
}
void print(Nr N)
{
    if(N != NULL)
    {
        cout<<N->data<<" ";
        print(N->left);
        print(N->right);
    }
}
int main()
{
    Trees T;
    Nr N;
    N=NULL;
    for(int i=1;i<=9;i++)
        T.t[i]=NULL;
    creat(T);
    make(T,N);
    cout<<endl<<"preorder:";
    print(N);
}
