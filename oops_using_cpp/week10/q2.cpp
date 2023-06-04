#include <iostream>

using namespace std;

template <class T> void swapping(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int i1 = 6, i2 = 7;
    double d1 = 11.4, d2 = 42.33;
    char c1 = 'c', c2 = 'k';

    cout<<"Before swapping:\n";
    cout<<"i1 = "<<i1<<"\ti2 = "<<i2<<'\n';
    cout<<"d1 = "<<d1<<"\td2 = "<<d2<<'\n';
    cout<<"c1 = "<<c1<<"\tc2 = "<<c2<<'\n';

    swapping(i1, i2);
    swapping(d1, d2);
    swapping(c1, c2);

    cout<<"After swapping:\n";
    cout<<"i1 = "<<i1<<"\ti2 = "<<i2<<'\n';
    cout<<"d1 = "<<d1<<"\td2 = "<<d2<<'\n';
    cout<<"c1 = "<<c1<<"\tc2 = "<<c2<<'\n';
    
    return 0;
}