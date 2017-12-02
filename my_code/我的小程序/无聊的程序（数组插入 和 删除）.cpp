#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int  a[7] = { 1,2,3,4,5 };
	int last;
}list;

void  insert(int p, int d, list &l)
{
	int q;
	for (q = l.last; q > p; q--)
	{
		l.a[q + 1] = l.a[q];
	}
	l.a[p] = d;
	l.last++;
}
void delet(int p, list &l)
{
	int q;
	for (q = p; q <= l.last - 1; q++)
	{
		l.a[q] = l.a[q + 1];
	}
	l.last--;
}
void print(list l)
{
	int i;
	for (i = 0; i <=l. last; i++)
	{
		printf("%2d", l.a[i]);
	}
}

int main()
{
	list l;
	l.last = 4;
	delet(3,l);
	print(l);
	getchar();
	return 0;


}