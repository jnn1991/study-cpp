#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class CowString
{
    class CharProxy
    {
    public:
        CharProxy(CowString & self,int idx)
        : _self(self)
        , _idx(idx)
        {}

        char & operator=(const char & ch);

        friend std::ostream & operator<<(std::ostream & os,const CharProxy & rhs);
        
    private:
        CowString & _self;
        int _idx;
    };
public:
    CowString()
    :_pstr(new char[1+4]() + 4)
    {
        cout<< "CowString()"<< endl;
        initRefcount();
    }
    CowString(const char * pstr)
    :_pstr(new char[strlen(pstr)+5]() + 4)
    {
        cout << "CowString(const char *)"<<endl;
        initRefcount();
        strcpy(_pstr,pstr);
    }
    CowString(const CowString & rhs)
    : _pstr(rhs._pstr)
    {
        increaseRefcount();
        cout<< "CowString(const CowString &)"<<endl;
    }
    CowString & operator=(const CowString & rhs)
    {
        cout << "CowString & operator=(const CowString &)"<<endl;
        if(this != &rhs)
        {
            release();

            _pstr =rhs._pstr;
            increaseRefcount();
        }
        return *this;
    }
    ~CowString()
    {
        release();
    }
    int size() const
    {
        return strlen(_pstr);
    }
    const char * c_str() const{return _pstr;}

    int refcount() const
    {
        return *(int*)(_pstr-4);
    }
    CharProxy  operator[](int idx);

    friend std::ostream & operator<<(std::ostream & os ,const CowString & rhs);
    friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);

private:
    void initRefcount()
    {
        *(int*)(_pstr - 4) = 1;
    }
    void increaseRefcount()
    {
        ++*(int*)(_pstr - 4) ;
    }
    void decreaseRefcount()
    {
        --*(int*)(_pstr - 4);
    }
    void release()
    {
        decreaseRefcount();
        if(refcount()==0)
        {
            delete [] (_pstr -4);
            cout << ">> delete heap data!" <<endl;
        }
    }
private:
    char * _pstr;

};
std::ostream & operator<<(std::ostream & os,const CowString & rhs)
{
    os << rhs._pstr;
    return os;
}
   
CowString::CharProxy CowString::operator[](int idx)
{
    return CharProxy(*this,idx);
}

char & CowString::CharProxy::operator=(const char & ch)
{
    if(_idx >= 0 && _idx < _self.size())
    {
        if(_self.refcount()>1)//共享字符串，执行深拷贝
        {
            _self.decreaseRefcount();

            char * ptmp = new char [_self.size() + 5]()+4;
            strcpy(ptmp,_self._pstr);
            _self._pstr=ptmp;
            _self.initRefcount();
        }
        _self._pstr[_idx]=ch;
        return _self._pstr[_idx];
    }else{
        static char nullchar='\0';
        cout <<"下标越界"<<endl;
        return nullchar;
    }
    
}

std::ostream & operator<<(std::ostream & os, const CowString::CharProxy & rhs)
{
    os<< rhs._self._pstr[rhs._idx];
    return os;
}

#if 0
//下标访问运算符的实现不能区分出接下来的操作是读操作还是写操作
char & CowString::operator[](int idx)
{
    if(idx >= 0 && idx < size())
    {
        if(refcount()>1)//共享字符串，执行深拷贝
        {
            decreaseRefcount();

            char * ptmp = new char [size() + 5]()+4;
            strcpy(ptmp,_pstr);
            _pstr=ptmp;
            initRefcount();
        }
        return _pstr[idx];
    }else{
        static char nullchar='\0';
        cout <<"下标越界"<<endl;
        return nullchar;
    }
}
#endif

int main(void)
{
    CowString s1;
    CowString s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1' refcount = " << s1.refcount() << endl;
    cout << "s2' refcount = " << s2.refcount() << endl;

    CowString s3 = "hello,world";
    CowString s4 = s3;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s3' refcount = " << s3.refcount() << endl;
    cout << "s4' refcount = " << s4.refcount() << endl;
    printf("s3's address is %p\n", s3.c_str());
    printf("s4's address is %p\n", s4.c_str());

    return 0;
}

