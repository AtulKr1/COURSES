#include<iostream>

using namespace std;

struct Rectangle
{
    float length, breadth;
};

void input(Rectangle *r)
{
    cout<<"Enter the length: ";
    cin>> r->length;
    cout<<"Enter the breadth: ";
    cin>> r->breadth;
}

void display_dimensions(Rectangle *r)
{
    cout<<"\nLength = "<< r->length;
    cout<<"\nBreadth = "<< r->breadth;
}

void display_area(Rectangle *r)
{
    float area = r->length * r->breadth;
    cout<<"\nArea = "<< area <<'\n';
}

int main()
{
    Rectangle r;
    input(&r);
    display_dimensions(&r);
    display_area(&r);

    return 0;
}