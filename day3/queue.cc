#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
    Queue()
    :_capacity(10)
    ,_front(0)
    ,_rear(0)
    {
        data=new int[_capacity];
    }

    ~Queue()
    {
        delete[] data;
    }
    void push(int a)
    {
        if(_rear+1==_front)
        {
            printf("队列已满");
            return;
        }
        data[_rear] = a;
        _rear = (_rear+1)%_capacity;
    }

    void pop()
    {
        if(_rear==_front)
        {
            cout << "队空，无法出队" << endl;
            return;
        }
        _front=(_front+1)%_capacity;
    }

    int front()
    {
        return data[_front];
    }

    int back()
    {
        return data[_rear-1];
    }

    bool emty()
    {
        if(_rear==_front)
        {
            return true;
        }else{
            return false;
        }
    }

    bool full()
    {
        if(_rear+1==_front)
        {
            return true;
        }else{
            return false;
        }

    }

private:
    int _capacity;
    int *data;
    int _front;
    int _rear;
};

int main(void)
{
    Queue q1;
    q1.push(10);
    q1.push(14);
    q1.push(11);
    cout<<"front="<<q1.front()<<endl
        <<"back="<<q1.back()<<endl;
    q1.pop();
    cout<<"front="<<q1.front()<<endl
        <<"back="<<q1.back()<<endl;

    return 0;

}

