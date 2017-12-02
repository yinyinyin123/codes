#include<iostream>
#include<string>
#include<cmath>

using namespace std;

typedef struct Stack{

    int  STACK[30];
    int  top;

}Stack;

typedef struct Stack_char{
    char STACK[30];
    int  top;
}Stack_char;

void initialize(Stack &S)
{
    S.top=-1;
}
void initialize(Stack_char &C)
{
    C.top=-1;
}

void push(Stack_char &C,char data)
{
    C.top++;
    C.STACK[C.top]=data;
}

void push(Stack &S,int data)
{
    S.top++;
    S.STACK[S.top]=data;
}

char pop(Stack_char &C)
{
    C.top--;
    return C.STACK[C.top+1];
}
int pop(Stack &S)
{
    S.top--;
    return S.STACK[S.top+1];
}
bool empty(Stack S)
{
    if(S.top==-1)
        return true;
    return false;
}
bool empty(Stack_char &C)
{
    if(C.top==-1)
        return true;
    return false;
}

bool is_number(string str , int a)
{
    if(str[a]=='0' || str[a]=='1' || str[a]=='2' || str[a]=='3' || str[a]=='4' || str[a]=='5' || str[a]=='6' || str[a]=='7' || str[a]=='8' || str[a]=='9')
         return true;
    return false;
}
int number(char c)
{
    if(c=='+')
        return 1;
    else if(c=='-')
        return 1;
    else if(c=='*')
        return 2;
    else if(c=='\\')
        return 2;
    else if(c=='(')
        return 3;
    else
        return 4;
}
int help[10];
void calculate(string str , int i , Stack &S , Stack_char &C)
{
    int a = 0 , b , c , d , e , f;
    char h;

    while( a < i)
    {
        cout<<a<<" "<<str[a];
        cout<<" "<<S.top<<"  "<<C.top<<endl;
        c = 0;
        if( ! is_number(str , a ) )
        {
            if ( empty(C) )
                push( C ,  str[a] );
            else
            {
                if(number(str[a])==4)
                {
                    while(number(C.STACK[C.top]) != 3)
                    {
                        d = pop(S);
                        b = pop(S);
                        h=pop(C);
                        if(h=='+')
                            push(S , b + d);
                        else if(h=='-')
                            push(S , b - d);
                        else if(h=='*')
                            push(S , b * d);
                        else if(h=='\\')
                            push(S , b / d);
                    }
                    pop(C);
                }
                else
                {
                    if( number(str[a]) > number(C.STACK[C.top]) || number(C.STACK[C.top])==3)
                    {

                        push( C , str[a] );

                    }
                    else
                    {

                        while(number(str[a]) <= number(C.STACK[C.top]) && number(C.STACK[C.top]) !=3  && !empty(C))
                        {

                            d = pop(S);
                            b = pop(S);
                            h=pop(C);
                            if ( h=='+' )
                                push(S , b + d);
                            else if ( h=='-')
                                push(S , b - d);
                            else if ( h=='*')
                                push(S , b * d);
                            else if ( h=='\\')
                                push(S ,b / d);
                        }
                        push(C , str[a]);
                    }
                }
            }
            a++;
        }
        else
        {
            c = -1;
            f = 0;
            while( is_number ( str , a ))
            {
                c++;
                help[c] = str[a] + 0 - '0';
                a++;
            }
            for(e=0 ; e <= c ; e++)
            {
                f += help[e] * pow(10 , c-e);
            }
            push(S , f);
        }
    }
    while(!empty(C))
    {
        d = pop(S);
        b = pop(S);
        h = pop(C);
        if(h =='+')
            push(S , b + d);
        else if(h =='-')
            push(S , b - d);
        else if(h =='*')
            push(S , b * d);
        else if(h =='\\')
            push(S , b / d);
    }
}
int main()
{
    string str="2*9-3*(2-1)+2*(20\\5-4)";
    int i;
    Stack S;
    Stack_char C;
    initialize(C);
    initialize(S);
    for(i=0;str[i]!='\0';i++);
    calculate(str,i,S,C);
    cout<<S.STACK[S.top];
    return 0;
}





