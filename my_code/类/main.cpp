#include <iostream>

using namespace std;

class date{
   public:
       date(int y=2001,int m=2,int d=20);
       void set_date(int y,int m,int d);
       void print_date();
       int get_year();
       int get_month();
       int get_day();
   private:
       int year;
       int month;
       int day;
};
bool check(int a,int b,int c)
{
    if(b>12 || b<1 || c<1 || c>31)
        return false;
    return true;
}
date::date(int y,int m,int d)
{
    if(check(y,m,d))
    {
        year=y;
        month=m;
        day=d;
    }
    else
    {
        year=2001;
        month=2;
        day=20;
    }
}
void date::set_date(int y , int m , int d)
{
    if(check(y,m,d))
    {
        year = y;
        month = m;
        day = d;
    }
    else
    {
        y = 2001;
        m = 2;
        d = 20;
    }
}
int date::get_day()
{
    return day;
}
int date::get_year()
{
    return year;
}
int date::get_month()
{
    return month;
}
void date::print_date()
{
    cout<<year<<" "<<month<<" "<<day<<endl;
}
int main()
{
    date D1(2001,30,10);
    date D2(2001,11,9);
    D1.print_date();
    D2.print_date();
    return 0;
}
