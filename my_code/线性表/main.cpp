#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct node{
   char data;
   node *next;
}node;

node *creat(node *head)
{
    node *p,*pr;
    char data;
    cin>>data;
    while(data!='#')
    {
        p=head;
        if(head==NULL)
        {
            head=(node *)malloc(sizeof(node));
            head->data=data;
            head->next=NULL;
        }
        else
        {
            pr=(node *)malloc(sizeof(node));
            pr->data=data;
            pr->next=NULL;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=pr;

        }
        cin>>data;
    }
    return head;

}
void print(node *head)
{
    node *p;
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
node *first(node *head)
{
    return head;
}
node *last(node *head)
{
    node *p;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}
node *delet(node *head,node *p)
{
    node *pr,*ptr;
    pr=head;
    if(p==head)
    {
        return p->next;
    }
    else
    {
        while(pr->next!=p)
        {
            pr=pr->next;
        }
        ptr=p;
        pr->next=p->next;
        free(ptr);
    }
    return head;
}
node *pre(node *head,node *pr)
{
    node *p;
    p=head;
    if(pr==head)
    {
        cout<<"this is the first element,no pre node"<<endl;
        return NULL;
    }
    while(p->next!=pr)
    {
        p=p->next;
    }
    return p;
}
node *after(node *p)
{
    if(p->next==NULL)
    {
        cout<<"this is the last element,no after node"<<endl;
        return NULL;
    }
    return p->next;
}
int main()
{
    node *head;
    head=NULL;
    head=creat(head);
    print(head);
    head=delet(head,head->next->next);
    print(head);
    cout<<first(head)->data<<" ";
    cout<<last(head)->data;
    pre(head,head);
    after(last(head));

}
