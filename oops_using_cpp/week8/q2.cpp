#include <iostream>
#include <string.h>

using namespace std;

class String
{
    char *ptr;

public:
    String()
    {
        ptr = NULL;
    }
    String(char *p)
    {
        ptr = new char[strlen(p) + 1];
        int i = 0;
        do
        {
            ptr[i] = p[i];
            i++;
        } while (p[i] != '\0');
    }
    String(String const &ob)
    {
        ptr = new char[strlen(ob.ptr) + 1];
        int i = 0;
        do
        {
            ptr[i] = ob.ptr[i];
            i++;
        } while (ob.ptr[i] != '\0');
    }
    String const operator+(String const &ob)
    {
        int n1 = strlen(ptr);
        int n2 = strlen(ob.ptr);
        int size = n1 + n2;

        String c;
        c.ptr = new char[size + 1];

        for (int i = 0; i < n1; i++)
            c.ptr[i] = ptr[i];
        for (int i = n1; i - n1 < n2; i++)
            c.ptr[i] = ob.ptr[i - n1];
        c.ptr[size] = '\0';

        return c;
    }
    void display()
    {
        cout << "String: " << ptr << '\n';
    }
    void change_case()
    {
        int x = 'a' - 'A';

        int i = 0;
        while (ptr[i] != '\0')
        {
            if (ptr[i] >= 'A' && ptr[i] <= 'Z')
                ptr[i] += x;
            else
                ptr[i] -= x;
            i++;
        }
    }
    void reverse()
    {
        int n = strlen(ptr);
        char temp;
        for (int i = 0; i < n / 2; i++)
        {
            temp = ptr[i];
            ptr[i] = ptr[n - i - 1];
            ptr[n - i - 1] = temp;
        }
    }
    char operator[](int x)
    {
        return ptr[x];
    }
    friend ostream &operator<<(ostream &output, String const &s)
    {
        output << s.ptr;
        return output;
    }
    friend istream &operator>>(istream &input, String const &s)
    {
        input >> s.ptr;
        return input;
    }
    ~String()
    {
        delete[] ptr;
    }
};

int main()
{
    char c[] = "ApplE";

    String ob2(c);
    String ob3(ob2);
    String ob1(ob2 + ob3);

    ob1.display();
    ob2.display();
    ob3.display();

    ob1.change_case();
    ob1.display();

    ob2.reverse();
    ob2.display();

    cout << "ob1[4] : " << ob1[4] << '\n';
    cout << "Enter new string:\n";
    cin >> ob3;
    cout << ob3 << '\n';

    return 0;
}