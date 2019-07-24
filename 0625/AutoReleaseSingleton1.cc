#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease(){
            cout <<"AutoRelease()"<<endl;
        }
        ~AutoRelease()
        {
            if(_pInstance)
            {
                delete _pInstance;
                cout<<"~AutoRelease()"<<endl;
            }
        }
    };
public:

    static Singleton * getInstance()
    {
        if(_pInstance==nullptr)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }

    void print() const
    {
        cout << "Singleton::_data = "<<_data<<endl;
    }
private:
    Singleton():_data(0) {  cout<<"Singleton()"<<endl;    }
    ~Singleton(){   cout << "~Singleton()"<<endl;   }
    int _data;
    static Singleton *_pInstance;
    static AutoRelease _autoRelease;
        
};
/* Singleton * Singleton::_pInstance=nullptr; */
//解决多线程安全的问题
Singleton * Singleton::_pInstance = getInstance();//饱汉模式

Singleton::AutoRelease Singleton::_autoRelease;//C++11
int main(void)
{
   
    Singleton* p1 = Singleton::getInstance();
    p1->print();
    return 0;
}

