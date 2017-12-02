#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *left,*right,*f;
}node,*tree;
node *root = NULL;
node *father = NULL;
int high(node *p)
{
    if(p == NULL)
        return 0;
    else
    {
        if(high(p->left) > high(p->right))
            return high(p->left) + 1;
        else
            return high(p->right) + 1;
    }
}
int factor(node *p)
{
    return high(p->left) - high(p->right);
}
void leftrotate(node *t)
{
    node *c;
    c = t->right;
    if(t->f != NULL)
    {
        if(t->f->left == t)
            t->f->left = c;
        else
            t->f->right = c;
    }
    else
        root = c;
    c->f = t->f;
    t->right = c->left;
    if(c->left)
       c->left->f = t;
    c->left = t;
    t->f = c;
}
void rightrotate(node *t)
{
    node *c;
    c = t->left;
    if(t == root)
        root = c;
    else
    {
        if(t->f->left == t)
            t->f->left = c;
        else
            t->f->right = c;
    }
    c->f = t->f;
    t->left = c->right;
    if(c->right)
        c->right->f = t;
    c->right = t;
    t->f = c;
}
void print(node *t)
{
    if(t != NULL)
    {
        print(t->left);
        cout<<t->data<<"("<<high(t)<<")"<<" ";
        print(t->right);
    }
}
void create_avl(tree &t , int data)
{
    if(t == NULL)
    {
        t = new node;
        t->data = data;
        t->f = t->left = t->right = NULL;
        if(father)
            t->f = father;
        if(root == NULL)
            root = t;

    }
    else
    {
        father = t;
        if(t->data > data)
        {
            create_avl(t->left , data);
            if(factor(t) == 2)
            {
                if(data > t->left->data)
                {
                    leftrotate(t->left);
                    rightrotate(t);
                }
                else
                    rightrotate(t);
            }
        }
        else
        {
            create_avl(t->right , data);
            if(factor(t) == -2)
            {
                if(data > t->right->data)
                {
                    leftrotate(t);
                }
                else
                {
                    rightrotate(t->right);
                    leftrotate(t);
                }
            }
        }
    }
}
void creat_avl(tree &t)
{
    int data;
    cin>>data;
    while(data != 0)
    {
        create_avl(t , data);
        t = root;
        print(t);
        cout<<"   "<<t->data;
        cout<<endl;
        cin>>data;
    }

}
node *find_it(tree t , int data)
{
    while(t != NULL)
    {
        if(t->data == data)
            return t;
        else if(t->data > data)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}
node* find_the_min(tree t)
{
    while(t->left!=NULL)
        t = t->left;
    return t;
}
void balance(node *t)
{
    while(t != NULL)
    {
        if(factor(t) == 2)
        {
            if(high(t->left->right) < high(t->left->left))
            {
                rightrotate(t);
            }
            else
            {
                leftrotate(t->left);
                rightrotate(t);
            }
            t = t->f->f;
        }
        else if(factor(t)==-2)
        {
            if(high(t->right->left) > high(t->right->right))
            {
                rightrotate(t->right);
                leftrotate(t);
            }
            else
                leftrotate(t);
            t = t->f->f;
        }
        else
            t = t->f;
    }
}
void delet(tree &t , int data)
{
    node *pr,*p,*mother;
    pr = find_it(t , data);
    if(pr == NULL)
        cout<<"there is no this data";
    else
    {
        if(pr->left !=NULL && pr->right!=NULL)
        {
             p = find_the_min(pr->right);
             mother = p->f;
             pr->data = p->data;
             if(p->right != NULL)
             {
                 mother->right = p->right;
             }
             else
             {
                 if(mother == pr)
                    mother->right = NULL;
                 else
                    mother->left = NULL;
             }
        }
        else if(pr->left == NULL && pr->right == NULL)
        {
            mother = pr->f;
            if(mother == NULL)
            {
                cout<<"the tree is empty";
                t = root = pr = NULL;
            }
            else
            {
                if(mother->left == pr)
                    mother->left=NULL;
                else
                    mother->right=NULL;
            }
        }
        else
        {
            if(pr->left==NULL)
            {
                p = pr->right;
                pr->data = p->data;
                pr->right = NULL;
            }
            else
            {
                p = pr->left;
                pr->data = p->data;
                pr->left = NULL;
            }
            mother = pr->f;
        }
        balance(mother);
    }
}
void delet_avl(tree &t)
{
    int data;
    cin>>data;
    while(data != 0)
    {
        delet(t , data);
        t = root;
        print(t);
        cin>>data;
    }
}
int main()
{
    tree t = NULL;
    creat_avl(t);
    delet_avl(t);
    return 0;
}
