#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <class Type, int kSize = 10>
class Queue
{
public:
    Queue()
    : _front(0)
    , _rear(0)
    , _base(new Type[kSize]())
    {}
    
    ~Queue()
    {
        if(_base)
        {
            delete [] _base;
            _base = nullptr;
        }
    }

    bool full()
    {
        return (_rear+1)%kSize == _front;
    }

    bool empty()
    {
        return _rear == _front;
    }

    void push(const Type & value)
    {
        if(!full())
        {
            _base[_rear++] = value;
        }
    }

    void pop()
    {
        if(!empty())
        {
           _front = (_front+1)%kSize;
        }
    }

    Type front()
    {
        if(!empty())
        {
            return _base[_front];
        }
    }

    Type back()
    {
        if(!empty())
        {
            return _base[_rear-1];
        }
    }

private:
    int _front;
    int _rear;
    Type * _base;    
};

int main(void)
{
    Queue<int> que;
    cout << ">> 此时队列中是否为空?" << que.empty() << endl;
    que.push(1);
    cout << ">> 此时队列中是否为空?" << que.empty() << endl;
    for(int idx=2;idx!=12;++idx)
    {
        que.push(idx);
    }
    cout << ">> 此时队列中是否已满?" << que.full() << endl;
    while(!que.empty())
    {
        cout << que.front() << endl;
        que.pop();
    }
    cout << ">> 此时队列中是否为空?" << que.empty() << endl;
    
    return 0;
}

