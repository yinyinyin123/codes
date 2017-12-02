#include <iostream>

using namespace std;

typedef struct node{
   int val;
   int addmark;
}node;

node SegTree[1000];
void build_segtree(int root,int arr[],int left,int right);//�����±꣬���飬������ߵĽ磬�ұߵĽ�
void pushdown(int root,int k);//�����±�
int find_the_min_from_x_to_y(int fstart,int fend,int left,int right,int root);//��ҪѰ�ҵ���߽�,�ұ߽磬������߽磬�ұ߽�
int update(int root,int fstart,int fend,int left,int right,int addnum);//������߽磬�ұ߽磬��Ҫ�Ӷ�ֵ����߽磬�ұ߽磬�ӵĶ�ֵ
int change_the_num(int root,int fstart,int fend,int index,int change);//root=1���������߽磬�ұ߽磬��Ҫ�޸ĵ�����λ�ã��ĺ��ֵ



void build_segtree(int root , int arr[] , int left , int right)
{
    SegTree[root].addmark = 0;
    if(left == right)
        SegTree[root].val = arr[left];
    else
    {
        int mid = (left + right)/2;
        build_segtree(2*root  , arr , left , mid);
        build_segtree(2*root+1, arr , mid+1, right);
        if(SegTree[2*root].val > SegTree[2*root+1].val)
            SegTree[root].val = SegTree[2*root+1].val;
        else
            SegTree[root].val = SegTree[2*root].val;
    }
}


void pushdown(int root,int k)
{
    if(SegTree[root].addmark != 0)
    {
        SegTree[2*root].val += k;
        SegTree[2*root+1].val+=k;
        SegTree[2*root].addmark = k;
        SegTree[2*root+1].addmark = k;
    }
    SegTree[root].addmark = 0;
}


int find_the_min_from_x_to_y(int fstart , int fend , int left , int right ,int root)
{
    int num,m,n,mid;
    mid = (left+right)/2;
    if(left > fend || fstart > right)
    {
        num = 1000;
    }
    else
    {
        if(left >= fstart && right <= fend)
        {
            num = SegTree[root].val;
            return num;
        }
        pushdown(root,SegTree[root].addmark);
        m = find_the_min_from_x_to_y(fstart , fend , left , mid   ,2*root  );
        n = find_the_min_from_x_to_y(fstart , fend , mid+1, right ,2*root+1);
        if(m > n)
            num = n;
        else
            num = m;
    }
    return num;
}


int change_the_num(int root , int fstart ,int fend ,int index ,int change)
{
    if(fstart == fend)
    {
        SegTree[root].val = change;
        return 0;
    }
    else
    {
        int mid = (fstart + fend)/2;
        if(mid >= index)
            change_the_num(root*2 , fstart , mid ,index ,change);
        else
            change_the_num(root*2+1 , mid+1 , fend ,index ,change);
    }
    if(SegTree[root*2].val > SegTree[root*2+1].val)
        SegTree[root].val = SegTree[root*2+1].val;
    else
        SegTree[root].val = SegTree[root*2].val;
}


int update(int root,int fstart , int fend , int left , int right , int addnum)
{
    int m,n;
    if(left > fend || fstart > right)
        return 0;
    if(fstart >= left && fend <= right)
    {
        SegTree[root].val += addnum;
        SegTree[root].addmark = addnum;
        return 0;
    }
    else
    {
        int mid = (fstart+fend)/2;
        update(root*2 , fstart , mid , left , right , addnum);
        update(root*2+1, mid+1 , fend, left , right , addnum);
    }
    if(SegTree[root*2].val > SegTree[root*2+1].val)
        SegTree[root].val = SegTree[root*2+1].val;
    else
        SegTree[root].val = SegTree[root*2].val;

}


void print()
{
    for(int i=1 ; i<30;i++)
        cout<<SegTree[i].val<<" ";
    cout<<endl;
}


int main()
{
    int arr[] = {0,2,5,1,4,9,3};
    int length = sizeof(arr)/sizeof(int);
    build_segtree(1 , arr , 1 , length-1);
    return 0;
}
