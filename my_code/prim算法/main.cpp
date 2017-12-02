#include <iostream>

using namespace std;

int close[10];
void chushi(int l[] , int d[][10],int num)
{
        for(int i=1 ; i <= num ; i++)
        {
            l[i]=d[1][i];
        }
}
void prim(int l[],int d[][10],int num)
{
    int min,j,k;
    for(int i=1;i<=9;i++)
        close[i]=1;     //初始化为1
    for(int i=2 ; i <= num ; i++ )
    {
        min=l[i];
        k=i;
        for(j=2 ; j <= num ; j++)
        {
            if(l[j]<min)
            {
                min=l[j];     // 找到现在数组中的最小的元素
                k=j;
            }
        }
        cout<<"("<<k<<","<<close[k]<<")"<<" "; //输出这条最小边的俩个顶点
        l[k]=2000;  //设置为已经走过
        for(j=2;j<=num;j++)
        {
            if(d[k][j] < l[j] && l[j] != 2000) //更新数组如果选中的节点到其他节点的距离小于当前数组中对应位置的数，更新数组并修改路径
            {
                l[j]=d[k][j];
                close[j]=k;
            }
        }
        for(int c=1;c<=num;c++)
            cout<<l[c]<<" ";
        cout<<endl;
    }
}
int main()
{
    int distance[10][10];
    int lowcost[10];
    int num;
    cout<<"input the number of node:";
    cin>>num;
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= num ; j++)
           cin>>distance[i][j];
    }
    chushi(lowcost , distance , num);
    prim(lowcost,distance,num);
    return 0;
}
