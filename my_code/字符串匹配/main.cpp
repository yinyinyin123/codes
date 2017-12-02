#include <iostream>
#include<string>


using namespace std;


int km(string t,int k,int m)
{
    int i=0;
    for(i=0;i<=m-k;i++)
    {
        if(t[i]!=t[i+k])
            return 0;
    }
    return 1;
}


int kmp(string t,int k)
{
    int i,j=0;
    if(k%2==0)
        i=k/2;
    else
        i=(k/2)+1;
    while(j==0 && i<=k)
    {
        j=km(t,i,k);
        if(j==1)
            return k-i+1;
        i++;
    }
    return 0;
}


void KMP(string s,string t)
{
    int i=0,j=0;
    while(j<=4)
    {
        if(t[j]==s[i])
        {
            i++;
            j++;
        }
        else
        {
            if(j==1 || j==0)
            {
                j=0;
                i++;
            }
            else
               j=kmp(t,j-1);
        }
    }
    cout<<i-1;
}


void BFcompare(string s,string t)
{
    int i=0,j=0;
    while(j<=4)
    {
        if(t[j]==s[i])
        {
            j++;
            i++;
        }
        else
        {
            i=i-j+3;
            j=1;
        }
    }
    cout<<i-1;
}


int main()
{
   string s,t;
   s="ababcabcacbab";
   t="cabca";
   cout<<"BFËã·¨: ";
   BFcompare(s,t);
   cout<<"KMPËã·¨: ";
   KMP(s,t);
}
