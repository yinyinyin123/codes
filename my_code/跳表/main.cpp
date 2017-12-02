#include <iostream>
#include <stdlib.h>
#include<ctime>
#include<malloc.h>

using namespace std;

typedef struct node{
   int key;
   int value;
   typedef struct buf{
      node* arr[100];
   }buf;
   buf B;
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
    p=nimei[k]->B.arr[k];
    pr=nimei[k+1]->B.arr[k+1];
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
            p=p->B.arr[k];
            pr=pr->B.arr[k+1];
        }
    }
}
void make(skip &S,int k)
{
    node *p,*pr,*ptr,*pp;
    p=nimei[k];
    p=p->B.arr[k];
    while(p!=NULL)
    {
       cout<<p->value<<" ";
       if(my_random())
       {
           pr=(node *)malloc(sizeof(node));
           pr->value=p->value;
           pr->key=p->key+1;
           pr->down=p;
           pr->B.arr[pr->key]=NULL;
           ptr=nimei[pr->key];
           while(ptr->B.arr[pr->key]!=NULL)
              ptr=ptr->B.arr[pr->key];
           ptr->B.arr[pr->key]=pr;
       }
       p=p->B.arr[k];
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
        p->B.arr[j]=NULL;
        p->down=NULL;
        p->key=1;
        while(pr->B.arr[j]!=NULL)
            pr=pr->B.arr[j];
        pr->B.arr[j]=p;
        cin>>i;
     }
     while(nimei[S.level]->B.arr[S.level]!=NULL)
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
                pp->B.arr[S.level+1]=NULL;
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
        p=p->B.arr[i];

        while(p!=NULL)
        {
            cout<<p->value<<" ";
            p=p->B.arr[i];
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
        while(p->B.arr[i]!=NULL)
        {
            if(p->B.arr[i]->value==k)
                return p->B.arr[i];
            else if(p->B.arr[i]->value>k)
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
                cout<<p->B.arr[i]->value<<"("<<i<<")";
                p=p->B.arr[i];
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
        pr->B.arr[1]=p->B.arr[1];
        p->B.arr[1]=pr;

    }
    while(my_random())
    {
        i++;
        ptr=nimei[i];
        pp=(node *)malloc(sizeof(node));
        pp->B.arr[i]=NULL;
        pp->value=pr->value;
        pp->key=pr->key+1;
        pp->down=pr;
        while(ptr->B.arr[i]!=NULL)
        {
            if(ptr->B.arr[i]->value>k)
                break;
            ptr=ptr->B.arr[i];
        }
        if(ptr->B.arr[i]==NULL)
        {
             ptr->B.arr[i]=pp;
        }
        else
        {
            pp->B.arr[i]=ptr->B.arr[i];
            ptr->B.arr[i]=pp;
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
    j=p->key;
    cout<<endl;
    for(i=p->key;i>=1;i--)
    {
        pr=nimei[i];
        while(pr->B.arr[i]!=p)
          pr=pr->B.arr[i];
        pr->B.arr[i]=p->B.arr[i];
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
    S.head->B.arr[S.level]=NULL;
    nimei[1]=S.head;
    for(int j=2;j<=99;j++)
    {
        p=(node *)malloc(sizeof(node));
        p->B.arr[j]=NULL;
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
