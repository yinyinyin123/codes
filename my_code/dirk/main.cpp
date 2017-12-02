#include <iostream>

using namespace std;


bool visited[10];
void chushi(int w[],int d[],int dis[][10],int num) //��ʼ�� ��һ���㵽���е�ľ���
{
    for(int i=1 ; i <= num ; i++)
    {
        w[i] = 1;      //·������ʼ��Ϊ1
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
        if(d[j] < temp && !visited[j])  //�ҵ���ǰ��С��û�з��ʹ���ֵ
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
        w = mincost(d,num); //�ҵ���С��ֵ��Ӧ�ĵ���±�
        if(w==0) //��wΪ0��˵��ʣ��Ľڵ㶼�޷�����˳�
            break;
        else
        {
            visited[w] = true; //����Ϊ�Ѿ��߹�
            for(int j=2 ; j <= num ; j++) //���¾��������·������
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
        if(d[i]==1000) //1000Ϊ����֮��û��·
            cout<<1<<"to "<<i<<"has no way!"<<endl;
        else
        {
            cout<<1<<"to "<<i<<"has way.";
            cout<<"the distance is"<<d[i];
            cout<<". the way is:";
            j=i;
            while(w[j] != 1)  //�ݹ��Ѱ��·��
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
