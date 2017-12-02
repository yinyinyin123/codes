#include <stdio.h>
#include <stdlib.h>

int f(n)
{
    static i=0;
    if (n==0)
    {
        i++;
        return i;

    }


    if (n<0)
    {
        i=i;
    }
    if (n>0)
    {

        f(n-1);
        f(n-2);
    }
    return i;


}
int main()
{
    int n;
    printf("Please input the number of step:");
    scanf("%d",&n);
    int a;
    a=f(n);
    printf("%d",a);

}
