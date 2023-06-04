#include<iostream>

using namespace std;

void reverse(char *str)
{
    int size = 0;
    while(*(str+size) != '\0')
        size++;
    
    cout<<"Size of string = "<<size<<'\n';
    for(int i=0; i<size/2; i++)
    {
        char temp = *(str+i);
        *(str+i) = *(str+size-i-1);
        *(str+size-i-1) = temp;
    }
}

int main()
{
    char str[20];
    cout<<"Enter the string: ";
    cin>>str;

    reverse(str);
    cout<<"After reverse: "<<str<<'\n';

    return 0;
}