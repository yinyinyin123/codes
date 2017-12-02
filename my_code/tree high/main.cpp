#include <iostream>

using namespace std;

typedef struct node{
   char data;
   node *left,*right;

}node,*tree;
void creat(tree &T)
{
    char data;
    cin>>data;
    if(data!='#')
    {
        T=new node;
        T->data=data;
        T->left=T->right=NULL;
        creat(T->left);
        creat(T->right);
    }
}
void print(tree T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        print(T->left);
        print(T->right);
    }
}
int high(tree T)
{
    if(T==NULL)
        return 0;
    else
    {
        if(high(T->left) > high(T->right))
            return high(T->left)+1;
        else
            return high(T->right)+1;
    }
}
int main()
{
    tree T=NULL;
    creat(T);
    int j;
    cout << "Hello world!" << endl;
    print(T);
    cout<<high(T->left->left);
    return 0;
}
