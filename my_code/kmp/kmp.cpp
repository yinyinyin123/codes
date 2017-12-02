#include <iostream>

using namespace std;
int next[20];
void getnext(char a[],int m)
{
    int j=1,k=0;
    next[1]=0;
    while(j<m)
    {
        if(k==0 || a[j]==a[k])
        {
            j++;
            k++;
            next[j]=k;
        }
        else
        {
            k=next[k];
        }
    }
}
void find(char a[],char b[],int k,int m)
{
    int i=1,j=1;
    while(i<=k && j<=m)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
            if(j==0)
            {
                i++;
                j++;
            }
        }
    }
    if(j>m)
        cout<<"we find it in the position:"<<" "<<i-m;
}
int main()
{
    char a[20];
    char b[20];
    int i,j;
    cout<<"主串长度:";
    cin>>i;
    cout<<endl<<"主串:";
    for(int u=1;u<=i;u++)
        cin>>a[u];
    cout<<endl<<"模式串长度:";
    cin>>j;
    cout<<endl<<"模式串:";
    for(int y=1;y<=j;y++)
    {
        cin>>b[y];
    }
    getnext(b,j);
    find(a,b,i,j);
    return 0;
}
