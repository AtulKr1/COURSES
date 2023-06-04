#include<iostream>

using namespace std;

int search(int *arr, int n, int k)
{
    int ans = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==k)
            return 1;
    }
    return -1;
}

int big(int *arr, int n)
{
    int biggest = arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i] > biggest)
            biggest = arr[i];
    }

    return biggest;
}

int main()
{
    int size;
    cout<<"Enter the size of array:\n";
    cin>>size;

    int arr[size];
    cout<<"Enter the array:\n";
    for(int i=0; i<size; i++)
        cin>>arr[i];

    int k;
    cout<<"Enter the key: ";
    cin>>k;

    int found = search(arr, size, k);
    if(found == 1)
        cout<<"Found\n";
    else if(found == -1)
        cout<<"Not Found\n";
    
    cout<<"Greatest number in array: "<<big(arr, size)<<'\n';

    return 0;
}