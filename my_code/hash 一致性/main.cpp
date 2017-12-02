#include <iostream>
#include <string>

using namespace std;

typedef struct ai{
   string str;
   int mark;
}ai;
ai a[1024];   //����һ������Ϊ1024�Ļ� �����ϵ�ÿ��λ�ô洢�������� ���ֱ������ַ�����Ϣ��һ����־����־�����ж��Ƿ�Ϊ������

typedef struct has{   //������
   string str[100];  //����һ���ַ������������洢����
   string name;  //��¼������������
   int hash_num;   //��¼hashֵ ��Ҳ�����ڻ��е��±�
   int index;  //��¼�������ݵĸ���
}has;
has m[1];
class myhash{
public:
    myhash(); //���캯��
    ~myhash();
    void creat_hash();  //����������
    //void get_data();   //���ÿ��������������
    void get_hash();  // ��������ӳ���ڻ��е��±��¼�ڷ�������hash_num
    void map_hash();  //��������ڵ㣬����Ҳӳ���ڻ���
    void insert_hash(); //�����ݴ����������
    void add_hash(); //����һ��������
    int find_hash(); //�ڷ�������Ѱ������
    int which_hash(string str); //���ݷ����������ҵ�������
    void delet_hash(); //ɾ��������
    void adjust_hash(string str); //ɾ����������ĵ�������
protected:
    int num;  //�������ĸ���
    has *b;  //ָ���������ָ��
};
myhash::myhash()    //���캯��
{
    num = 1;  //��������ʼ����Ϊ1
    b = new has[1];
    for(int i=0;i < num;i++)
    {
       b[i].name = "hash";    //����hash
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
    cout<<"input the number of array:"; //����������ĸ���
    cin>>n;
    num = n;
    b = new has[n];
    for(int i=0 ; i<n ; i++)
    {
        b[i].index = 0;
        cin>>b[i].name;  //��������������
    }
}
int get_the_len(string str)
{
    for(int j=0 ; ;j++)
    {
        if(str[j]=='\0') //����ַ����ĳ���
            return j;
    }
}
int myhash::which_hash(string str) //���ݷ���������Ѱ�ҷ�����
{
    for(int i=0;i<num;i++)   //����
    {
        if(b[i].name == str)
            return i;
    }
}
int gethash(string str)  //����hash ��ÿ���ַ���acsii��ƽ���ĺͶ�1024����
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
void chushi(ai a[])  //�Ի���ʼ��
{
    for(int i=0;i<=1023;i++)
    {
        a[i].str = "#";
        a[i].mark = 0;
    }
}
void myhash::get_hash() //ͨ��hash�����õ��Ļ��е��±긳ֵ��hash_num
{
    int m;
    for(int i=0;i<num;i++)
    {
        m = gethash(b[i].name);
        b[i].hash_num = m;
    }
}
void myhash::map_hash()  //��������ڵ�
{
    int m,n;
    string str;
    char *p;
    for(int i=0 ; i<num ;i++)
    {
        cout<<b[i].name<<":"<<"virtal node:";
        m = b[i].hash_num;
        str = "1" + b[i].name;  //��ÿ��������������ǰ��1��3��5��7��9Ȼ��hash������
        a[gethash(str)].str =  b[i].name; // hash�������±���ַ����Ƿ�����������
        a[gethash(str)].mark =  1;  //��mark����Ϊ1 ���������Ƿ�����
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
void myhash::insert_hash() //�洢����
{
    string str;
    int m,h=-1,p;
    cout<<"input the data you want to memory:";
    cin>>str;
    while(str != "#")
    {
        m = gethash(str);  //m���ַ���hash�����е�λ��
        for(int n = m ; n < 1024 ; n++) //�� m λ�ÿ�ʼ����
        {
            if(a[n].mark == 1)  //ֱ������һ������ڵ�
            {
                h = which_hash(a[n].str);  //ͨ���ַ����õ��������ڵ�������һ��������
                b[h].str[b[h].index] = str; //�����ַ����洢�ڷ�������
                b[h].index++;
                a[m].str = str;
                cout<<str<<"     has been memoried in the "<<a[n].str<<endl;
                break;
            }
        }
        if(h == -1) //��������Ǵ� m �� �������λ��û������ڵ�
        {
            for(p = 0 ; p<1024;p++) //��ô�ʹ�0 ��ʼ������ڵ�
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
    if(a[m].str == "#") //����ַ���hash�ڻ��е�λ�õ�strΪ#������û��hash������˵��û���������
        cout<<"there is no this data";
    else
    {
       for(i=m;i<1024;i++)
       {
           if(a[i].mark ==1)  //��m��ʼ�������ҵ���һ������ڵ�
           {
               flag=1;
               n = which_hash(a[i].str); //ͨ���ַ����õ��ڼ���������
               break;
           }
       }
       if(flag == 0) //����m���������λ��û������ڵ�Ĵ���
       {
           for(int i=0 ; i < m ;i++) //��0λ�ÿ�ʼѰ��
           {
               if(a[i].mark == 1)
               {
                   n = which_hash(a[i].str);
                   break;
               }
           }
       }
       for(int j=0 ; j < b[n].index;j++) //�ڵ�n���������б���Ѱ��
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
    b[num-1].name = str;   //�����м���÷�����
    b[num-1].index = 0;
    b[num-1].hash_num = gethash(str);  //�����������hash���ֵ�����
    a[gethash(str)].str = str;
    a[gethash(str)].mark = 1;
    for(p = gethash(str)-1; ;p--)  //�ҵ����������ǰһ������ڵ�
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
    for(q = gethash(str)+1 ; ;q++)  //�ҵ�����������ĺ�һ������ڵ�
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
    for(int mm=p+1;mm<gethash(str);mm++)  //������һ���ڵ㵽�������֮��Ľڵ����洢����Ϣ������һ������ɾ�������������¼ӵķ�������
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
    for(p = gethash(str)-1; ;p--)  //p is the front node  //����ɾ���Ľڵ��ҵ�����ǰһ������ڵ�
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
    for(q = gethash(str)+1 ; ;q++)  //q is the last node  //�ҵ���һ������ڵ�
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
    if( p > q)      //����һ������ڵ㵽Ҫɾ���Ľڵ����ڻ��ϴ洢�����ݶ��洢����һ������ڵ���
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
    b = new has[num];   //������ɾ���÷�����
    for(int i=0 ; i<m;i++)
       b[i] = n[i];
    for(int j=m;j<num;j++)   //�ڻ���ɾ���÷�������Ӧ������ڵ�
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
