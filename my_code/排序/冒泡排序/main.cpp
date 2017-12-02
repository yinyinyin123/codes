#include <iostream>

using namespace std;


void paopao(int d[],int i)
{
    int a,b,c;
    for(a=0;a<=i;a++)
    {
        for(b=0;b<i-a;b++)
        {
            if(d[b]<d[b+1])
            {
                c=d[b];
                d[b]=d[b+1];
                d[b+1]=c;
            }
        }
    }
}
int main()
{
    int i;
    int buff[10]={100,43,1,201,34,12,56,13,57,20};
    paopao(buff,9);
    for(i=0;i<=9;i++)
        cout<<buff[i]<<" ";
}
