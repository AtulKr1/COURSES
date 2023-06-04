#include<iostream>

using namespace std;

inline bool is_prime(int n)
{
    if(n == 1)
        return 0;
    
    for(int i=2; i<=n/2; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    cout<<"Enter the number: ";
    int n;
    cin>>n;

    if(is_prime(n))
        cout<<"Number is prime.";
    else
        cout<<"Number is not prime.";

    return 0;
}