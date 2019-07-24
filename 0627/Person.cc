#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Person
{
public:
    Person(const string name,int age)
    :_name(name)
    ,_age(age)
    {}

    void display()
    {
        cout << "name:" << _name <<endl
             << "age:" << _age <<endl;
    }
private:
    string _name;
    int _age;
};

class Employee
:public Person
{
public:
    
    Employee(const string name,const int age,const string depatrment,const double salary )
    :Person(name,age)
    ,_department(depatrment)
    ,_salary(salary)
    {}
    void display()
    {
        Person::display();
        cout << "depatrment:" << _department << endl
             << "salary:" << _salary << endl;
    }
    double getSalary()
    {
        return _salary;
    }
private:
    string _department;
    double _salary;

};

int main(void)
{
   
    Employee e1("niny",18,"HR",10);
    Employee e2("ning",18,"Art",22);
    Employee e3("yy",18,"ii",230);
    e1.display();
    e2.display();
    e3.display();

    double ave;
    ave = (e1.getSalary()+e2.getSalary()+e3.getSalary())/3;
    cout << "平均工资：" << ave << endl;
    return 0;

}

