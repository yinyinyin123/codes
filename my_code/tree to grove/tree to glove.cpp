#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node{
   char data;
   node *left,*right;
}node,*tree;
typedef struct Node{
    char data;
    Node* son[0];
    int num;
}Node,*Grove;



void creat(tree &T)
{
    char data;
    cin>>data;
    if(data!='#')
    {
        T=(node*)malloc(sizeof(node));
        T->right=NULL;
        T->left=NULL;
        T->data=data;
        creat(T->left);
        creat(T->right);
    }
}
void chushi(Grove &G,tree T)
{
    G=(Node*)malloc(sizeof(Node));
    G->data=T->data;
}
int number_of_son(tree T)
{
    int k=1;
    while(T->right!=NULL)
    {
        k++;
        T=T->right;
    }
    return k;
}
void tree_to_grove(Grove &G , tree T)
{
    int k=0;
    node *pr;
    if(T->left!=NULL)
    {
        pr=T->left;
        k=number_of_son(pr);
    }
    G=(Node*)malloc(sizeof(Node)+k*sizeof(Node));
    G->data=T->data;
    G->num=k;
    for(int i=1;i<=k;i++)
    {
        tree_to_grove(G->son[i],pr);
        pr=pr->right;
    }
}
int number(tree T)
{
    int k=1;
    while(T->right!=NULL)
    {
        k++;
        T=T->right;
    }
    return k;
}
void print(Grove G)
{
    cout<<G->data;
    for(int i=1;i<=G->num;i++)
    {

        print(G->son[i]);
    }
}
int main()
{
    int k;
    tree T;
    creat(T);
    k=number(T);
    Grove G[k+1];
    for(int i=1;i<=k;i++)
    {
       tree_to_grove(G[i],T);
       T=T->right;
    }
    for(int i=1;i<=k;i++)
    {
       print(G[i]);
       cout<<endl;
    }
    return 0;
}
