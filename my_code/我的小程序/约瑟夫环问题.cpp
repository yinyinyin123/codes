#include<stdio.h>
#include<stdlib.h>
struct link {
	int data;
	link *next;
};
struct Queue {
	link  *first;
	link  *last;
};
void put_in(Queue &Q, int n)
{
    int i = 1;
	struct link *p = NULL;
	Q.first = (struct link*)malloc(sizeof(struct link));
	Q.first->data = i;
	Q.first->next = NULL;
	while (i < n-1 )
	{
		struct link *pr = Q.first;
		i++;
		p = (struct link*)malloc(sizeof(struct link));
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
		p->data = i;
		p->next = NULL;
	}
	struct link *ptr = Q.first;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	Q.last = (struct link*)malloc(sizeof(struct link));
	ptr->next = Q.last;
	Q.last->next = Q.first;
	Q.last->data = n;
}
void change(Queue &Q,int q)
{
	int i = 1;
	int a, b;
	while (Q.last->data != Q.first->data)
	{
        while (i<q)
		{
			b = Q.first->data;
			Q.last = Q.first;
			Q.last->data = b;
			a = Q.first->next->data;
			Q.first = Q.first->next;
			Q.first->data = a;
			i++;
		}
		a = Q.first->next->data;
		Q.first = Q.first->next;
		Q.first->data = a;
		Q.last->next = Q.first;
		i = 1;
	}
}
void print(Queue Q)
{
	
	struct link *p = Q.first;
	while (p != Q.last);
	{
		printf("%d", p->data);
		p = p->next;
	}
}
int main()
{
    int n ,q;
	Queue Q;
	printf("请输入环的人数");
	scanf("%d", &n);
	printf("请输入r（即每隔多少人打死一个)");
	scanf("%d", &q);
	put_in(Q, n);
	change(Q,q);
	print(Q);
	getchar();
}