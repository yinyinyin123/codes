#include <iostream>
#include <fstream>
#include <string.h>
#include <malloc.h>

using namespace std;

typedef struct my_stack{
    char a[20];
    int i;
}my_stack;
typedef struct node{
    char s;
    int row[20];
    int flag;
    int num;
    node *left,*down,*right;
}node,*Trip;

my_stack  S;
void intialize(my_stack &S)
{
    S.i = -1;
}
char pop(my_stack &S)
{
    S.i--;
    return S.a[S.i+1];
}
void push(my_stack &S , char s)
{
    S.i++;
    S.a[S.i] = s;
}
int all_the_word(Trip T)
{
    if(!T)
        return 0;
    all_the_word(T->left);
    if(T->s!='#')
    {
        push(S,T->s);
        all_the_word(T->down);
        pop(S);
    }
    else
    {
        for(int i=0 ; i<=S.i ;i++)
            cout<<S.a[i];
        cout<<endl;
    }
    all_the_word(T->right);
}
int insert_trip(Trip &T,char *s,int row)
{
    if(T == NULL)
    {
        T = new node;
        T->s = *s;
        T->flag = 0;
        T->num = -1;
        T->left = T->right = T->down = NULL;
    }
    if(*s > T->s)
    {
        insert_trip(T->right , s,row);
    }
    else if(*s < T->s)
    {
        insert_trip(T->left , s , row);
    }
    else
    {
        if(*s != '#')
           insert_trip(T->down , ++s,row);
        else
        {
            T->s = '#';
            T->num++;
            T->row[T->num] = row;
        }
    }
}
char* str_to_char(string str , char *s)
{
    int i;
    int length = str.length();
    s = (char *)malloc((length+1)*sizeof(char));
    for(i=0;i<length;i++)
    {
         s[i] = str[i];
    }
    s[length] = '#';
    return s;
}
void create(Trip &T)
{
    char *s;
    string str;
    ifstream in;
    in.open("word.txt");
    int i=0,j,k,m,row=0;
    while(getline(in , str))
    {
        i = 0;
        row++;
        while(i<str.length() && str[i]-'0' != -48)
        {
            j = i;
            while(str[i] - '0' != -16 && i < str.length())
            {
               i++;
            }
            if(i!=j)
            {
                s = (char *)malloc((i-j)*sizeof(char));
                for( m = 0 ; m < i-j ; m++)
                {
                    s[m] = str[j+m];
                }
                if(ispunct(s[m-1]))
                    s[m-1]='#';
                else
                    s[m] = '#';
                for(int c=0 ;s[c]!='#';c++)
                    cout<<s[c];
                cout<<"#";
                insert_trip(T,s,row);
            }
            i++;
        }
        cout<<endl;
    }

    /*in>>str;
    s = str_to_char(str , s);
    while(*s!='#')
    {
        insert_trip(T,s);
        in>>str;
        s = str_to_char(str , s);
    }*/
}
void print(Trip T)
{
    if(T!=NULL)
    {
        cout<<T->s<<" ";
        print(T->left);
        print(T->down);
        print(T->right);
    }
}
void print_row(Trip T)
{
    for(int i=0 ;i <=T->num ;i++)
        cout<<T->row[i]<<" ";
}
node* find_it(Trip T , char *s)
{
    if(T == NULL)
        cout<<"there is no this word";
    else if(T->s == '#')
    {
        if(*s == '\0')
        {
            cout<<"find it in the row : ";
            print_row(T);
        }
        else
        {
            if(T->s > *s)
            {
                find_it(T->left , s);
            }
            else
            {
                find_it(T->right , s);
            }
        }
    }
    else
    {
        if(T->s > *s)
        {
            find_it(T->left , s);
        }
        else if(T->s < *s)
        {
            find_it(T->right , s);
        }
        else
        {
            find_it(T->down , ++s);
        }
    }
}
void find_trip(Trip T)
{
    char *s;
    cout<<endl<<"the word you want to find : ";
    cin>>s;
    while(*s != '*')
    {
        find_it(T , s);
        cin>>s;
    }
}
int nearfind(Trip T,const char *s)
{
    if(T == NULL)
        return 0;
    if(T->s < *s)
    {
        nearfind(T->right , s);
    }
    else if(T->s > *s)
    {
        nearfind(T->left , s);
    }
    else
    {
        if(*(s+1) !='#')
            nearfind(T->down ,++s);
        else
            all_the_word(T->down);
    }
}
int main()
{
    Trip T;
    char s;
    string str;
    T = NULL;
    intialize(S);
    create(T);
    print(T);
    all_the_word(T);
    cout<<endl;
    cin>>str;
    nearfind(T,str.c_str());
    find_trip(T);
    return 0;
}
