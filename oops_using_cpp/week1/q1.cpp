#include<iostream>

using namespace std;

int factorial(int num)
{
    int ans = 1;
    while(num)
    {
        ans *= num;
        num--;
    }

    return ans;
}

int main()
{
    cout<<"Enter the number to find the factorial: ";
    int num;
    cin>>num;

    cout<<"Factorial of number= "<<factorial(num)<<'\n';
    return 0;
}