#include <iostream>
using std::cout;
using std::endl;

class myStack
{
public:
    myStack(int size=10)
    :_top(-1)
    ,_size(size)
    ,_base(new int[_size]())
    {  

    }
    
    bool emty()
    {
        return _top == -1;
    }

    bool full()
    {
        return _top == _size-1;
    }
        
    //元素入栈
    void push(int a)
    {
        if(!full())
        {
            _base[++_top]=a;
        }else{
            return;
        }
    }
    
    void pop()
    {
        if(!emty())
        {
            --_top;
        }else{
            cout<<"栈空，出栈失败"<<endl;
            return;
        }
    }

    int top()
    {
        if(!emty())
        {
            return _base[_top];
        }
    }
    

private:
    int _top;
    int _size;
    int * _base;
};

int main(void)
{
    myStack Stack1;
    Stack1.push(10);
    Stack1.push(12);
    Stack1.push(14);
    cout << Stack1.top()<<endl;
    Stack1.pop();
    cout << Stack1.top()<<endl;
    
    return 0;
}

