#include <iostream>

using namespace std;

int way[15][15];
void chushi(int way[][15])
{
    for(int i=1;i<=14;i++)
    {
        for(int j=1;j<=14;j++)
        {
            way[i][j] = i;
        }
    }
}
void creat_node(char node[],int num)
{
    for(int i=1;i<=num;i++)
        cin>>node[i];
}
void creat_distance(int distance[][15],int num)
{
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            cin>>distance[i][j];
        }
    }
}
void floyd(int distance[][15] , int num)
{
    for(int k=1;k<=num;k++)
    {
        for(int i=1;i<=num;i++)
        {
            for(int j=1;j<=num;j++)
            {
                if(distance[i][j] > distance[i][k]+distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    way[i][j] = k;
                }
            }
        }
    }
}
void print(int distance[][15],char node[],int num)
{
    int m,n;
    for(int i=1;i<=num;i++)
    {
        n = i;
        for(int j=1;j<=num;j++)
        {
            if(i!=j)
            {
                m = j;
                cout<<i<<"->"<<j<<"="<<distance[i][j]<<"  way:";
                if(distance[i][j] != 1000)
                {
                    cout<<i<<" ";
                    while(way[n][m] != n)
                    {
                        cout<<way[n][m]<<" ";
                        n = way[n][m];
                    }
                    cout<<j<<endl;
                }
                else
                {
                    cout<<"there is no way"<<endl;
                }
                n = i;
            }
        }
    }


}
int main()
{
    int distance[15][15];
    char node[15];
    int num; // num表示顶点个数
    chushi(way);
    cout<<"input the number of node:";
    cin>>num;
    cout<<endl;
    cout<<"input the node:";
    creat_node(node,num);
    cout<<endl;
    cout<<"input the distance:";
    creat_distance(distance,num);
    floyd(distance,num);
    print(distance,node,num);
    return 0;
}
