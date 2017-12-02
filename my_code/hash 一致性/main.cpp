#include <iostream>
#include <string>

using namespace std;

typedef struct ai{
   string str;
   int mark;
}ai;
ai a[1024];   //建立一个长度为1024的环 ，环上的每个位置存储俩个数据 ，分别是是字符串信息和一个标志，标志用来判断是否为服务器

typedef struct has{   //服务器
   string str[100];  //建立一个字符串数组用来存储数据
   string name;  //记录服务器的名字
   int hash_num;   //记录hash值 ，也就是在环中的下标
   int index;  //记录保存数据的个数
}has;
has m[1];
class myhash{
public:
    myhash(); //构造函数
    ~myhash();
    void creat_hash();  //建立服务器
    //void get_data();   //输出每个服务器的名字
    void get_hash();  // 将服务器映射在环中的下标记录在服务器的hash_num
    void map_hash();  //建立虚拟节点，并将也映射在环中
    void insert_hash(); //将数据存入服务器中
    void add_hash(); //增加一个服务器
    int find_hash(); //在服务器中寻找数据
    int which_hash(string str); //根据服务器名字找到服务器
    void delet_hash(); //删除服务器
    void adjust_hash(string str); //删除服务器后的调整操作
protected:
    int num;  //服务器的个数
    has *b;  //指向服务器的指针
};
myhash::myhash()    //构造函数
{
    num = 1;  //服务器初始个数为1
    b = new has[1];
    for(int i=0;i < num;i++)
    {
       b[i].name = "hash";    //叫做hash
    }
}
myhash::~myhash()
{
    delete []b;
}
/*void myhash::get_data()
{
    cout<<endl;
    for(int i=0 ; i<num;i++)
    {
        cout<<b[i].name<<" ";
    }
}*/
void myhash::creat_hash()
{
    int n;
    cout<<"input the number of array:"; //输入服务器的个数
    cin>>n;
    num = n;
    b = new has[n];
    for(int i=0 ; i<n ; i++)
    {
        b[i].index = 0;
        cin>>b[i].name;  //给服务器赋名字
    }
}
int get_the_len(string str)
{
    for(int j=0 ; ;j++)
    {
        if(str[j]=='\0') //获得字符串的长度
            return j;
    }
}
int myhash::which_hash(string str) //根据服务器名字寻找服务器
{
    for(int i=0;i<num;i++)   //遍历
    {
        if(b[i].name == str)
            return i;
    }
}
int gethash(string str)  //计算hash ：每个字符的acsii的平方的和对1024求余
{
    int m,y=0,j;
    j = get_the_len(str);

    for(int i=0 ;i<j ;i++)
    {
        m = str[i];
        y += m*m;
    }
    return y%1024;
}
void chushi(ai a[])  //对环初始化
{
    for(int i=0;i<=1023;i++)
    {
        a[i].str = "#";
        a[i].mark = 0;
    }
}
void myhash::get_hash() //通过hash函数得到的环中的下标赋值给hash_num
{
    int m;
    for(int i=0;i<num;i++)
    {
        m = gethash(b[i].name);
        b[i].hash_num = m;
    }
}
void myhash::map_hash()  //建立虚拟节点
{
    int m,n;
    string str;
    char *p;
    for(int i=0 ; i<num ;i++)
    {
        cout<<b[i].name<<":"<<"virtal node:";
        m = b[i].hash_num;
        str = "1" + b[i].name;  //在每个服务器的名字前加1，3，5，7，9然后hash到环中
        a[gethash(str)].str =  b[i].name; // hash到环中下标的字符串是服务器的名字
        a[gethash(str)].mark =  1;  //将mark设置为1 ，表明他是服务器
        cout<<"(1)"<<str<<" "<<gethash(str)<<endl;
        str = "3" + b[i].name;
        a[gethash(str)].str = b[i].name;
        a[gethash(str)].mark =  1;
        cout<<"(2)"<<str<<" "<<gethash(str)<<endl;
        str = "5" + b[i].name;
        a[gethash(str)].str = b[i].name;
        a[gethash(str)].mark =  1;
        cout<<"(3)"<<str<<" "<<gethash(str)<<endl;
        str = "7" + b[i].name;
        a[gethash(str)].str = b[i].name;
        a[gethash(str)].mark =  1;
        cout<<"(4)"<<str<<" "<<gethash(str)<<endl;
        str = "9" + b[i].name;
        a[gethash(str)].str = b[i].name;
        a[gethash(str)].mark =  1;
        cout<<"(5)"<<str<<" "<<gethash(str)<<endl;
    }
}
void myhash::insert_hash() //存储数据
{
    string str;
    int m,h=-1,p;
    cout<<"input the data you want to memory:";
    cin>>str;
    while(str != "#")
    {
        m = gethash(str);  //m是字符串hash到环中的位置
        for(int n = m ; n < 1024 ; n++) //从 m 位置开始遍历
        {
            if(a[n].mark == 1)  //直到遇到一个虚拟节点
            {
                h = which_hash(a[n].str);  //通过字符串得到这个虚拟节点属于哪一个服务器
                b[h].str[b[h].index] = str; //将该字符串存储于服务器中
                b[h].index++;
                a[m].str = str;
                cout<<str<<"     has been memoried in the "<<a[n].str<<endl;
                break;
            }
        }
        if(h == -1) //这种情况是从 m 到 数组最大位置没有虚拟节点
        {
            for(p = 0 ; p<1024;p++) //那么就从0 开始找虚拟节点
            {
                if(a[p].mark==1)
                {
                    h = which_hash(a[p].str);
                    b[h].str[b[h].index] = str;
                    b[h].index++;
                    a[m].str = str;
                    cout<<str<<"     has been memoried in the "<<b[0].name<<endl;
                    break;
                }
            }
        }
        cin>>str;
    }
}
int myhash::find_hash()
{
    string str;
    int m,n,flag=0,i;
    cout<<endl<<"input the data you want to find:";
    cin>>str;
    m = gethash(str);
    if(a[m].str == "#") //如果字符串hash在环中的位置的str为#，代表没有hash到过，说明没有这个数据
        cout<<"there is no this data";
    else
    {
       for(i=m;i<1024;i++)
       {
           if(a[i].mark ==1)  //从m开始遍历，找到第一个虚拟节点
           {
               flag=1;
               n = which_hash(a[i].str); //通过字符串得到第几个服务器
               break;
           }
       }
       if(flag == 0) //对于m到数组最大位置没有虚拟节点的处理
       {
           for(int i=0 ; i < m ;i++) //从0位置开始寻找
           {
               if(a[i].mark == 1)
               {
                   n = which_hash(a[i].str);
                   break;
               }
           }
       }
       for(int j=0 ; j < b[n].index;j++) //在第n个服务器中遍历寻找
       {
            if(b[n].str[j] == str)
            {
                cout<<"we find it in the"<<b[n].name;
                return 0;
            }
       }
       cout<<"there is no this data";
    }
}
void myhash::add_hash()
{
    int m = num,p,flag=0,q,flag1=0,c;
    string str;
    has n[10];
    for(int i=0;i<num;i++)
    {
        n[i] = b[i];
    }
    num = num + 1;
    b = new has[num];
    for(int i = 0 ; i < num-1 ; i++)
    {
        b[i] = n[i];
    }
    cout<<"input the name of hash you want to add:";
    cin>>str;
    b[num-1].name = str;   //向类中加入该服务器
    b[num-1].index = 0;
    b[num-1].hash_num = gethash(str);  //将这个服务器hash名字到环中
    a[gethash(str)].str = str;
    a[gethash(str)].mark = 1;
    for(p = gethash(str)-1; ;p--)  //找到这个服务器前一个虚拟节点
    {
        if(a[p].mark == 1)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        for(p = 1023;  ; p--)//has changed
        {
            if(a[p].mark==1)
                break;
        }
    }
    for(q = gethash(str)+1 ; ;q++)  //找到这个服务器的后一个虚拟节点
    {
        if(a[q].mark==1)
        {
            flag1=1;
            break;
        }
    }
    if(flag1==0)
    {
        for(q=0; ;q++)
        {
            if(a[q].mark == 1)
                break;
        }
    }
    for(int mm=p+1;mm<gethash(str);mm++)  //对于上一个节点到这个服务之间的节点所存储的信息在他下一个点中删除，并保存在新加的服务器中
    {
        if(a[mm].str != "#")
        {
            cout<<a[mm].str<<" has been changed"<<endl;
            b[num-1].str[b[num-1].index] = a[mm].str;
            b[num-1].index++;
            c = which_hash(a[q].str);
            for(int pp=0; ;pp++)
            {
                if(b[c].str[pp] == a[mm].str)
                {
                    for(int qq=pp ;qq<b[c].index-1;qq++)
                    {
                        b[c].str[qq] = b[c].str[qq+1];
                    }
                    b[c].index--;
                    break;
                }
            }
        }
    }
}
void myhash::adjust_hash(string str)
{
    int m,n,i,j,flag=0,flag1=0,p,q;
    a[gethash(str)].str = "#";
    a[gethash(str)].mark = 0;
    for(p = gethash(str)-1; ;p--)  //p is the front node  //对于删除的节点找到他的前一个虚拟节点
    {
        if(a[p].mark == 1)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        for(p = 1023;  ; p--)//has changed
        {
            if(a[p].mark==1&& a[p].str != a[gethash(str)].str)
                break;
        }
    }
    for(q = gethash(str)+1 ; ;q++)  //q is the last node  //找到后一个虚拟节点
    {
        if(a[q].mark==1 && a[q].str != a[gethash(str)].str)
        {
            flag1=1;
            break;
        }
    }
    if(flag1==0)
    {
        for(q=0; ;q++)
        {
            if(a[q].mark == 1 && a[q].str != a[gethash(str)].str)
                break;
        }
    }
    m = which_hash(a[q].str);
    if( p > q)      //将上一个虚拟节点到要删除的节点中在环上存储的数据都存储在下一个虚拟节点中
    {
        for(int i = p ; i < 1024 ; i++ )
        {
            if(a[i].str != "#" && a[i].mark == 0)
            {
                b[m].str[b[m].index] = a[i].str;
                b[m].index++;
                cout<<a[i].str<<" has been changed to "<<b[m].name<<endl;
            }
        }
        for(int i = 0 ; i < gethash(str) ; i++)
        {
            if(a[i].str != "#" && a[i].mark == 0)
            {
                b[m].str[b[m].index] = a[i].str;
                b[m].index++;
                cout<<a[i].str<<" has been changed to "<<b[m].name<<endl;
            }
        }
    }
    else
    {
        for(int i = p;i < q; i++)
        {
            if(a[i].str != "#" && a[i].mark ==0 )
            {
                b[m].str[b[m].index] = a[i].str;
                b[m].index++;
                cout<<a[i].str<<" has been changed to "<<b[m].name<<endl;
            }
        }
    }
}
void myhash::delet_hash()
{
    string str,str_hash;
    int m,p;
    cout<<"input the web you want to delet:";
    cin>>str;
    has n[10];
    for(int i=0 ; i<num;i++)
        n[i] = b[i];
    for(m = 0;m<num ; m++)
    {
        if(n[m].name == str)
            break;
    }
    delete []b;
    num--;
    b = new has[num];   //在类中删除该服务器
    for(int i=0 ; i<m;i++)
       b[i] = n[i];
    for(int j=m;j<num;j++)   //在环上删除该服务器对应的虚拟节点
        b[j] = n[j+1];
    str_hash = "1" + n[m].name;
    adjust_hash(str_hash);
    str_hash = "3" + n[m].name;
    adjust_hash(str_hash);
    str_hash = "5" + n[m].name;
    adjust_hash(str_hash);
    str_hash = "7" + n[m].name;
    adjust_hash(str_hash);
    str_hash = "9" + n[m].name;
    adjust_hash(str_hash);
}
int main()
{
    myhash H;
    chushi(a);
    H.creat_hash();
    H.get_hash();
    H.map_hash();
    H.insert_hash();
    H.find_hash();
    cout<<endl;
    H.add_hash();
    H.find_hash();
    cout<<endl;
    H.delet_hash();
    H.find_hash();
    return 0;
}
