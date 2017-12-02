#include <iostream>

using namespace std;


class point{
   public:
       point();
       point(int x,int y);
       ~point();
       int get_x();
       int get_y();
       void set_x(int x);
       void set_y(int y);
   protected:
       int px;
       int py;
};
class point3D:public point
{
    public:
        point3D();
        point3D(int x,int y,int z);
        ~point3D();
        void set_point3D(int x,int y,int z);
        void print();
        const point3D& operator=(const point3D &t);
        point3D operator+(const point3D &t);
    protected:
        int pz;
};
point3D def[3]={point3D(1,2,3),point3D(4,5,6)};
class curve:public point3D
{
public:
    curve(int num = 2 , point3D hello[] = def);
    ~curve();

    void DisplayCurve();//输出折线的各个点的信息

    const curve& operator=(const curve &t); //运算符重载
    curve operator+(const point3D &t) ;
protected:
    int pnum;
    point3D *curpoint;
};
curve::curve(int num , point3D hello[])
{
    int i;
    pnum = num;
    curpoint = new point3D[num];
    for(i = 0 ; i < num ; i++)
    {
        curpoint[i] = hello[i];
    }
}
curve::~curve()
{
    delete []curpoint;
}
void curve::DisplayCurve()
{
    for(int i=0 ; i < pnum ; i++)
    {
        curpoint[i].print();
        cout<<endl;
    }
}
point3D::point3D()
{
    px = 10;
    py = 20;
    pz = 30;
}
point3D::point3D(int x,int y,int z)
{
    px = x;
    py = y;
    pz = z;
}
void point3D::print()
{
    cout<<px<<" "<<py<<" "<<pz;
}
const point3D& point3D::operator=(const point3D &t)
{
    px = t.px;
    py = t.py;
    pz = t.pz;
    return *this;
}
point3D::~point3D()
{

}
point3D point3D::operator+(const point3D &t)
{
    point3D p;
    p.px = t.px + px;
    p.py = t.py + py;
    p.pz = t.pz + pz;
    return p;

}
point::point()
{
    px = 10;
    py = 20;
}
point::point(int x , int y)
{
    px = x;
    py = y;
}
point::~point()
{

}
int point::get_x()
{
    return px;
}
int point::get_y()
{
    return py;
}
void point::set_x(int x)
{
    px = x;
}
void point::set_y(int y)
{
    py = y;
}
curve curve::operator+(const point3D &t)
{
    curve temp;
    temp.pnum = pnum + 1;
    delete []temp.curpoint;
    temp.curpoint = new point3D[temp.pnum];
    for(int i = 0 ; i < temp.pnum-1 ; i++)
    {
        temp.curpoint[i] = curpoint[i] ;
    }
    temp.curpoint[temp.pnum-1] = t;
    return temp;
}
const curve& curve::operator=(const curve &t)
{
    if(this != &t)
    {
        if(t.curpoint != NULL)
        {
            pnum = t.pnum ;
            delete []curpoint;
            curpoint = new point3D[pnum];
            for(int i = 0 ; i < pnum ; i++)
            {
                curpoint[i] = t.curpoint[i];
            }

        }
        else
        {
            pnum = t.pnum;
            curpoint = NULL;
        }
    }
    return *this;
}
int main()
{
   point p;
   point w(2,3);
   cout<<p.get_x()<<" "<<w.get_x()<<endl;
   point3D p1;
   point3D p2(10,20,30);
   point3D p3(30,40,50);
   p1 = p2 + p3;
   curve c1,c2,c3;
   c1.DisplayCurve();
   cout<<endl;
   c3 = c1 + p2 + p3 ;
   c3.DisplayCurve();

}
