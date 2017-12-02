#include<iostream>
#include<fstream>
#include<stdlib.h>



using namespace std;

typedef struct{
    int  x;
    int  y;
}position;

typedef struct{
    position posi[100];
    int top;
}Stack;

void push(Stack &S , int x , int y)
{
    S.top++;
    S.posi[S.top].x=x;
    S.posi[S.top].y=y;
}
void pop(Stack &S)
{
    S.top--;
}
bool visited[8][8];

void  initialize(int a[8][8])
{
    ifstream in;
    in.open("maze.txt");
    int i,j;
    for(i=0;i<=7;i++)
    {
        for(j=0;j<=7;j++)
            in>>a[i][j];
    }
    in.close();
}

void initialize(bool visited[8][8])
{
    int i,j;
    for(i=0;i<=7;i++)
    {
        for(j=0;j<=7;j++)
            visited[i][j]=false;
    }
    visited[1][1]=true;
}

void find_the_way(int maze[8][8] ,int x , int y , Stack &S)
{
    if(x==6 &&  y==6)
    {
       int i;
       visited[6][6]=false;
       for(i=0;i<=S.top;i++)
       {
           cout<<"("<<S.posi[i].x<<", "<<S.posi[i].y<<")   ";
       }
       cout<<endl;
    }
    else
    {
        if(!visited[x][y+1] && maze[x][y+1]==1)
        {
            push(S , x , y+1);
            visited[x][y+1]=true;
            find_the_way(maze , x , y+1 , S);
            visited[x][y+1]=false;
            pop(S);
        }
        if(!visited[x+1][y] && maze[x+1][y]==1)
        {
            push(S , x+1 , y);
            visited[x+1][y]=true;
            find_the_way(maze , x+1 , y ,S);
            visited[x+1][y]=false;
            pop(S);
        }
        if(!visited[x][y-1] && maze[x][y-1]==1)
        {
            push(S , x , y-1);
            visited[x][y-1]=true;
            find_the_way(maze , x , y-1 ,S);
            visited[x][y-1]=false;
            pop(S);
        }
        if(!visited[x-1][y] && maze[x-1][y]==1)
        {
            push(S , x-1 ,y);
            visited[x-1][y]=true;
            find_the_way(maze , x-1 , y ,S);
            visited[x-1][y]=false;
            pop(S);
        }
    }
}
int main()
{
    int maze[8][8];
    int y;
    Stack S;
    S.top=-1;
    initialize(maze);
    initialize(visited);
    find_the_way(maze,1,1,S);


    return 0;
}
