#include <iostream>

using namespace std;
int B[20]; //辅助数组

void mersort(int i,int j,int A[])
{

    int u = i;
    int m = i;
    int n = 1 + (i+j)/2;
    while( m <= (i+j)/2 && n <= j)
    {
        if(A[m] > A[n])
        {
            B[u] = A[n];
            n++;u++;
        }
        else
        {
            B[u] = A[m];
            m++;u++;
        }
    }
    if(n > j)
    {
        while(u <= j)
        {
            B[u] = A[m];
            m++;u++;
        }
    }
    else
    {
        while(u <= j)
        {
            B[u] = A[n];
            n++;u++;
        }
    }
    for(int c = i;c <= j ;c++)
    {
        A[c] = B[c];
    }
}
void merge_sort(int i,int j,int A[])
{
    if(j != i)
    {
        merge_sort(i , (i+j)/2 , A);
        merge_sort(1+(i+j)/2 , j ,A);
    }
    if( i != j)
       mersort(i,j,A);
}
int main()
{
    int A[20];
    int num;
    cout<<"数组长度";
    cin>>num;
    for(int i=1 ; i <= num ; i++)
        cin>>A[i];
    merge_sort(1,num,A);
    for(int i= 1;i<=num;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
