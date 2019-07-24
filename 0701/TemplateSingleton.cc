#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class Singledog {
    class AutoRelease
    {
    public:
        AutoRelease(){  cout << "AutoRelease()" << endl;}
        ~AutoRelease()
        {
            if(_pInstance){
                delete _pInstance;
                _pInstance = nullptr;
                cout << "~AutoRelease()" << endl;
            }
        }
    };
public:
    template<class... Args >
        static T * getInstance(Args... args)
        {
            if (NULL == _pInstance)
            {
                (void)_auto;
                _pInstance = new T(args...);

            }
            return _pInstance;
        }
private:
    Singledog() {}
    ~Singledog() {}
private:
    static T * _pInstance;
    static AutoRelease _auto;

};

template <typename T>
T * Singledog<T>::_pInstance = NULL;

template <typename T>
typename Singledog<T>::AutoRelease Singledog<T>::_auto;


class Point {
public:
    Point(int x, int y) :_x(x), _y(y) {}

    void print() const
    {
        cout << "(" << _x
             << "," << _y
             << ")" << endl;
    }
    ~Point() {}
private:
    int _x;
    int _y;

};

class Computer {
public:
    Computer() {}
    Computer(string brand, int price)
        : _brand(brand), _price(price)
    {}

private:
    string _brand;
    int   _price;

};


int main()
{
    Computer* p1 = Singledog<Computer>::getInstance("Xiaomi", 6666);
    Computer* p2 = Singledog<Computer>::getInstance("apple", 20000);

    printf("addr of p1 = %p\naddr of p2 = %p\n",
           p1, p2);
    return 0;
}
