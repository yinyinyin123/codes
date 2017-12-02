#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

void insertsort(int buf[] , int m)
{
    int k;
    for(int i = 1; i <= m ; i++)
    {
        for(int j = i ; j >= 1 ; j--)
        {
            if(buf [j] > buf[j-1])
            {
                k=buf[j];
                buf[j]=buf[j-1];
                buf[j-1]=k;
            }
            else
            {
                break;
            }
        }
    }

}
void bubblesort(int buf[],int k)
{
    int m;
    for(int i=0;i <= k ; i++)
    {
        for(int j=0 ; j <= k-i-1 ; j++)
        {
            if(buf[j] < buf[j+1])
            {
                m=buf[j];
                buf[j]=buf[j+1];
                buf[j+1]=m;
            }

        }
    }
}
void selectsort(int buf[] , int a)
{
    int k,m,p;
    for(int i=0 ; i <= a-1; i++)
    {
        k = buf[i];
        m = i;
        for(int j = i+1; j <= a-1 ;j++ )
        {
            if(k < buf[j] )
            {
                k = buf[j];
                m = j;
            }
        }
        if(m != i)
        {
            p = buf[m];
            buf[m] = buf[i];
            buf[i] = p;
        }
    }
}
void quicksort(int buf[] , int i , int  j)
{
    int key,left,right;
    if(i<j)
    {
        left = i;
        right = j;
        key = buf[i];
        while(left < right)
        {
            while(left < right && buf[right] >= key)
                right--;
            buf[left] = buf[right];
            while(left < right && buf[left] < key)
                left++;
            buf[right] = buf[left];
        }
        buf[left] = key ;
       // for(int c = i;c<=j;c++)
       // {
      //      cout<<buf[c]<<" ";
      //  }
       // cout<<endl;
        quicksort(buf , i , left-1);
        quicksort(buf , left+1 ,j);
    }
}
void heapsort(int buf[])
{
    int m;
    for(int k = 15;k >= 2 ; k--)
    {
        for(int i = k; i >= 2; i--)
        {
            for(int j = i ; j >= 1 ; j = j/2)
            {
                if(buf[j] < buf[j/2] && j != 1)
                {
                    m = buf[j];
                    buf[j] = buf[j/2];
                    buf[j/2] = m;
                }
            }
        }
        m = buf[k];
        buf[k] = buf[1];
        buf[1] = m;
    }
}
int main()
{
    int buf[200000];
    long x,y;
    srand( (unsigned)time( NULL ) );
     for(int i=0;i<=100000;i++)
        buf[i] = rand()%200000;
    //insertsort(buf,14);
    x = clock();
    quicksort(buf,0,100000);
    y = clock();
    //selectsort(buf,14);

    //quicksort(buf,0,1000);

    //heapsort(buf);
    for(int i=0;i<=1000;i++)
    {
        cout<<buf[i]<<"  ";
    }
    cout<<endl<<y-x<<endl;
    return 0;
}
