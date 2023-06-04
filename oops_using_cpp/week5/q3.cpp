#include <iostream>

using namespace std;

class Rectangle;

class Circle
{
    float r, a;

public:
    void input()
    {
        cout << "Enter the radius of Circle:\n";
        cin >> r;
        area();
    }
    void display()
    {
        cout << "For Circle:\n";
        cout << "Radius= " << r << '\n';
        cout << "Area= " << a <<'\n';
    }
    void area()
    {
        a = 3.141 * r * r;
    }
    friend void compare(Rectangle, Circle);
};

class Rectangle
{
    float l, b, a;

public:
    void input()
    {
        cout << "Enter the dimensions of Rectangle:\n";
        cin >> l >> b;
        area();
    }
    void display()
    {
        cout << "For Rectangle:\n";
        cout << "Length= " << l << ", Breadth= " << b << '\n';
        cout << "Area= " << a<<'\n';
    }
    void area()
    {
        a = l * b;
    }
    friend void compare(Rectangle, Circle);
};

void compare(Rectangle rec, Circle c)
{
    cout << "Area of ";
    if (rec.a > c.a)
        cout << "Rectangle is greater\n";
    else if (rec.a < c.a)
        cout << "Circle is greater\n";
    else
        cout << "Both are same\n";
}

int main()
{
    Circle c;
    Rectangle rec;
    c.input();
    rec.input();
    c.display();
    rec.display();
    compare(rec, c);
    return 0;
}