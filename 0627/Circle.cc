#include <iostream>
using std::cout;
using std::endl;

#define PI 3.14159
class Circle
{
public:
    Circle()
    :_radius(0)
    {}
    Circle(double r)
    :_radius(r)
    {}

    double getArea()
    {
        return PI*_radius*_radius;
    }

    double getPerimeter()
    {
        return 2*PI*_radius;
    }

    void show()
    {
        cout << "半径：" << _radius << endl
             << "周长：" << getPerimeter() << endl
             << "面积：" << getArea() << endl;
    }

private:
    double _radius;
}

class Cylinder
:public Circle
{
public:
    Cylinder (double r, double  h)
    :Circle(r)
    ,_high(h)
    {}

    double getVolume()
    {
        return getArea()*_high;
    }

    void showVolume()
    {
        cout <<"圆柱体体积：" <<  getVolume() << endl;
    }
private:
    double _high;
}

int main(void)
{
   
    return 0;
}

