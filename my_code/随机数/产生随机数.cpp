#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main()
{
    srand( (unsigned)time( NULL ) );
    for(int i=0;i<=10;i++)
        cout<<rand()%100<<"  ";
}
