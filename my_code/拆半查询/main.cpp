#include <iostream>

using namespace std;

int find_it(int a[],int b,int i,int j)

{
    if(a[(i+j)/2]==b)
    {
        cout<<(i+j)/2;
        return (i+j)/2;
    }
    else if(j-i>=1  && a[(i+j)/2]>b)
        find_it(a,b,i,((i+j)/2)-1);
    else if(j-i>=1 && a[(i+j)/2]<b)
        find_it(a,b,((i+j)/2)+1,j);
}

int main()

{
    int buff[10]={1,2,3,4,5,6,7,8,9,10};
    int i;
    for(i=0;i<=10;i++)
       find_it(buff,i,0,9);
}
