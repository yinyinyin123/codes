#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct node{
    node *next;
    int data;
}node;
typedef struct dot{
   node *head;
   char data;
}dot;
typedef struct grapf{
   dot  G[10];
   int num;
}grapf;
int dfn[10];
int low[10];
void chushi(grapf &GG)
{
    GG.num=0;
    for(int i=1 ; i <= 9 ; i++)
    {
        GG.G[i].head=(node*)malloc(sizeof(node));
        GG.G[i].head->next=NULL;
    }
}
node* create_node(node *p,int k)
{
    p=(node*)malloc(sizeof(node));
    p->data=k;
    p->next=NULL;
    return p;
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
        pr=GG.G[a].head;
        while(pr->next!=NULL)
            pr=pr->next;
        pr->next=ptr;
        pptr=GG.G[b].head;
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
        p=GG.G[i].head->next;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
int cont=1,flag = 0;
void DFN(int k , grapf GG)
{
    int min,data;
    node *p;
    cont++;
    dfn[k] = cont; //遍历的时间数组由全局变量来确定
    min = cont; // 先将min初始为遍历的时间
    for(p = GG.G[k].head->next ; p != NULL ; p = p->next)
    {
        data=p->data;
        if(dfn[data]==0)
        {
            DFN(data,GG);
            if(low[data] < min) //判断min和先深后序的节点的大小
                min = low[data];
            if(low[data] >= dfn[k]) //第二类关节点
            {
                cout<<GG.G[k].data<<" ";
                flag = 1;
            }
        }
        else if(dfn[data] < min) //判断回退边的dfn和min的大小
            min = dfn[data];

    }
    low[k]=min;  //将min赋值给low
}
void shuang_lian_tong(grapf GG)
{
    node *p;
    dfn[1] = 1;
    low[1] = 1;
    for(int i=2 ; i <= GG.num ; i++) //初始化遍历时间
    {
        dfn[i] = 0;
    }
    p = GG.G[1].head->next; //先从1邻接的点开始先深遍历
    DFN(p->data,GG);
    if(cont<GG.num)  //如果cont<点的总个数，那么说明节点1还有其他的子树，属于第一类关节点
    {
        cout<<GG.G[1].data<<" ";
        flag=1;
        while(p->next != NULL) //接着1下一个邻接点先深遍历
        {
            p = p->next;
            if(dfn[p->data]==0)
                DFN(p->data,GG);
        }
    }
    if(cont < GG.num || flag==1)
        cout<<"this is not shuang lian tong tu";
    else
        cout<<"this is shuang lian tong tu";

}
int main()
{
    grapf GG;
    chushi(GG);
    creat(GG);
    print(GG);
    shuang_lian_tong(GG);
    return 0;
}
