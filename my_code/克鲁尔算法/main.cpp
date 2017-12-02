#include <iostream>

using namespace std;

typedef struct node{
    int left_node;
    int right_node;
    int distance;
}node;
int imp=1;
int access[10];
int num;
void creat_node(node G[],int k)
{
    for(int i=1;i<=k;i++)
        cin>>G[i].left_node>>G[i].right_node>>G[i].distance;
}
void chushi(int access[])
{
    for(int i=1;i<=9;i++)
        access[i]=i;
}
void quicksort(node G[],int i,int j) //快排将节点数组按权值从大到小排序
{
    int low,high,key,m,n;
    if(i < j)
    {
        low=i;
        high=j;
        key=G[i].distance;
        m=G[i].left_node;
        n=G[i].right_node;
        while(low<high)
        {
            while(low < high && G[high].distance >= key)
                high--;
            G[low].distance=G[high].distance;
            G[low].left_node=G[high].left_node;
            G[low].right_node=G[high].right_node;
            while(low<high && G[low].distance < key)
                low++;
            G[high].distance=G[low].distance;
            G[high].left_node=G[low].left_node;
            G[high].right_node=G[low].right_node;
        }
        G[low].distance=key;
        G[low].left_node=m;
        G[low].right_node=n;
        quicksort(G,i,low-1);
        quicksort(G,low+1,j);
    }
}
void print(node G[],int k)
{
    for(int i=1;i<=k;i++)
        cout<<G[i].left_node<<" "<<G[i].right_node<<" "<<G[i].distance<<endl;
}
int the_number(int k)  //并查集
{
    while(access[k]!=k) //若下标与数组对应的值相等 返回，否则将数组对应的值赋予k，在进行递归
        k=access[k];
    return k;
}
void kruskal(node G[])
{
    int l=1,m,n,i=1; //  l为输出的边数，i为数组下标
    while(l <= num-1)
    {
        m = the_number(G[i].left_node); //运用并查集
        n = the_number(G[i].right_node);
        if( m != n )   //若m，n相等表示 已经相连接，否则输出此边，将m赋给数组中下标为n的位置
        {
            l++;
            access[n] = m;
            cout<<G[i].left_node<<" "<<G[i].right_node<<endl;
        }
        i++;
    }
}
int main()
{
    int  m,n,k;
    node G[20];//最大边数为20
    cout<<"num of node:";
    cin>>num;
    cout<<"输入边个数:";
    cin>>k;
    cout<<endl<<"输入边及权值:";
    creat_node(G,k);
    quicksort(G,1,k);
    chushi(access);
    cout<<endl;
    print(G,k);
    cout<<endl;
    kruskal(G);
    cout<<endl;
    return 0;
}
