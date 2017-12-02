#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <ctime>

using namespace std;

typedef struct node{
    int data;
    int key;
    int value;
    node *down;
    node *next[0];
}node,*Node;

typedef struct skip{
   Node head[10];
   int  level;
}skip;

int my_random()
{
    int i=0;
    if(rand()%2)
        i++;
    cout<<i<<" number"<<endl;
    return i;

}

void chushi(skip &S)
{
    S.level=1;
    node *p,*pr=NULL;
    for(int i=1 ;i<=9 ;i++)
    {
        p=(node *)malloc(sizeof(node)+1*sizeof(node));
        p->key=i;
        p->data=-1;
        p->next[1]=NULL;
        if(pr==NULL)
            p->down=NULL;
        else
            p->down=pr;
        S.head[i]=p;
        pr=p;
    }


}
void creat(skip &S)
{
    int data,high;
    cin>>data;
    node *p,*pr,*ptr;
    while(data != 0)
    {
        high=1;
        while(my_random())
            high++;
        if(high>S.level)
            S.level=high;
        p=(node *)malloc(sizeof(node)+high*sizeof(node));
        p->key=high;
        p->down=NULL;
        p->data=data;
        for(int j=1 ; j<=high ; j++)
        {
            pr=S.head[j];
            if(pr->next[1]==NULL)
            {
                pr->next[1]=p;
                p->next[j]=NULL;
            }
            else
            {
                pr=pr->next[1];
                while(pr->next[j] != NULL)
                    pr=pr->next[j];
                pr->next[j]=p;
                p->next[j]=NULL;
            }
        }
        cin>>data;
    }
}
void print(skip S)
{
    node *p;
    for(int i=S.level ;i>=1 ;i--)
    {
        p=S.head[i]->next[1];
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next[i];
        }
        cout<<endl;
    }
}
int main()
{
    srand((unsigned)time(0));
    skip S;
    chushi(S);
    creat(S);
    print(S);
}
