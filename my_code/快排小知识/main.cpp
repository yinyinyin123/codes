#include <iostream>

using namespace std;

int  buf[10]={54,62,53,12,48,33,42,79,94,30};
int pap(int i,int j)
{
    int low,high,key;
    if(i<j)
    {
        low=i;
        high=j;
        key=buf[low];
        while(low<high)
        {
            while(low<high && buf[high]>key)
                high--;
            buf[low]=buf[high];
            while(low<high && buf[low]<key)
                low++;
            buf[high]=buf[low];
        }
        buf[low]=key;

        return low;
    }
    return i;
}
int find_it(int i,int j)
{
    int a=i,b=j,c;
    for(c=a+1;c<=b;c++)
    {
        if(buf[c]>buf[c-1])
            return c;
        else
            return c-1;
    }
    return -1;
}
int part(int i,int j,int key)
{
    int l,r,t,m=-1;
    do{
        for(l=i;buf[l]<key;l++);
        for(r=j;buf[r]>=key;r--);
        if(l<r)
        {
            t=buf[r];
            buf[r]=buf[l];
            buf[l]=t;
        }
        if(l<r && m==-1)
            m=r;
    }while(l<=r);
    /*if(m!=-1)
    {
        t=buf[m];
        buf[m]=buf[l];
        buf[l]=t;
    }

    cout<<l<<" ";
    for(r=0;r<=9;r++)
        cout<<buf[r]<<"  ";
    cout<<endl;*/
    return l;
}
void paixu(int i,int j)
{
     int key,m,k;


    if(i<j)
    {


      key=buf[i];
      k=part(i,j, key);
      paixu(i,k-1);
      paixu(k+1,j);
    }

}
int search1(int i)
{
    int a=0,b=9,k;
    k=pap(a,b);

    while(k!=i)
    {
        if(k>i)
        {
            k=pap(a,k-1);
        }
        else if(k<i)
        {

            k=pap(k+1,b);
        }
    }
    cout<<buf[k];

}
int main()
{
    int i;
    paixu(0,9);
    for(i=0;i<10;i++)
        cout<<buf[i];
    return 0;
}
