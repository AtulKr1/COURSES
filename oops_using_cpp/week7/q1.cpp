#include <iostream>
#include <string.h>

using namespace std;

class Student
{
    char name[20];
    int id;

public:
    void get_stud()
    {
        cout<<"Enter the name and id:\n";
        cin>>name>>id;
    }
    void print_stud()
    {
        cout<<"Name: "<<name<<'\n';
        cout<<"ID: "<<id<<'\n';
    }
};

class Sports : virtual public Student
{
public:
    int s_grade;

    void get_sport()
    {
        cout<<"Enter the sports grade: ";
        cin>>s_grade;
    }
    void print_sports()
    {
        cout<<"Sports grade: "<<s_grade<<'\n';
    }
};

class Exam : virtual public Student
{
public:
    int e_grade;

    void get_exam()
    {
        cout<<"Enter the exam grade: ";
        cin>>e_grade;
    }
    void print_exam()
    {
        cout<<"Exam grade: "<<e_grade<<'\n';
    }
};

class Result : public Sports, public Exam
{
    char result[10];

public:
    Result()
    {
        get_stud();
        get_sport();
        get_exam();
        int grade = (s_grade + e_grade)/2;
        if(grade > 5)
            strcpy(result, "GOOD");
        else
            strcpy(result, "BAD");
    }
    void print_result()
    {
        print_stud();
        print_sports();
        print_exam();
        cout<<"Overall Grade is "<<result<<'\n';
    }
};

int main()
{
    Result s1;
    s1.print_result();

    return 0;
}