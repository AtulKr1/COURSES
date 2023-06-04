#include <iostream>

using namespace std;

class Shape
{
public:
    double a, b;
    void get_data()
    {
        cout<<"Enter a and b respectively:\n";
        cin>>a>>b;
    }
    virtual void display_area()
    {
        double area = a*b;
        cout<<"Area = "<<area<<'\n';
    }
};

class Triangle : public Shape
{
public:
    void display_area()
    {
        double area = (a*b)/2;
        cout<<"Area of Triangle = "<<area<<'\n';
    }
};

class Rectangle : public Shape
{
public:
    void display_area()
    {
        double area = a*b;
        cout<<"Area of Rectangle = "<<area<<'\n';
    }
};

int main()
{
    Shape *ptr;

    Triangle t;
    ptr = &t;
    ptr->get_data();
    ptr->display_area();

    Rectangle r;
    ptr = &r;
    ptr->get_data();
    ptr->display_area();
    
    return 0;
}