#include <iostream>

using namespace std;

class B;

class A
{
    int a;
public:
    A()
    {
        a = 10;
    }
    friend void add(A &, B &);
};

class B
{
    int b;
public:
    B()
    {
        b = 20;
    }
    friend void add(A &, B &);
};

void add(A &ob1, B &ob2)
{
    cout<<"Sum = "<<ob1.a + ob2.b<<'\n';
}

int main()
{
    A ob1;
    B ob2;

    add(ob1, ob2);

    return 0;
}