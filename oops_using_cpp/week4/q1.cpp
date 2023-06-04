#include <iostream>
#define pi 3.141

using namespace std;

inline void tri_area(float height, float base)
{
    cout<<"Area of triangle = "<<(height*base)/2<<'\n';
}

inline void cir_area(float r)
{
    cout<<"Area of circle = "<<pi*r*r<<'\n';
}

int main()
{
    int h, b;
    cout<<"Enter the height and base of triangle:\n";
    cin>>h>>b;

    tri_area(h, b);

    int r;
    cout<<"Enter the radius of circle:\n";
    cin>>r;

    cir_area(r);

    return 0;
}