#include <iostream>
#include<malloc.h>
using namespace std;

typedef struct node{
    node *next;
    int data;
}node;
typedef struct dot{
   node *head_out;  //data 为出弧
   node *head_in;  //data 为入弧
   char data;
}dot;
typedef struct grapf{
   dot  G[10];
   int num;
}grapf;
bool visited[10];
int cont[10];
int cot=0;
void chushi(bool visited[])
{
    for(int i=1;i<=9;i++)
        visited[i]=false;
}
void chushi(grapf &GG)
{
    GG.num=0;
    for(int i=1 ; i <= 9 ; i++)
    {
        GG.G[i].head_in=(node*)malloc(sizeof(node));
        GG.G[i].head_in->next=NULL;
        GG.G[i].head_out=(node*)malloc(sizeof(node));
        GG.G[i].head_out->next=NULL;
    }
}
node* create_node(node *p,int k)
{
    p=(node*)malloc(sizeof(node));
    p->data=k;
    p->next=NULL;
    return p;
}
int count=0;
void mm(grapf GG,int k)
{
    node *p;
    p=GG.G[k].head_out;
    visited[k]=true;
    p=p->next;
    while(p!=NULL)
    {
        if(!visited[p->data])
            mm(GG,p->data);
        p=p->next;
    }
    count++;
    cont[count]=k;
}
int flag=0;
int  DFS(grapf &GG,int k)
{
    node *p;
    visited[k]=true;
    for(p=GG.G[k].head_in->next;p!=NULL;p=p->next)
    {
        if(!visited[p->data])
        {
            flag++;
            DFS(GG,p->data);
        }
    }
    if(flag)
        cout<<k<<" ";

}
void strong(grapf GG)
{
    int i,j,k=1,m;
    chushi(visited);
    for(int v=1;v<=GG.num;v++)
    {
        if(!visited[v])
            mm(GG,v);
    }
    chushi(visited);
    for(j=GG.num;j>=1;j--)
    {
        i = cont[j];
        if(!visited[i])
        {
            flag=0;
            DFS(GG,i);
            if(flag!=0)
            {
                cout<<":this is the"<<k<<endl;
                k++;
            }
            cout<<endl;
        }
    }

}
void creat(grapf &GG)
{
    int num,a,b;
    node *pr,*pptr;
    cout<<"输入节点个数:";
    cin>>GG.num;
    cout<<"节点:";
    for(int i=1;i<=GG.num;i++)
    {
        cin>>GG.G[i].data;
    }
    cout<<endl;
    cout<<"边的个数:";
    cin>>num;
    cout<<endl<<"边:";
    for(int i=1;i<=num;i++)
    {
        node *p,*ptr;
        cin>>a>>b;
        p=create_node(p,a);
        ptr=create_node(ptr,b);
        pr=GG.G[a].head_out;
        while(pr->next!=NULL)
            pr=pr->next;
        pr->next=ptr;
        pptr=GG.G[b].head_in;
        while(pptr->next!=NULL)
            pptr=pptr->next;
        pptr->next=p;
    }
}
void print(grapf GG)
{
    node *p;
    for(int i=1;i<=GG.num;i++)
    {
        p=GG.G[i].head_out->next;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
void printi(grapf GG)
{
    node *p;
    for(int i=1;i<=GG.num;i++)
    {
        p = GG.G[i].head_in->next;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}
void print_(grapf GG)
{
    for(int i=1;i<=GG.num;i++)
        cout<<cont[i]<<" ";
}
int main()
{
    grapf GG;
    chushi(GG);
    chushi(visited);
    creat(GG);
    cout<<endl;
    strong(GG);
    return 0;
}
