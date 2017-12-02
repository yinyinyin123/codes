#include <iostream>
#include<malloc.h>
#include<fstream>

using namespace std;

class graph{

   public:
       void get_the_number_node(int x);
       void get_the_number_edge(int y);
       void creat_the_graph();
       void print_the_graph();
       void chushi(int d[],int j);
       void get_the_node();
       void dijkstra(int d[],int k);
       int mincost(int d[]);
       int minnumber(int d[]);
       void floyd(int d[][10]);
       void juzhen(int m[][10],int d[]);
   private:
       int  number_of_node;
       int  number_of_edge;
       int  a[10][10];
       char node[10];
};

void graph::get_the_node()
{
    int i;
    ifstream in;
    in.open("ni.txt");
    for(i=1;i<=number_of_node;i++)
        in>>node[i];
}
void graph::get_the_number_node(int x)
{
    number_of_node=x;
}
void graph::creat_the_graph()
{
    int i,j;
    ifstream in;
    in.open("ni.txt");
    char p;
    for(i=1;i<=number_of_node;i++)
        in>>p;
    for(i=1;i<=number_of_node;i++)
        for(j=1;j<=number_of_node;j++)
            in>>a[i][j];
}
void graph::get_the_number_edge(int y)
{
    number_of_edge=y;
}
void graph::chushi(int d[],int j)
{
    int i;
    for(i=1;i<=number_of_node;i++)
    {
        d[i]=a[j][i];
     }
}
bool visited[10]={true,true,true,true,true,true,true,true,true,true};
int p[5]={0,0,0,0,0};
int graph::minnumber(int d[])
{
    int i,l=1000,y=0;
    for(i=1;i<=number_of_node;i++)
    {
        if(visited[i]==true && l>d[i])
          {
            l=d[i];
            y=i;
          }
    }
    if(y!=0)
    {
        visited[y]=false;
        return y;
    }
    return 0;
}
void chushi1(bool m[])
{
    int i;
    for(i=0;i<=9;i++)
        m[i]=true;
}
void graph::juzhen(int m[][10],int d[])
{
    int i,j;
    for(i=1;i<=5;i++)
    {
        chushi1(visited);
        chushi(d,i);
        dijkstra(d,i);
        for(j=1;j<=5;j++)
        {
            m[i][j]=d[j];
        }
    }
}
void chushi2(int k)
{
    int i;
    for(i=1;i<=5;i++)
        p[i]=k;
}
void get(int d[],int i,int k)
{
    if(d[i]==k)
        cout<<k<<" ";
    else
    {
        cout<<d[i]<<" ";
        get(d,d[i],k);
    }

}
void graph::dijkstra(int d[],int k)
{
    int i,j,e,f,h;
    chushi2(k);
    for(i=1;i<number_of_node;i++)
    {

        //e=mincost(d);
        f=minnumber(d);
        for(j=1;j<=number_of_node;j++)
        {
            if(d[j]>d[f]+a[f][j])
               {

                 d[j]=d[f]+a[f][j];
                 p[j]=f;
               }
        }
    }
    for(i=1;i<=5;i++)
    {



           cout<<k<<"->"<<i<<"  "<<d[i]<<" ";
           get(p,i,k);
           cout<<endl;

    }
}
void graph::floyd(int d[][10])
{
    int i,j,k;
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            d[i][j]=a[i][j];
    for(k=1;k<=5;k++)
        for(i=1;i<=5;i++)
           for(j=1;j<=5;j++)
              if(d[i][k]+d[k][j]<d[i][j])
                  d[i][j]=d[i][k]+d[k][j];
    cout<<endl;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            if(d[i][j]==1000)
                cout<<0<<" ";
            else
                cout<<1<<" ";
        }
        cout<<endl;
    }
}
void graph::print_the_graph()
{
    int i,j;
    for(i=1;i<=number_of_node;i++)
    {
        for(j=1;j<=number_of_node;j++)
           cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    graph G;
    int d[10][10];
    int l[10];
    int m[10][10];
    G.get_the_number_node(5);
    G.get_the_number_edge(10);
    G.get_the_node();
    G.creat_the_graph();
    G.print_the_graph();
    cout<<"floyd"<<endl;
    G.floyd(d);
    G.chushi(l,1);
    cout<<"dijkstra"<<endl;
    G.dijkstra(l,1);
    cout<<endl;
    G.juzhen(m,l);
    return 0;
}
