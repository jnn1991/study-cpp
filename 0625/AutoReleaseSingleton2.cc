#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
//单例对象自动释放
//方案二： atexit + 静态方法
class Singleton
{
public:

    static Singleton * getInstance()
    {
        if(_pInstance==nullptr)
        {
            _pInstance = new Singleton();
            atexit(destroy);
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
        
};
/* Singleton * Singleton::_pInstance=nullptr; */
//解决多线程安全的问题
Singleton * Singleton::_pInstance = getInstance();//饱汉模式

int main(void)
{
   
    Singleton* p1 = Singleton::getInstance();
    p1->print();
    return 0;
}

