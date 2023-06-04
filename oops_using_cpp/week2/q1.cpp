#include<iostream>

using namespace std;

struct Student
{
    int id;
    char name[20];
    float cgpa;
};

void input(Student *s)
{
    cout<<"\nEnter the student details:\n";
    cout<<"ID: ";
    cin >> s->id;
    cout<<"Name: ";
    cin >> s->name;
    cout<<"CGPA: ";
    cin >> s->cgpa;
}

void display(Student *s)
{
    cout<<"\nStudent ID: "<< s->id;
    cout<<"\nStudent Name: "<<s->name;
    cout<<"\nStudent CGPA: "<< s->cgpa;
}

void edit(Student *s)
{
    cout<<"\nEnter the new student details:\n";
    cout<<"ID: ";
    cin >> s->id;
    cout<<"Name: ";
    cin >> s->name;
    cout<<"CGPA: ";
    cin >> s->cgpa;
}

int main()
{
    Student s, *ptr;
    ptr = &s;

    input(ptr);
    display(ptr);
    edit(ptr);
    display(ptr);

    return 0;
}