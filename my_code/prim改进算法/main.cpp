#include <iostream>

using namespace std;
typedef struct node{
    int data;
    int quan;
    node *left,*right,*father;
}node,*Queue;

node* help[100];
int close[20];
int rear;
int num;
bool visited[20];

void intialize(Queue &Q)
{
    rear = 0;
}
void adjust(node *p , int quan , int data)
{
    while(p->father != NULL)
    {
        if(p->father->quan > quan)
        {
            p->quan = p->father->quan;
            p->data = p->father->data;
            p = p->father;
        }
        else
        {
            break;
        }
    }
    p->data = data;
    p->quan = quan;
}
void push(Queue &Q,int data,int quan)
{
    node *p,*pr;
    rear++;
    pr = new node;
    pr->data = data;
    pr->quan = quan;
    pr->left = pr->right = NULL;
    if(rear == 1)
    {
        pr->father = NULL;
        Q = pr;
    }
    else
    {
        p = help[rear/2];
        pr->father = p;
        if(rear%2 == 0)
            p->left = pr;
        else
            p->right = pr;
        adjust(pr , pr->quan , pr->data);
    }
    help[rear] = pr;
}
void creat(int dis[][20])
{
    for(int i=1 ; i<=num ; i++)
    {
        for(int j=1 ; j<=num ; j++)
            cin>>dis[i][j];
    }
}
void print(Queue Q)
{
    if(Q != NULL)
    {
        cout<<Q->quan<<" ";
        print(Q->left);
        print(Q->right);
    }
}
int pop(Queue &Q)
{
    int m,flag=0,temp;
    node *p = help[1];
    m = Q->data;
    if(Q->left==NULL && Q->right==NULL)
    {
        Q = NULL;
        rear--;
        return m;
    }
    while(p->left!=NULL)
    {
        if(p->right == NULL)
        {
           p->quan = p->left->quan;
           p->data = p->left->data;
           rear--;
           p->left = NULL;
           return m;
        }
        else
        {
            if(p->left->quan > p->right->quan)
            {
                flag=1;
                p->quan = p->right->quan;
                p->data = p->right->data;
            }
            else
            {
                p->data = p->left->data;
                p->quan = p->left->quan;
            }
            if(flag == 0)
                p = p->left;
            else
                p = p->right;
        }
    }
    if(p != help[rear])
    {
        p->data = help[rear]->data;
        p->quan = help[rear]->quan;
        if(rear%2==0)
           help[rear/2]->left = NULL;
        else
            help[rear/2]->right = NULL;
        rear--;
        adjust(p, p->quan ,p->data);
    }
    else
    {
        help[rear/2]->right = NULL;
        rear--;
    }
    return m;
}
void intialize_it(Queue &Q,int dis[][20])
{
    for(int i=2 ; i<=num ; i++)
        push(Q,i,dis[1][i]);
}
void intializee(int close[] ,bool visited[])
{

    for(int i=1 ; i<=19 ; i++)
    {
       visited[i] = false;
       close[i] = 1;
    }
    visited[1] = true;
}
void prim(Queue &Q,int dis[][20])
{
    int m,n,i=0;
    while(i <= num-2)
    {
        m = pop(Q); //�����ȶ���
        if(!visited[m])
        {
            cout<<close[m]<<" "<<m<<endl;  //���û�з��ʹ� ������ڽӵĵ�ʹ˵�
            i++;
        }
        visited[m] = true;  //����Ϊ�Ѿ�������
        for(int j=2 ; j<=num ; j++)   //������������ȶ���
        {
            if(!visited[j] && dis[m][j] < dis[1][j])
            {
                push(Q,j,dis[m][j]); //�������ȶ���
                dis[1][j] = dis[m][j];
                close[j] = m;  //�޸�j�ڵ���ڽӵ�
            }
        }
    }
}
int main()
{
    Queue Q;
    intialize(Q);
    int dis[20][20];
    cout<<"input the number of node:"; //����ڵ�
    cin>>num;
    cout<<endl;
    creat(dis);  //�����������
    intializee(close,visited); //��ʼ��
    intialize_it(Q,dis);  //��ʼ��������
    prim(Q,dis); //����prim�㷨
    return 0;
}
