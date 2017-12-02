#include <iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;

typedef struct node{

    char data;
    struct node* next[0];
    int num;

}Node,*Tree;

void creat(Tree &T)
{
    int num;
    char data;
    cin>>data;
    cin>>num;
    T=(Node *)malloc(sizeof(Node)+num*sizeof(Node));
    T->num=num;
    T->data=data;
    cout<"ok";
    for(int i=1 ; i<=T->num ;i++)
        T->next[i]=NULL;
    for(int j=1 ; j<=T->num ; j++)
        creat(T->next[j]);

}
int main()
{
   Tree T;
   T=NULL;
   creat(T);
   return 0;
}
