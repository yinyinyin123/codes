#include <iostream>

using namespace std;

bool visited[8];
int dfn[10];
int low[10];
int cont = 1;
bool visi[10][10];
void make(bool visited[])
{
    for(int m=1;m<=7;m++)
        visited[m]=false;
}
void node(int l[][9],int m)
{
    visited[m] = true;
    dfn[m] = cont;
    low[m] = cont;
    cont++;
    for(int i=1 ; i<=7;i++)
    {
        if(l[m][i]==1)
        {
            if(!visited[i])
            {
                node(l , i);
                if(low[i] < low[m])
                    low[m] = low[i];
                if(low[i] >= dfn[m])
                    cout<<i<<" "<<m<<endl;
            }
            else
            {
                if(dfn[i] < low[m])
                    low[m] = dfn[i];
            }
        }
    }
}
int main()
{
    int m,j;
    int l[9][9];
    make(visited);
    for(m = 1;m <= 7;m++)
    {
        for(j = 1 ; j<=7 ;j++)
        {
            cin>>l[m][j];
        }
    }
    node(l,1);
    cout<<endl;
    for(int i=1;i<=7;i++)
        cout<<dfn[i]<<" ";
    cout<<endl;
    for(int i=1;i<=7;i++)
        cout<<low[i]<<" ";

    return 0;
}
