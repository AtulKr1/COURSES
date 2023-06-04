#include <iostream>

using namespace std;

template <class T> void largest(T x, T y)
{
    if(x > y)
        cout<<x<<" > "<<y<<'\n';
    else if(x < y)
        cout<<x<<" < "<<y<<'\n';
    else
        cout<<x<<" = "<<y<<'\n';
}

int main()
{
    largest(6.4, 7.2);
    largest(3, 2);
    largest('a', 'd');
    
    return 0;
}