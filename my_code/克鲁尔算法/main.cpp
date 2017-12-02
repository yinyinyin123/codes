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
void quicksort(node G[],int i,int j) //���Ž��ڵ����鰴Ȩֵ�Ӵ�С����
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
int the_number(int k)  //���鼯
{
    while(access[k]!=k) //���±��������Ӧ��ֵ��� ���أ����������Ӧ��ֵ����k���ڽ��еݹ�
        k=access[k];
    return k;
}
void kruskal(node G[])
{
    int l=1,m,n,i=1; //  lΪ����ı�����iΪ�����±�
    while(l <= num-1)
    {
        m = the_number(G[i].left_node); //���ò��鼯
        n = the_number(G[i].right_node);
        if( m != n )   //��m��n��ȱ�ʾ �Ѿ������ӣ���������˱ߣ���m�����������±�Ϊn��λ��
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
    node G[20];//������Ϊ20
    cout<<"num of node:";
    cin>>num;
    cout<<"����߸���:";
    cin>>k;
    cout<<endl<<"����߼�Ȩֵ:";
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
