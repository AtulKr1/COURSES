#include<iostream>

using namespace std;

void reverse(int *n)
{
    int temp = 0;
    while(*n)
    {
        temp *= 10;
        temp += (*n)%10;
        *n /= 10;
    }
    *n = temp;
}

int sum_dig(int *n)
{
    int sum = 0;
    while(*n)
    {
        sum += (*n)%10;
        *n /= 10;
    }
    
    return sum;
}

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    reverse(&num);
    cout<<"After Reverse: "<<num<<'\n';

    cout<<"Sum of digits = "<<sum_dig(&num)<<'\n';

    return 0;
}