#include<stdio.h>
#include<stdlib.h>

struct link
{
	int data;
	struct link *next;
};

typedef struct list
{
	int a[10] = { 1,2,3,4 };
	int last;
}List;

struct link *maketogether(struct link *head, struct link *head1)
{
	struct link *pr=head;
	struct link *ptr2 = head1;
	while (pr->next != NULL)
	{
		pr = pr->next;
	}
	pr->next = ptr2;
	return head;
}
struct link *put_in(struct link *head, int a[], int i)
{
	struct link *p = NULL;
	int j;
	for (j = 0; j <= i; j++)
	{
		struct link *pr = head;
		p = (struct link *)malloc(sizeof(struct link));
		if (p == NULL)
		{
			printf("there is no memory");
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
		p->data = a[j];
		p->next = NULL;
	}
	return head;
}


struct link  *delet(struct link *head, int i)
{
	struct link *p = head, *pr = head;
	int j = 0, o = 0;
	while (p != NULL && j<i)
	{
		pr = p;
		p = p->next;
		j++;
	}
	pr->next = p->next;
	return head;

}
struct link *insert(struct link *head, int i, int j)
{
	struct link *p = NULL, *pr = head, *pp = NULL;
	int u = 0;
	p = (struct link *)malloc(sizeof(struct link));
	while (u <i - 1)
	{
		pr = pr->next;
		pp = pr->next;
		u++;
	}
	pr->next = p;
	p->data = j;
	p->next = pp;
	return head;
}
void print(struct link *head)
{
	struct link  *p = head;
	while (p != NULL)
	{
		printf("%2d", p->data);
		p = p->next;
	}
}
int main()
{
	struct link *head = NULL;
	struct link *head1 = NULL;
	List l;
	int b[10] = { 6,7,8,9 };
	l.last = 3;
    head = put_in(head, l.a, l.last);
	head1 = put_in(head1, b, 3);
	head = insert(head, 2, 6);
	maketogether(head, head1);
	print(head);
	getchar();
	return 0;
}