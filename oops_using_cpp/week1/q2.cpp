#include<iostream>

using namespace std;

int sum()
{
    int ans = 0;
    while(1)
    {
        int n;
        cin>>n;

        if(n == 0)
            break;
        ans += n;
    }
    return ans;
}

int main()
{
    cout<<"Enter the numbers:\n";
    int sm = sum();
    cout<<"Sum of the numbers= "<<sm<<'\n';

    return 0;
}