#include <iostream>
using std::cout;
using std::endl;

//单例设计模式
//要求：通过某一个类在内存中只能创建唯一的一个对象
//
//1.该对象不能是栈（全局）对象
//2.该对象只能是一个堆对象
//
//
//单例模式的应用场景有：
//1.单例模式替换全局变量
//2.配置文件的内容可以用单例对象存储
//3.词典文件、网页库

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(_pInstance == nullptr)
            _pInstance = new Singleton();
        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;
    }
        
    void print() const
    {
        cout<< "Singleton::data = "<<_data<<endl;
    }

private:
    Singleton():_data(0)  {  cout<< "Singleton()" << endl; }
    ~Singleton() {  cout << "~Singleton()"<<endl; }
    int _data;
    static Singleton *_pInstance;
};
Singleton * Singleton::_pInstance = nullptr;
int main(void)
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();

    cout << "p1 = " << p1 << endl
         << "p2 = " << p2 << endl;

    Singleton::getInstance()->print();
    Singleton::destroy();
    return 0;
}

