#include<iostream>

using namespace std;

int main()
{
	int a;
	int b[100];
	int c,d=-1,e;
	cin>>a;
	while(a>1)
	{
		c=a%2;
		d++;
		b[d]=c;
		a=a/2;
	}
	if(a==0)
		b[d+1]=0;
	else
		b[d+1]=1;
	for(e=d+1;e>=0;e--)
	{
		cout<<b[e];
	}

	return 0;
}