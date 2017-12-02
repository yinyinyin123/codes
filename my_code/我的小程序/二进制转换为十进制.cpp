#include<iostream>
#include<cmath>

using namespace std;


int main()
{
	char a[100];
	cout<<"请输入二进制数"<<endl;
	cin>>a;
	int i,j,m=-1;
	double n=0;
	for(i=0;  ;i++)
	{
		if(a[i]=='0'  ||  a[i]=='1')
		{
			m++;
			
		}
		else
			break;
	}
	for(j=0;j<=m;j++)
	{
		if(a[j]=='1')
			n+=pow(2,m-j);
	}
	cout<<n<<endl;
	return 0;
}