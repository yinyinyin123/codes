#include <iostream>
#include <malloc.h>


using namespace std;

typedef struct Node{    //动态哈夫曼树
    char data;
    int quan,key; //权值
    Node *left,*right,*father;
}Node,*Huffman;
typedef struct node{
    char data;
    node *next;
    Node *dat;//存储节点字符
}node;
typedef struct SKT{    //带有溢出表的内散列法存储字符和所在节点位置
   node *head[10];
   int  num;
}SKT;
typedef struct stac{   //利用栈编码
    int top;
    char code[10];
}stac;
stac  sta;
Node *vip;
Node *head;
int import;
void chushi_yichubiao(SKT &S)
{
    S.num=0;
    node *pr;
    for(int i=0;i<=9;i++)
    {
        pr=(node *)malloc(sizeof(node));
        pr->next=NULL;
        pr->data='#';
        S.head[i]=pr;
    }
}
void chushi_stack(stac &s)
{
    s.top=-1;
}
bool empty(stac s)
{
    if(s.top==-1)
        return true;
    return false;
}
char pop(stac &s)
{
    s.top--;
    return s.code[s.top+1];
}
void push(stac &s,char k)
{
    s.top++;
    s.code[s.top]=k;
}
void chushi_Huffman(Huffman &H)
{
    vip=(Node *)malloc(sizeof(Node));
    vip->key=0;
    vip->data='#';
    vip->left=NULL;
    vip->right=NULL;
    vip->quan=51;
    vip->father=NULL;
    H=vip;
}
Node* first_input(char data,SKT S)  //判断是否第一次读入
{
    int m;
    node *p;
    m=(data+'20'-0)%10;
    p=S.head[m];
    while(p->next!=NULL)
    {

        if(p->next->data==data)
            return p->next->dat;
        p=p->next;
    }
    return NULL;
}
int flag=0;
Node *imp;
int the_max(int key,Huffman H)  //寻找节点所在的块中最大的点
{
    Node *pr;
    if(H!=NULL)
    {
        pr=H;
        if(pr->key==key && pr->quan>=flag)
        {
            flag=pr->quan;
            imp=pr;
            return 0;
        }
        else if(pr->key<key);
        else
        {
            the_max(key,pr->left);
            the_max(key,pr->right);
        }
    }
}
void add_one(Node *p,Huffman &H)  //节点递归key 加1
{
    int change,lflag,rflag;
    Node *pp;
    while(p!=NULL)
    {
        if(p==H)
            H->key++;
        else
        {
            flag=0;lflag=0;rflag=0;
            the_max(p->key,H);   //判断是否为块中最大
            if(imp->quan==p->quan)
                p->key++;
            else
            {
                change=p->quan;
                p->quan=imp->quan;    //换一下权值和指针
                imp->quan=change;
                if(p->father->left==p)
                     lflag=1;
                else
                     lflag=0;
                if(imp->father->left==imp)
                    rflag=1;
                else
                    rflag=0;
                if(lflag==0)
                    p->father->right=imp;
                else
                    p->father->left=imp;
                if(rflag==0)
                    imp->father->right=p;
                else
                    imp->father->left=p;
                pp=p->father;
                p->father=imp->father;
                imp->father=pp;
                p->key++;
            }
        }
        p=p->father;
    }
}
void output(Node *p,int k)   //编码
{
    while(p->father!=NULL)
    {
        if(p->left==NULL && k==1 )
            push(sta,p->data);
        else
        {
            if(p->father->left==p)
                push(sta,'0');
            else
                push(sta,'1');
        }
        p = p->father;
    }
    while(!empty(sta))
        cout<<pop(sta);
}
void add_yichubiao(Node *pr,SKT &S) //将字符加入溢出表
{
    int m;
    node *p,*ptr;
    m=(pr->data+'20'-0)%10;
    p=S.head[m];
    ptr=(node*)malloc(sizeof(node));
    ptr->data=pr->data;
    ptr->next=NULL;
    ptr->dat=pr;
    ptr->next=p->next;
    p->next=ptr;
}
void change_S(Node *p,SKT &S) //改变溢出表中字符原本的节点位置
{
    int m;
    node *pr;
    m=(p->data+'20'-0)%10;
    pr=S.head[m];
    while(pr->next!=NULL)
    {
        if(pr->next->data==p->data)
            pr->next->dat=p;
        break;
    }
}
void print_H(Huffman H)        //打印动态哈夫曼树
{
    if(H!=NULL)
    {
        cout<<H->data<<" "<<H->key<<" "<<H->quan<<endl;
        print_H(H->left);
        print_H(H->right);
    }
}
void creat(Huffman &H,SKT &S)  //建立哈夫曼树
{
    char data;
    cin>>data;
    Node *p,*pr,*pp;
    while(data!='#')
    {
        pp=first_input(data,S);
        if(pp==NULL)
        {
            vip->key++;
            p=(Node*)malloc(sizeof(Node));
            p->key=1;
            p->left=NULL;
            p->right=NULL;
            p->quan=vip->quan-1;
            p->data=data;
            p->father=vip;
            vip->right=p;
            pr=(Node*)malloc(sizeof(Node));
            pr->key=0;
            pr->left=NULL;
            pr->data='#';
            pr->right=NULL;
            pr->quan=vip->quan-2;
            vip->left=pr;
            pr->father=vip;
            output(p,1);   //输出编码.
            if(vip->father!=NULL)
                add_one(vip->father,H);
            add_yichubiao(p,S);
            vip=pr;
        }
        else
        {
            output(pp,0);
            add_one(pp,H);
            change_S(pp,S);
        }
        cout<<endl;
        print_H(H);
        cout<<endl;
        cin>>data;
    }
}
void jiema(char a[],int num,Huffman &G)
{
    Node *ptr;
    if(num <= import)
    {
        if(a[num]!='0' && a[num]!='1')
        {
            Node *p,*pr;
            G->key++;
            p=(Node*)malloc(sizeof(Node));
            p->data=a[num];
            p->key=1;
            p->father=G;
            p->quan=G->quan-1;
            p->left=NULL;
            p->right=NULL;
            G->right=p;
            pr=(Node*)malloc(sizeof(Node));
            pr->left=NULL;
            pr->right=NULL;
            pr->data='#';
            pr->father=G;
            G->left=pr;
            pr->quan=G->quan-2;
            pr->key=0;
            cout<<a[num];
            if(G->father!=NULL)
                add_one(G->father,head);
            cout<<endl;
            print_H(head);
            cout<<endl;
            jiema(a,num+1,head);
        }
        else if(a[num]=='0')
        {
            if(G->left->data!='#')
            {
                cout<<G->left->data;
                add_one(G->left,head);
                cout<<endl;
                print_H(head);
                cout<<endl;
                jiema(a,num+1,head);
            }
            else
                jiema(a,num+1,G->left);
        }
        else
        {
            if(G->right->data!='#')
            {
                cout<<G->right->data;
                add_one(G->right,head);
                cout<<endl;
                print_H(head);
                cout<<endl;
                jiema(a,num+1,head);
            }
            else
               jiema(a,num+1,G->right);
        }
    }
}
int main()
{
    SKT S;
    Huffman H;
    Huffman G;
    char a[30];
    chushi_stack(sta);
    chushi_Huffman(H);
    chushi_yichubiao(S);
    creat(H,S);
    cout<<"解码的长度:";
    cin>>import;
    for(int i=1 ; i <= import ;i++)
    {
        cin>>a[i];
    }
    chushi_Huffman(G);
    head=G;
    jiema(a,1,G);
    return 0;
}
