#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
class String
{
private:
    char* _pstr;
public:
    String()
    {
        _pstr=nullptr;
    }
    String(const char *pstr)
    {
        _pstr=new char[strlen(pstr)+1];
        strcpy(_pstr,pstr);
    }

    String(const String &rhs)
    :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
    }

    String &operator=(const String &rhs)
    {
        if(this==&rhs)
            return (*this);
        _pstr=new char[strlen(rhs._pstr)+1];
        if(NULL!=_pstr)
        {
            strcpy(_pstr,rhs._pstr);
        }
        return (*this);
    }

    ~String()
    {
        delete[] _pstr;
        _pstr=NULL;
    }

    void print()
    {
        if(_pstr)
            cout<<_pstr<<endl;
    }
};

int main()
{
    String str1;
    str1.print();
    String str2="Hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();

    String str4=str3;
    str4.print();

    str4=str2;
    str4.print();

    return 0;
}

