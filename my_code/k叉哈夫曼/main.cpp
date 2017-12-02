#include <iostream>
#include <fstream>

using namespace std;

typedef struct dat{
   char data;
   int quan;
   int  father_of_son;
}dat;
typedef struct stack{
    int top;
    int a[10];
}stack;
stack Q;
dat d[200];
int front=0,rear=0;
dat help[100];
void chushi(stack &Q)
{
    Q.top=-1;
}
void push(stack &Q,int k)
{
    Q.top++;
    Q.a[Q.top]=k;
}
void print(stack Q)
{
    for(int i=Q.top ; i>=0;i--)
        cout<<Q.a[i];
}
void chushi(int d[])
{
    for(int i = 0 ; i <= 139 ; i++)
        d[i] = 0;
}
void make(int quan[],dat d[],int num)
{
    char m;
    int j=0;
    for(int i=1 ; i <= 139 ; i++)
    {
        if(quan[i]!=0)
        {
            j++;
            m = i;
            d[j].data = m;
            d[j].quan = quan[i];
        }
    }
    for(int i = 1 ; i <= num ; i++)
    {
        j++;
        d[j].data='#';
        d[j].quan=0;
    }
}
void my_sort(dat d[],int num)
{
    int k,j,p;
    char m;
    for(int i=1 ; i < num ; i++)
    {
        j = i;
        p = d[i].quan;
        for(int u = i ; u <= num ; u++)
        {
            if(p > d[u].quan )
            {
                p = d[u].quan;
                j = u;
            }
        }
        if(j != i)
        {
            p = d[i].quan;
            d[i].quan = d[j].quan;
            d[j].quan = p;
            m = d[i].data;
            d[i].data = d[j].data;
            d[j].data = m;
        }
    }
}
void remake(int quan[],dat d[],int num)
{
    int n;
    for(int i=1;i<=num;i++)
    {
        if(d[i].data!='#')
        {
            n = d[i].data;
            quan[n] = i;
        }
    }
}
int find_the_min(dat d[],int &num,int n,int p)
{
    int m;
    if(front==rear)
    {
        num++;
        m = d[num-1].quan;
        d[num-1].father_of_son = p;
        d[num-1].quan = rear;
        return m;
    }
    else
    {
        if(num > n)
        {
            front++;
            m = help[front-1].quan;
            help[front-1].father_of_son =  p;
            help[front-1].quan = rear;
            return m;
        }
        else
        {
            if(d[num].quan < help[front].quan)
            {
                num++;
                m = d[num-1].quan;
                d[num-1].father_of_son = p;
                d[num-1].quan = rear;
                return m;
            }
            else
            {
                front++;
                m = help[front-1].quan;
                help[front-1].father_of_son =  p;
                help[front-1].quan = rear;
                return m;
            }
        }
    }
}
void creat_the_tree(dat d[],int num)
{
    int p = 1,y,o;
    while(rear - front != 1 || p <= num)
    {
        y = 0;
        for(int i=1;i<=5;i++)
        {
            o=find_the_min(d,p,num,i);
            y+=o;
        }
        help[rear].quan = y;
        rear++;
    }
}
void bianma(int quan[],char data[],dat d[],int num)
{
    int m;chushi(Q);
    for(int i=1;i<=num;i++)
    {
        m = data[i];
        m = quan[m];
        push(Q , d[m].father_of_son);
        m = d[m].quan;
        while(help[m].quan != 76)
        {
            push(Q , help[m].father_of_son);
            m = help[m].quan;
        }
        print(Q);
        chushi(Q);
    }
}
int main()
{
    char temp;
    int i = 0;
    int k = 5; //5²æ
    int m , l=0, add = 0,a;
    int j;
    char data[2000];
    int quan[140];
    ifstream in;
    chushi(quan);
    in.open("nimei.txt");
    in>>temp;
    while(temp!='#')
    {
        i++;
        data[i] = temp;
        m = temp;
        if(quan[m]==0)
            l++;
        quan[m]++;
        in>>temp;
    }
    j = 'i';
    cout<<j<<" "<<quan[j];
    cout<<endl;
    cout<<l<<" "<<i<<endl;
    a = (l-1)%(k-1);
    if(a != 0)
        add = k-1-a;
    make(quan , d ,add);
    cout<<endl;
    cout<<"ÅÅÐò:"<<endl;
    l+=add;
    my_sort(d,l);
    for(int i=1 ; i<=l;i++)
        cout<<d[i].quan<<" "<<d[i].data<<endl;
    remake(quan,d,l);
    cout<<endl;
    creat_the_tree(d,l);
    bianma(quan,data,d,i);
    return 0;
}
