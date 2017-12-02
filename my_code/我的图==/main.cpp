#include <iostream>
#include <fstream>
#include <malloc.h>


using namespace std;

typedef struct Queue{
   int a[20];
   int front,rear;
}Queue;
typedef struct node{
   int  data;
   node *next;
}node;

typedef struct dot{
   node *first;
   char data;
}dot;
typedef struct graph{
   dot D[20];
   int number;
}graph;

void inque(Queue &Q,int k)
{
    Q.front++;
    Q.a[Q.front]=k;
}
int outque(Queue &Q)
{
    Q.rear++;
    return Q.a[Q.rear];
}
bool empty(Queue Q)
{
    if(Q.rear==Q.front)
        return true;
    return false;
}
bool visited[20];
void make(graph &gg,Queue &Q,int k)
{
    node *p,*pr;
    for(int i=1;i<=gg.number;i++)
    {
        if(!visited[i])
        {
            p=gg.D[i].first;
            pr=p->next;
            while(pr!=NULL)
            {
                if(pr->data==k)
                {
                    p->next=pr->next;
                    gg.D[i].first->data--;
                    break;
                }
                p=pr;
                pr=pr->next;
            }

            if(gg.D[i].first->data==0)
            {
                visited[i]=true;
                inque(Q,i);
            }
        }
    }
}
void print_edge(graph gg)
{
    node *p;
    for(int i=1;i<=gg.number;i++)
    {
        p=gg.D[i].first->next;
        cout<<i<<": ";
        while(p!=NULL)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
        cout<<endl;
    }
}
void tuopu(graph gg,Queue Q)
{
    int j;
    for(int i=1;i<=gg.number;i++)
    {
        if(gg.D[i].first->data==0)
        {
            visited[i]=true;
            inque(Q,i);
        }
    }
    while(!empty(Q))
    {
        j=outque(Q);
        cout<<j<<" ";
        make(gg,Q,j);
    }
}
void creat(graph &gg)
{
    ifstream in;
    int num,dot_one,dot_two;
    in.open("nimei.txt");
    in>>gg.number>>num;
    for(int i=1;i<=gg.number;i++)
    {
        in>>gg.D[i].data;
        gg.D[i].first=(node*)malloc(sizeof(node));
        gg.D[i].first->next=NULL;
        gg.D[i].first->data=0;
    }
    for(int j=1;j<=num;j++)
    {
        in>>dot_two>>dot_one;
        node *p,*pr;
        gg.D[dot_one].first->data++;
        p=gg.D[dot_one].first;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        pr=(node*)malloc(sizeof(node));
        pr->data=dot_two;
        pr->next=NULL;
        p->next=pr;
    }
}

void intialize(bool visited[])
{
    for(int i=1;i<=18;i++)
        visited[i]=false;
}
void DFXS(graph &gg,int k)
{
    node *p;
    p=gg.D[k].first->next;
    cout<<k<<" ";
    visited[k]=true;
    while(p!=NULL)
    {
        if(!visited[p->data])
            DFXS(gg,p->data);
        p=p->next;
    }
}
void DFX(graph gg)
{
    for(int i=1;i<=gg.number;i++)
    {
        if(!visited[i])
        {
            DFXS(gg,i);
        }
    }
}
int main()
{
    Queue Q;
    Q.front=-1;
    Q.rear=-1;
    graph gg;
    creat(gg);
    intialize(visited);
    tuopu(gg,Q);
    cout<<endl;
    creat(gg);
    intialize(visited);
    DFX(gg);
    return 0;


}
