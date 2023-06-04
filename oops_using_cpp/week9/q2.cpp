#include <iostream>

using namespace std;

class A
{
    int length, breadth;
public:
    void display()
    {
        cout<<"Length = "<<length<<'\n';
    }
    void input()
    {
        cout<<"Enter Length and Breadth respectively:\n";
        cin>>length>>breadth;
    }
    friend class B;
};

class B
{
public:
    void area(A &ob)
    {
        int area = ob.length * ob.breadth;
        cout<<"Area = "<<area<<'\n';
    }
};

int main()
{
    A ob1;
    ob1.input();
    ob1.display();

    B ob2;
    ob2.area(ob1);
    
    return 0;
}