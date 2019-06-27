#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
class String
{
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
        if(this!=&rhs){

            delete [] _pstr;
            _pstr=new char[strlen(rhs._pstr)+1];
            strcpy(_pstr,rhs._pstr);
        }
        return (*this);
    }

    ~String()
    {
        delete[] _pstr;
        _pstr=NULL;
    }

    /* String &operator=(const char *_str) */
    /* { */
    /*     if(this->_pstr!=_str){ */

    /*         delete [] _pstr; */
    /*         _pstr=new char[strlen(_str)+1]; */
    /*         strcpy(_pstr,_str); */
    /*     } */
    /*     return (*this); */
    /* } */

    String &operator+=(const String &rhs)
    {
        if(sizeof(_pstr)>strlen(_pstr)+strlen(rhs._pstr))
        {
            strcat(_pstr,rhs._pstr);
            return (*this);
        }
    }

    char &operator[](std::size_t index)
    {
        static char szNull='\0';
        if(index < strlen(_pstr))
        {
            return _pstr[index];
        }else{
            cout << "下标越界" <<endl;
            return szNull;
        }
    }

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);
    void print()
    {
        if(_pstr)
            cout<<_pstr<<endl;
    }
private:
    char* _pstr;
};

bool operator == (const String &lhs,const String & rhs)
{
    return !strcmp(lhs._pstr,rhs._pstr);
}

bool operator != (const String &lhs,const String & rhs)
{
    return strcmp(lhs._pstr,rhs._pstr);
}

bool operator<(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)<0)
    {
        return true;
    }else{
        return false;
    }
}

bool operator>(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)>0)
    {
        return true;
    }else{
        return false;
    }
}

bool operator<=(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)<=0)
    {
        return true;
    }else{
        return false;
    }
}

bool operator>=(const String &lhs, const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)>=0)
    {
        return true;
    }else{
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os<< s._pstr;
    return os;
}

std::istream &operator>>(std::istream &is, String &s)
{
    is>>s._pstr;
    return is;
}

/* String operator+(const String &lhs, const String &rhs) */
/* { */
/*     if(sizeof(lhs)>strlen(lhs)+strlen(rhs._pstr)) */
/*     { */
/*         strcat(lhs._pstr,rhs._pstr); */
/*     } */
/*     return lhs; */
/* } */
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
    str4="haha";
    str4.print();
    

    return 0;
}

