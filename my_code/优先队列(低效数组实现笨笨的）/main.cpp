#include <iostream>

using namespace std;

void make(int a[],int flag,int j,int k)
{
    int p=j,m;
    while(flag==2)
    {
                if(p*2>k)
                    flag=1;
                else if(p*2<=k && p*2+1>k)
                {
                    if(a[p]<a[p*2])
                    {
                        m = a[p];
                        a[p] = a[p*2];
                        a[p*2] = m;
                        p=2*p;
                    }
                    else
                        flag=1;
                }
                else
                {
                    if(a[p*2+1]>a[p*2] && a[p*2+1]>a[p])
                    {
                        m = a[p];
                        a[p] = a[p*2+1];
                        a[p*2+1] = m;
                        p=2*p+1;
                    }
                    else if(a[p*2]>a[p*2+1] && a[p*2]>a[p])
                    {
                        m = a[p];
                        a[p] = a[p*2];
                        a[p*2] = m;
                        p=2*p;
                    }
                    else
                        flag=1;

                }
    }
}
void creat(int a[],int k)
{
     int i,m,flag=1,p;
     for(i = k ; i>=1 ; i--)
     {
         for(int j = i ; j > 1 ; j = j/2)
         {
            if(a[j] > a[j/2])
            {
                flag=2;
                m = a[j];
                a[j] = a[j/2];
                a[j/2] = m;
            }
            make(a,flag,j,k);
            flag=1;
            /*while(flag==2)
            {
                if(p*2>k)
                    flag=1;
                else if(p*2<=k && p*2+1>k)
                {
                    if(a[p]<a[p*2])
                    {
                        m = a[p];
                        a[p] = a[p*2];
                        a[p*2] = m;
                        p=2*p;
                    }
                    else
                        flag=1;
                }
                else
                {
                    if(a[p*2+1]>a[p*2] && a[p*2+1]>a[p])
                    {
                        m = a[p];
                        a[p] = a[p*2+1];
                        a[p*2+1] = m;
                        p=2*p+1;
                    }
                    else if(a[p*2]>a[p*2+1] && a[p*2]>a[p])
                    {
                        m = a[p];
                        a[p] = a[p*2];
                        a[p*2] = m;
                        p=2*p;
                    }
                    else
                        flag=1;

                }
            }
         }*/
             }
     }
}
void delet(int a[],int k)
{
    int m;
    cout<<endl<<"the deleted data:"<<a[1];
    m=a[k+1];
    a[k+1]=a[1];
    a[1]=m;
    make(a,2,1,k);
}
void insert(int a[],int key,int i )
{
    a[i]=key;
    int m;
    for(int j=i;j>1;j=j/2)
    {
        if(a[j]>a[j/2])
        {
            m=a[j];
            a[j]=a[j/2];
            a[j/2]=m;
        }
    }
}
int find_the_data(int a[],int i,int key)
{
    for(int j=1;j<=i;j++)
    {
        if(a[j]==key)
        {
            cout<<"find it";
            return 0;
        }
    }
    cout<<"no this data";

}

int main()
{
     int a[20],i,m;
     cout<<"input the number of data:";
     cin>>i;
     cout<<endl<<"input the data:";
     for(int j=1;j<=i;j++)
        cin>>a[j];
     creat(a,i);
     for(int z = 1 ; z <= i ; z++ )
        cout<<a[z]<<"  ";
     i--;
     delet(a,i);
     cout<<endl;
     for(int z = 1 ; z <= i ; z++ )
        cout<<a[z]<<"  ";
     i++;

     cout<<endl<<"add the data:";
     cin>>m;
     insert(a,m,i);
     for(int z = 1 ; z <= i ; z++ )
        cout<<a[z]<<"  ";
     cout<<endl<<"find the data:";
     cin>>m;
     find_the_data(a,i,m);

     return 0;


}
