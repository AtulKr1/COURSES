#include <iostream>

using namespace std;

class IntArr
{
    int arr[20];
    int size;
public:
    IntArr()
    {
        for(int i=0; i<20; i++)
            arr[i] = 0;
        size = 0;
    }
    IntArr(int a[], int m)
    {
        for(int i=0; i<m; i++)
            arr[i] = a[i];
        size = m;
    }
    IntArr(IntArr &cpy)
    {
        for(int i=0; i<cpy.size; i++)
            arr[i] = cpy.arr[i];
        size = cpy.size;
    }
    void search(int k)
    {
        for(int i=0; i<size; i++)
        {
            if(arr[i] == k)
            {
                cout<<"Found at index: "<<i<<'\n';
                return;
            }
        }
        cout<<"Not Found\n";
    }
    static void compare(IntArr &ob1, IntArr &ob2)
    {
        if(ob1.size != ob2.size)
        {
            cout<<"Different\n";
            return;
        }
        for(int i=0; i<ob1.size; i++)
        {
            if(ob1.arr[i] != ob2.arr[i])
            {
                cout<<"Different\n";
                return;
            }
        }
        cout<<"Same\n";
    }
    IntArr operator+(IntArr &ob)
    {
        for(int i=0; i<ob.size; i++)
            arr[i] += ob.arr[i];
        size = ob.size;
        return *this;
    }
    bool operator==(IntArr &ob)
    {
        if(size != ob.size)
            return 0;
        
        for(int i=0; i<size; i++)
        {
            if(arr[i] != ob.arr[i])
                return 0;
        }
        return 1;
    }
    void disp()
    {
        for(int i=0; i<size; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
    }
};

int main()
{
    IntArr ob1;
    int arr[] = {1, 2, 3, 4, 5};
    IntArr ob2(arr, 5);
    IntArr ob3(ob2);

    ob1.disp();
    ob2.disp();
    ob3.disp();

    ob2.search(4);
    IntArr::compare(ob2, ob3);

    ob1 = ob3 + ob2;
    ob1.disp();

    cout<<"Object 1 and 2 are ";
    if(ob1 == ob2)
        cout<<"Same\n";
    else
        cout<<"Different\n";

    return 0;
}