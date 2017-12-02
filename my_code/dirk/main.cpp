#include <iostream>

using namespace std;


bool visited[10];
void chushi(int w[],int d[],int dis[][10],int num) //初始化 第一个点到所有点的距离
{
    for(int i=1 ; i <= num ; i++)
    {
        w[i] = 1;      //路径都初始化为1
        d[i] = dis[1][i];
        visited[i]=false;
    }
}
int mincost(int d[],int num)
{
    int m = 2,k = 2,temp;
    temp = 1000;
    for(int j = 2 ; j <= num ;j++)
    {
        if(d[j] < temp && !visited[j])  //找到当前最小的没有访问过的值
        {
            temp = d[j];
            k = j;
        }
    }
    if(k==2 && visited[2])
        return 0;
    return k;
}
void dirk(int dis[][10] , int d[] ,int way[] , int num)
{
    int w;
    for(int i=2 ; i<=num ; i++ )
    {
        w = mincost(d,num); //找到最小的值对应的点的下标
        if(w==0) //若w为0，说明剩余的节点都无法到达，退出
            break;
        else
        {
            visited[w] = true; //设置为已经走过
            for(int j=2 ; j <= num ; j++) //更新距离数组和路径数组
            {
                if(d[w] + dis[w][j] < d[j] && !visited[j])
                {
                    d[j] = d[w] + dis[w][j];
                    way[j] = w;
                }
            }
        }
    }
}
void print_way_and_distance(int w[] , int d[] ,int num)
{
    int j;
    for(int i=2 ; i <= num ; i++)
    {
        if(d[i]==1000) //1000为俩点之间没有路
            cout<<1<<"to "<<i<<"has no way!"<<endl;
        else
        {
            cout<<1<<"to "<<i<<"has way.";
            cout<<"the distance is"<<d[i];
            cout<<". the way is:";
            j=i;
            while(w[j] != 1)  //递归的寻找路径
            {
                cout<<w[j]<<" ";
                j = w[j];
            }
            cout<<1<<endl;
        }
    }
}
int main()
{
    int distance[10][10];
    int number_of_node;
    int way[10];
    int distanse[10];
    cout<<"number_of_dnode:";
    cin>>number_of_node;
    for(int i=1 ; i <= number_of_node ; i++)
    {
        for(int j=1 ; j<=number_of_node ; j++)
        {
            cin>>distance[i][j];
        }
    }
    chushi(way,distanse,distance,number_of_node);
    dirk(distance , distanse ,way, number_of_node);
    print_way_and_distance(way , distanse , number_of_node );
    return 0;
}
