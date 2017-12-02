#include <iostream>
#include<malloc.h>
#include<fstream>

using namespace std;

typedef struct node{
   int data;
   node *next;
}node;
typedef struct Node{
   int data;
   node *first;
}Node;
void create_graph(Node m[])
{
    int i,y,n;
    node *p,*pr;
    ifstream in;
    in.open("nimei.txt");
    for(i=1;i<=11;i++)
    {
        in>>y>>n;
        p=m[n].first;
        pr=(node *)malloc(sizeof(node));
        pr->data=y;
        pr->next=p->next;
        p->next=pr;
    }
}
void initialize_Node(Node m[])
{
    int i=1;
    for(i=1;i<=10;i++)
    {
        m[i].data=i;
        m[i].first=(node*)malloc(sizeof(node));
        m[i].first->data=i;
        m[i].first->next=NULL;
    }
}
int buf[15];
int iq=-1,oq=-1;
void handle_graph(Node m[],int k)
{
    int i;
    node *p;
    for(i=1;i<=10;i++)
    {
        p=m[i].first;
        while(p->next!=NULL)
        {
            if(p->next->data==k)
            {
                p->next=p->next->next;
            }
            else
              p=p->next;
        }
    }
}
bool visited[15];
void Topologicalsort(Node m[])
{
    int i;
    for(i=1;i<=10;i++)
    {
        if(visited[i] && m[i].first->next==NULL)
        {
            iq++;
            buf[iq]=i;
            visited[i]=false;
        }
    }
    oq++;
    cout<<buf[oq]<<" ";
    if(oq<9)
    {

       handle_graph(m,buf[oq]);
       Topologicalsort(m);
    }
}
void print_graph(Node m[])
{
    int i;
    node *p;
    for(i=1;i<=10;i++)
    {
        p=m[i].first;
        cout<<p->data;
        while(p->next!=NULL)
        {
            p=p->next;
            cout<<"->"<<p->data;
        }
        cout<<endl;
    }
}
void initialize_visited(bool visited[])
{
    int i;
    for(i=1;i<=10;i++)
        visited[i]=true;
}

int main()
{
    Node m[15];
    initialize_Node(m);
    initialize_visited(visited);
    create_graph(m);
    cout<<"µ±Ç°µÄÍ¼"<<endl;
    print_graph(m);
    cout<<"ÍØÆËÅÅÐòÐòÁÐÎª"<<endl;
    Topologicalsort(m);
    cout<<endl;
    cout<<"ÍØÆËÅÅÐòºóµÄÍ¼"<<endl;
    print_graph(m);
}
