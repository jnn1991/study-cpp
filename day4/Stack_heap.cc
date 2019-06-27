#include <iostream>
using std::cout;
using std::endl;

//只能生成栈对象，不能生成堆对象
//
//解决方案：将operator new 放入private 区
//
class Stack
{
public:
    Stack()
    {
        cout << "Stack 构造函数被调用" << endl;
    }

    ~Stack()
    {
        cout << "Stack 析构函数被调用" << endl;
    }
private:
    static void* operator new(std::size_t nSize);
    static void operator delete(void *pVoid);

};

class Heap
{
public:
    Heap()
    {
        cout<< "Heap 构造函数被调用"<< endl;
    }
    void destroy()
    {
        delete this;
    }

private:
    ~Heap()
    {
        cout<< "~Heap 析构函数被调用"<< endl;
    }

};

int main(void)
{
   
    return 0;
}

