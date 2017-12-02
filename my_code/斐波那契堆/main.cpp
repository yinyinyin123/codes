#include <iostream>

using namespace std;

typedef struct node{
    int quan;
    int degree;
    int mark;
    node *child,*lb,*rb,*father;
}node;
typedef struct fibo{
    node *min_node;
    int num;   //堆中树的个数
    int n; //记录最小节点的下标
    node* t[20];//存储树的根
}fibo;
node* a[20];
void chushi(node* a[])
{
    for(int i=0 ; i<=19 ; i++)
        a[i] = NULL;
}
void insert_it(fibo &F , int data)
{
     node *pr;
     pr = new node;
     pr->quan = data;
     pr->degree = 0;
     pr->child = pr->father = pr->lb = pr->rb = NULL;
     pr->mark = 0;
     if(F.min_node == NULL)
     {
         F.min_node = pr;
         F.n = 1;
     }
     else
     {
         node *p = F.min_node;
         while(p->rb != NULL)
            p = p->rb;
         p->rb = pr;
         pr->lb = p;
     }
     F.num++;
     F.t[F.num] = pr;
     if(data  < F.min_node->quan )
     {
         F.min_node = pr;
         F.n = F.num;
     }
}
void print_it(node *p)
{
    if(p != NULL)
    {
        cout<<p->quan<<" ";
        print_it(p->rb);
        print_it(p->child);
    }
}
void print(fibo F)
{
    node *p = F.t[1];
    print_it(p);

}
int pp;
void make(fibo &F , node *p)
{
    int i,j,m;
    for(i=1 ; i<= F.num ;i++)
    {
        if(F.t[i] == p)
        {
            m=i;
            break;
        }
    }
    for(int j=m ; j < F.num ;j++ )
        F.t[j] = F.t[j+1];
    F.num--;
}
void make_one(fibo &F,node *p)
{
    if(p->lb != NULL)
    {
        p->lb->rb = p->rb;
        if(p->rb!=NULL)
           p->rb->lb = p->lb;
    }
    else
    {
        if(p->rb != NULL)
           p->rb->lb = NULL;
    }
}
int find_it(fibo &F,node *p)
{
    for(int i=1;i<=F.num;i++)
    {
        if(F.t[i] == p)
            return i;
    }
}
int make_two(fibo &F,int i)
{
    node *p,*pr;
    int m;
    if(a[F.t[i]->degree])
    {
        p = F.t[i];
        pr = a[F.t[i]->degree];
        if(pr->quan > p->quan)
        {
            make_one(F,pr);
            make(F,pr);
            a[p->degree]=NULL;
            if(p->child != NULL)
            {
                pr->rb = p->child->rb;
                if(p->child->rb!=NULL)
                   p->child->rb->lb = pr;
                p->child->rb = pr;
                pr->lb = p->child;
                pr->father = p;
            }
            else
            {
                p->child = pr;
                pr->father = p;
                pr->rb = pr->lb = NULL;
            }
            p->degree++;
            if(a[p->degree]==NULL)
               a[p->degree] = p;
            else
            {
                pp--;
                make_two(F,pp);
            }
        }
        else
        {
            make_one(F,p);
            make(F,p);
            a[p->degree] = NULL;
            if(pr->child !=NULL)
            {
                p->rb = pr->child->rb;
                if(pr->child->rb!=NULL)
                   pr->child->rb->lb = p;
                pr->child->rb = p;
                p->lb = pr->child;
                p->father = pr;
            }
            else
            {
                pr->child = p;
                p->father = pr;
                p->rb = p->lb = NULL;
            }
            pr->degree++;
            if(a[pr->degree]==NULL)
               a[pr->degree] = pr;
            else
            {
                pp--;
                m = find_it(F , pr);
                make_two(F,m);
            }
        }
    }
    else
    {
        a[F.t[i]->degree] = F.t[i];
        pp++;
    }
    return pp;
}
void make_together(fibo &F)
{
    node *p,*pr;
    int i=1;
    while(i <= F.num)
    {
        pp = i;
        i = make_two(F,i);
    }
}
void reget_the_min_node(fibo &F)
{
    int temp=100, j;
    for(int i=1;i<=F.num;i++)
    {
        if(F.t[i]->quan < temp)
        {
            temp = F.t[i]->quan;
            j = i;
        }
    }
    F.min_node = F.t[j];
    F.n = j;
}

void delet(fibo &F)
{
    node *p = F.min_node;
    node *pr = p->rb;
    int num,s;
    if(p->lb != NULL)
    {
        p->lb->rb = p->rb;
        if(p->rb!=NULL)
           p->rb->lb = p->lb;
    }
    else
    {
        if(p->rb != NULL)
        {
           p->rb->lb = NULL;
        }
    }
    for(int i = F.n ; i < F.num ; i++)
        F.t[i] = F.t[i+1];
    F.num--;
    num = p->degree;
    p = p->child;
    for(int j=1 ; j<=num ; j++)
    {
        F.num++;
        F.t[F.num] = p;
        p = p->rb;
    }
    make_together(F);
    reget_the_min_node(F);
}
int main()
{
    fibo  F;
    int m;
    F.num = 0;
    F.min_node = NULL;
    chushi(a);
    for(int i = 1 ; i <= 19 ; i++)
        F.t[i] = NULL ;
    cin>>m;
    while(m != 0)
    {
        insert_it(F , m);
        cin>>m;
    }
    delet(F);
    chushi(a);
    print(F);
    cout<<endl;
    delet(F);
    print(F);
    return 0;
}
