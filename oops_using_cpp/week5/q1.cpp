#include <iostream>

using namespace std;

class Complex
{
    int a, b;
public:
    Complex()
    {
        a = b = 0;
    }
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    Complex(Complex &c)
    {
        a = c.a;
        b = c.b;
    }
    void assign()
    {
        cout<<"Enter a and b respectively in form a+ib :\n";
        cin>>a>>b;
    }
    void display()
    {
        cout<<"Complex Number = ";
        cout<<a;
        if(b>0)
            cout<<"+i"<<b<<'\n';
        else if(b<0)
            cout<<"-i"<<-1*b<<'\n';
    }
    friend Complex add(Complex, Complex);
    friend Complex subtract(Complex, Complex);
};

Complex add(Complex c1, Complex c2)
{
    Complex ans;
    ans.a = c1.a + c2.a;
    ans.b = c1.b + c2.b;

    return ans;
}

Complex subtract(Complex c1, Complex c2)
{
    Complex ans;
    ans.a = c1.a - c2.a;
    ans.b = c1.b - c2.b;

    return ans;
}

int main()
{
    Complex c1, c2;
    cout<<"Complex 1:\n";
    c1.assign();
    c1.display();

    cout<<"Complex 2:\n";
    c2.assign();
    c2.display();

    Complex sum, diff;
    cout<<"\nSum of C1 and C2\n";
    sum = add(c1, c2);
    sum.display();
    cout<<"\nDifference of C1 and C2\n";
    diff = subtract(c1, c2);
    diff.display();

    Complex c3;
    Complex c4(5, 4);
    Complex c5(c4);
    c3.display();
    c4.display();
    c5.display();

    return 0;
}