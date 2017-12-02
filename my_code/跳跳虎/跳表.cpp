#include <iostream>
#include <stdlib.h>
#include<ctime>
#include<malloc.h>

using namespace std;

typedef struct node{
   int key;
   int value;
   node *next;
   node *down;
}node;
typedef struct skip{
   int level;
   node *head;
}skip;
node *nimei[100];
int my_random()
{
    int i=0;
    if(rand()%2)
        i++;
    cout<<i<<" number"<<endl;
    return i;

}
bool same(skip S,int k)
{
    node *p,*pr;
    p=nimei[k]->next;
    pr=nimei[k+1]->next;
    while(true)
    {
        if(pr==NULL && p==NULL)
            return true;
        else if(pr==NULL && p!=NULL)
            return false;
        else if(pr!=NULL && p==NULL)
            return false;
        else
        {
            if(pr->value!=p->value)
                return false;
            p=p->next;
            pr=pr->next;
        }
    }
}
void make(skip &S,int k)
{
    node *p,*pr,*ptr,*pp;
    p=nimei[k];
    p=p->next;
    while(p!=NULL)
    {
       cout<<p->value<<" ";
       if(my_random())
       {
           pr=(node *)malloc(sizeof(node));
           pr->value=p->value;
           pr->key=p->key+1;
           pr->down=p;
           pr->next=NULL;
           ptr=nimei[pr->key];
           while(ptr->next!=NULL)
              ptr=ptr->next;
           ptr->next=pr;
       }
       p=p->next;
    }
}
void creat(skip &S)
{
    int i,j=1, z=0;
    cin>>i;
    node *p,*pr,*ptr,*pp;
    while(i!=0)
    {
        pr=nimei[j];
        p=(node*)malloc(sizeof(node));
        p->value=i;
        p->next=NULL;
        p->down=NULL;
        p->key=1;
        while(pr->next!=NULL)
            pr=pr->next;
        pr->next=p;
        cin>>i;
     }
     while(nimei[S.level]->next!=NULL)
     {
            make(S,S.level);
            if(!same(S,S.level))
            {
                cout<<S.level<<endl;
                S.level++;
            }
            else
            {
                pp=nimei[S.level+1];
                pp->next=NULL;
            }
     }
}
void print(skip S)
{

    node *p,*pr,*pre,*pp;
    for(int i=S.level;i>=1;i--)
    {
        p=nimei[i];
        cout<<p->value<<" ";
        p=p->next;

        while(p!=NULL)
        {
            cout<<p->value<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
node* find(skip S,int k)
{
    int i;
    node *p;
    i=S.level;
    cout<<"S.level:"<<i<<" "<<endl;
    p=nimei[i];
    while(true)
    {
        cout<<p->value<<"("<<i<<")";
        while(p->next!=NULL)
        {
            if(p->next->value==k)
                return p->next;
            else if(p->next->value>k)
            {
                if(i!=1)
                {
                  p=p->down;
                  i--;
                  cout<<p->value<<"("<<i<<")";
                }
                else
                    return p;
            }
            else
            {
                cout<<p->next->value<<"("<<i<<")";
                p=p->next;
            }
        }
        if(i==1)
        {
            cout<<p->value<<" ";
            return p;
        }
        else
        {

            //if(p->B.arr[i]!=NULL)
              //  cout<<p->value<<"("<<i<<")";
            p=p->down;
            i--;
        }
    }


}
void add(skip &S,int k)
{
    node *p,*pr,*ptr,*pp;
    int i=1;
    p=find(S,k);
    if(p->value==k)
        cout<<"the data has existed";
    else
    {
        pr=(node *)malloc(sizeof(node));
        pr->key=1;
        pr->down=NULL;
        pr->value=k;
        pr->next=p->next;
        p->next=pr;

    }
    while(my_random())
    {
        i++;
        ptr=nimei[i];
        pp=(node *)malloc(sizeof(node));
        pp->next=NULL;
        pp->value=pr->value;
        pp->key=pr->key+1;
        pp->down=pr;
        while(ptr->next!=NULL)
        {
            if(ptr->next->value>k)
                break;
            ptr=ptr->next;
        }
        if(ptr->next==NULL)
        {
             ptr->next=pp;
        }
        else
        {
            pp->next=ptr->next;
            ptr->next=pp;
        }
        pr=pp;

    }
    print(S);


}
void delet(skip &S,int k)
{
    node *p,*pr,*ptr;
    int i,j;
    p=find(S,k);
    if(p->value!=k)
        cout<<"no this data";
    j=p->key;
    cout<<endl;
    for(i=p->key;i>=1;i--)
    {
        pr=nimei[i];
        while(pr->next!=p)
          pr=pr->next;
        pr->next=p->next;
        p=p->down;
        if(i==j)
        {
            if(same(S,i))
            {
                for(int h=j+1;j<=S.level-1;j++)
                {
                    nimei[h]=nimei[h+1];
                }
                S.level--;
            }
        }
    }
    print(S);
}
int main()
{
    srand((unsigned)time(0));
    skip S;
    node *p,*pr;
    int i;
    S.level = 1;
    S.head = (node *)malloc(sizeof(node));
    S.head->value=-1;
    S.head->down=NULL;
    S.head->next=NULL;
    nimei[1]=S.head;
    for(int j=2;j<=99;j++)
    {
        p=(node *)malloc(sizeof(node));
        p->next=NULL;
        p->value=-1;
        p->down=S.head;
        S.head=p;
        nimei[j]=p;
    }
    creat(S);
    cout<<endl;
    print(S);
    cout<<"find the data:";
    cin>>i;
    pr=find(S,i);
    if(pr->value==i)
        cout<<endl<<"find it";
    else
        cout<<endl<<"no this data:"<<endl;
    cout<<"add the data:";
    cin>>i;
    add(S,i);
    cout<<endl;
    cout<<"delete the data:";
    cin>>i;
    cout<<endl;
    delet(S,i);
    return 0;
}
