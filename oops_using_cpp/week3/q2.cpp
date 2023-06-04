#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    cout<<"Enter the numbers:\n";
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;

    swap(&a, &b);
    cout<<"After Swap:\n";
    cout<<"a: "<<a<<'\n';
    cout<<"b: "<<b<<'\n';

    return 0;
}