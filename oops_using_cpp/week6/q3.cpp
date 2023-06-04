#include <iostream>
#include <string.h>

using namespace std;

class Bank
{
    char name[20];
    int acn_no;
    char acn_type[10];
    float amount;
    static int rate;
public:
    Bank()
    {
        strcpy(name, "NA");
        acn_no = 0;
        strcpy(acn_type, "NA");
        amount = 0;
    }
    Bank(char str[], int no, char type[], float amt)
    {
        strcpy(name, str);
        acn_no = no;
        strcpy(acn_type, type);
        amount = amt;
    }
    Bank(Bank &b)
    {
        strcpy(name, b.name);
        acn_no = b.acn_no;
        strcpy(acn_type, b.acn_type);
        amount = b.amount;
    }
    void deposit()
    {
        cout<<"Enter the amount to deposit: ";
        float temp;
        cin>>temp;
        amount += temp;
    }
    void disp_amt()
    {
        float min_amt = 5000;
        if(amount >= min_amt)
            cout<<"OK "<<amount<<'\n';
        else
            cout<<"Not OK 5000 required\n";
    }
    void disp_all()
    {
        cout<<"All details:";
        cout<<"\nName: "<<name;
        cout<<"\nAccount Number: "<<acn_no;
        cout<<"\nAccount Type: "<<acn_type;
        cout<<"\nAccount Balance: "<<amount;
    }
    static void disp_rate()
    {
        cout<<"Rate: "<<rate<<'\n';
    }
    ~Bank()
    {
        cout<<"\nAccount Removed.";
    }
};

int Bank::rate = 9;
int main()
{
    Bank a1;
    char name[] = "Sam", type[] = "Saving";
    Bank a2(name, 1, type, 7000);
    Bank a3(a2);

    Bank::disp_rate();
    a1.deposit();
    a1.disp_amt();
    a3.disp_all();

    return 0;
}