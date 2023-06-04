#include <iostream>

using namespace std;

class Time
{
    int hh, mm, ss;
public:
    Time()
    {
        hh = 0;
        mm = 0;
        ss = 0;
    }
    Time(int h, int m, int s)
    {
        hh = h;
        mm = m;
        ss = s;
    }
    Time(Time &cpy)
    {
        hh = cpy.hh;
        mm = cpy.mm;
        ss = cpy.ss;
    }
    void assign()
    {
        cout<<"Enter the time in Hours, Minuters & Seconds respectively:\n";
        cin>>hh>>mm>>ss;
    }
    void display()
    {
        cout<<"Time: ";
        cout<<hh%24<<":"<<mm<<":"<<ss<<'\n';
    }
    friend Time add(Time, Time);
    friend Time subtract(Time, Time);
    friend void compare(Time, Time);
};

Time add(Time t1, Time t2)
{
    int sec = t1.hh*(60*60)+t1.mm*(60)+t1.ss;
    sec += t2.hh*(60*60)+t2.mm*(60)+t2.ss;

    Time ans;
    ans.hh = sec/(60*60);
    sec %= (60*60);
    ans.mm = sec/60;
    sec %= 60;
    ans.ss = sec;

    return ans;
}

Time subtract(Time t1, Time t2)
{
    int sec1 = t1.hh*(60*60)+t1.mm*(60)+t1.ss;
    int sec2 = t2.hh*(60*60)+t2.mm*(60)+t2.ss;

    if(sec1 < sec2)
        sec1 += 24*60*60;
    int sec = sec1 - sec2;

    Time ans;
    ans.hh = sec/(60*60);
    sec %= (60*60);
    ans.mm = sec/60;
    sec %= 60;
    ans.ss = sec;

    return ans;
}

void compare(Time t1, Time t2)
{
    int sec1 = t1.hh*(60*60)+t1.mm*(60)+t1.ss;
    int sec2 = t2.hh*(60*60)+t2.mm*(60)+t2.ss;

    if(sec1 > sec2)
        cout<<"Time 1 is greater\n";
    else if(sec1 < sec2)
        cout<<"Time 2 is greater\n";
    else
        cout<<"Both Times are equal\n";
}

int main()
{
    Time t1, t2;
    t1.assign();
    t2.assign();

    Time sum;
    cout<<"Sum:\n";
    sum = add(t1, t2);
    sum.display();
    Time diff;
    cout<<"Difference:\n";
    diff = subtract(t1, t2);
    diff.display();
    compare(t1, t2);

    Time t3;
    Time t4(4, 5, 6);
    Time t5(t4);
    t3.display();
    t4.display();
    t5.display();

    return 0;
}