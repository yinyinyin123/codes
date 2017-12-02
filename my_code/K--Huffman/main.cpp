#include <iostream>
#include <malloc.h>
#include <fstream>

using namespace std;

typedef struct node{
   node *next[5];
   int data;
   char dat;
}node,*tree;

typedef struct Node{
   Node *next;
   char data;
   int quan;
}Node;
typedef struct hush{
   Node *head[10];
}hush;
typedef struct buf{
   char data;
   int quan;
}buf;
int num=0;
int front=0,rear=0;
node *head;
void chushi(hush &h)
{
    for(int i=0;i<=9;i++)
    {
        h.head[i] = (Node*)malloc(sizeof(Node));
        h.head[i]->next = NULL;
    }
}
int input(hush &h,int k,char data)
{
    cout<<data;
    Node *p,*pr;
    p=h.head[k];
    while(p->next!=NULL)
    {
        if(p->next->data==data)
        {
            p->next->quan++;
            return 1;
        }
        else
            p=p->next;
    }
    pr=(Node *)malloc(sizeof(Node));
    pr->quan=1;
    pr->next=NULL;
    pr->data=data;
    p->next=pr;

}
void creat(buf B[],hush h)
{
    Node *p,*pr;
    for(int i=0 ; i<=9 ; i++)
    {
        p=h.head[i];
        while(p->next!=NULL)
        {
            B[num].data=p->next->data;
            B[num].quan=p->next->quan;
            num++;
            p=p->next;
        }
    }
}
void print(buf B[])
{
    for(int i=0;i<num;i++)
    {
        cout<<"("<<B[i].data<<","<<B[i].quan<<")"<<endl;
    }
}
void quicksort(buf B[] , int i , int j)  //对权重进行排序
{
    int left,right,key;
    char data;
    if( i < j )
    {
        left=i;
        right=j;
        key=B[left].quan;
        data=B[left].data;
        while(left < right)
        {
            while(left < right && B[right].quan >= key )
                right--;
            B[left].quan=B[right].quan;
            B[left].data=B[right].data;
            while(left < right && B[left].quan < key)
                left++;
            B[right].quan=B[left].quan;
            B[right].data=B[left].data;
        }
        B[left].data = data;
        B[left].quan = key;
        quicksort(B,i,left-1);
        quicksort(B,left+1,j);
    }
}
void make(buf B[] , int k)
{
    if(k==1)
    {
        num=num+1;
        for(int i=num-1 ; i >= 1 ; i--)
        {
            B[i].data=B[i-1].data;
            B[i].quan=B[i-1].quan;
        }
        B[0].data='#';
        B[0].quan=0;
    }
    else if(k==2)
    {
        num+=2;
        for(int i=num-1 ; i >= 1;i--)
        {
            B[i].data=B[i-2].data;
            B[i].quan=B[i-2].quan;
        }
        B[0].data='#';
        B[1].data='#';
        B[0].quan=0;
        B[1].quan=0;
    }
    else
    {
        num+=3;
        for(int i=num-1 ; i >= 1;i--)
        {
            B[i].data=B[i-3].data;
            B[i].quan=B[i-3].quan;
        }
        B[0].data='#';
        B[1].data='#';
        B[0].quan=0;
        B[1].quan=0;
        B[2].quan=0;
        B[2].data='#';
    }
}
node* creat_node(node *p)
{
    p=(node*)malloc(sizeof(node));
    for(int i=0 ; i<=4 ; i++)
        p->next[i] = NULL;
    return p;
}
int fron=0;//the buf of B de xiabiao
node *C_node[20];
node *B_ndoe[20];
int  find_the_min(buf B[],buf C[],node *p,int i)
{
    node *pr;
    if(fron>=num)
    {
        front++;
        p->next[i]=C_node[front-1];
        return  C[front-1].quan;
    }
    else
    {
        if(rear==front)
        {
            fron++;
            pr=creat_node(pr);
            pr->data=B[fron-1].quan;
            pr->dat=B[fron-1].data;
            p->next[i]=pr;
            return  B[fron-1].quan;
        }
        else
        {
            if( B[fron].quan >= C[front].quan)
            {
                front++;
                p->next[i]=C_node[front-1];
                return C[front-1].quan;
            }
            else
            {
                fron++;
                pr=creat_node(pr);
                pr->dat=B[fron-1].data;
                pr->data=B[fron-1].quan;
                p->next[i]=pr;
                return B[fron-1].quan;
            }
        }
    }


}
node* create(buf B[],tree &T,buf C[])  //建立树
{
    node *pr;
    while(fron!=num || rear-1!=front)
    {
        int y=0,z;
        pr=creat_node(pr);
        for(int i=0;i<=4;i++)
        {
            z=find_the_min(B,C,pr,i);
            y+=z;
        }
        C[rear].quan=y;
        C_node[rear]=pr;
        rear++;
        pr->dat='#';
        pr->data=y;
    }
    return pr;
}
void print(tree T)  //先序输出树
{
    if(T!=NULL)
    {
        cout<<T->dat<<" ";
        for(int i=0;i<=4;i++)
        {
            print(T->next[i]);
        }
    }
}
int a[10];
int q=-1;
int flag=0;
node *head_;
int find_it(tree T,char data)  //在树中找到节点输出编码
{

    if(T!=NULL)
    {
        if(T->dat==data)
        {
            for(int j=0;j<=q;j++)
            {
                cout<<a[j];
                flag=1;
            }
        }
        for(int i=0 ; i<=4 ; i++)
        {
            q++;
            a[q]=i;
            find_it(T->next[i],data);
            if(flag==1)
                return 0;
            q--;
        }
    }
}
void bianma(tree T , char a[] , int k)
{
    char data;
    for(int i=0 ; i<k ; i++)
    {
        data=a[i];
        q=-1;
        flag=0;
        find_it(T,data);
    }
}
void jiema(char code[],int k,tree T)
{
    if(k <= q)
    {
        int i;
        i=code[k]-('0'-0);
        if(T->next[i]->dat!='#')
        {
            cout<<T->next[i]->dat;
            jiema(code,k+1,head_);
        }
        else
            jiema(code,k+1,T->next[i]);
    }

}
int main()
{
    ifstream in;
    tree T;
    int m;
    char data;
    hush h;
    char arr[100];
    int number=0;
    buf B[30];
    buf C[30];
    char code[200];
    chushi(h);
    char mm;
    in.open("ni.txt");
    in>>data;
    while(data!='#')
    {
        arr[number]=data;
        number++;
        m = (data+'20'-0)%10;
        input(h,m,data);
        in>>data;
    }
    creat(B,h);
    quicksort(B,0,num-1);
    cout<<endl;
    if((num-1)%4!=0)
        make(B,4-(num-1)%4);
    print(B);
    T=create(B,T,C);
    print(T);
    bianma(T,arr,number);
    cout<<endl;
    cout<<"½âÂë:";
    q=-1;
    cin>>mm;
    while(mm!='5')
    {
        q++;
        code[q]=mm;
        cin>>mm;
    }
    head_=T;
    jiema(code,0,T);

    return 0;
}
