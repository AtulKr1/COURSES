#include<iostream>

using namespace std;

int fibonacci(int);
int fact(int);

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<"Factorial of "<<n<<" = "<<fact(n);
    cout<<"\nFibonacci of "<<n<<":\n";
    for(int i=0; i<n; i++)
    {
        cout<<fibonacci(i)<<' ';
    }

    return 0;
}

int fibonacci(int n)
{
    if(n == 1 || n == 0)
        return n;
    
    return (fibonacci(n-1)+fibonacci(n-2));
}

int fact(int n)
{
    if(n>=1)
        return (n * fact(n-1));
    return 1;
}