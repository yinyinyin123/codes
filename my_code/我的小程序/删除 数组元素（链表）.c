#include<stdio.h>
#include<stdlib.h>

struct link
{
	int data;
	struct link *next;
};

struct link *append(struct link *head,int j,int a[])
{
	struct link *p = NULL;
	int i;
	for (i = 1; i <= j; i++)
	{
		struct link *pr = head;
		p = (struct link *)malloc(sizeof(struct link));
		if (p == NULL)
		{
			printf("no memory");
			exit(0);
		}
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			while (pr->next != NULL)
			{
				pr = pr->next;
			}
			pr->next = p;
		}
		p->data = a[i-1];
		p->next = NULL;
		
	}
	return head;
	
}
struct link *del(struct link *head, int k)
{
	struct link *p = head, *pr = head;
	while (k != p->data && p->next != NULL)
	{
		pr = p;
		p = p->next;
	}
	if (k == p->data)
	{
		if (p == head)
		{
			head = p->next;
		}
		else
		{
			pr->next = p->next;
		}
		free(p);
	}
	return head;
}
void print(struct link *head)
{
	struct link *p = head;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
}
void delete(struct link *head)
{
	struct link *p = head, *pr = NULL;
	while (p != NULL)
	{
		pr = p;
		p = p->next;
		free(pr);
	}
}
int main()
{
	int a[5] = { 1,2,3,4 };
	struct link *head = NULL;
	head = append(head,4,a);
	head = del(head, 3);
	head = del(head, 2);
	
	
	
	
	getchar();
	return 0;


}