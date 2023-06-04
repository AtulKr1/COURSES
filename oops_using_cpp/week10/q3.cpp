#include <iostream>

using namespace std;

template <class T>
class Operation
{
    T x, y;
public:
    Operation(T a, T b)
    {
        x = a;
        y = b;
    }
    void add()
    {
        cout<<"Add = "<< x + y<<'\n';
    }
    void subtract()
    {
        cout<<"Subtract = "<< x - y<<'\n';
    }
    void multiply()
    {
        cout<<"Multiply = "<< x * y<<'\n';
    }
    void divide()
    {
        cout<<"Divide = "<< x / y<<'\n';
    }
    void disp()
    {
        cout<<"x = "<< x <<"\ty = "<< y<<'\n';
    }
};

int main()
{
    Operation<int> i(25, 5);
    Operation<char> c('K', 'B');
    Operation<double> d(45.23, 12.12);

    cout<<"For INTEGER:\n";
    i.disp();
    i.add();
    i.subtract();
    i.multiply();
    i.divide();

    cout<<"For CHARACTER:\n";
    c.disp();
    c.add();
    c.subtract();
    c.multiply();
    c.divide();

    cout<<"For DOUBLE:\n";
    d.disp();
    d.add();
    d.subtract();
    d.multiply();
    d.divide();

    return 0;
}