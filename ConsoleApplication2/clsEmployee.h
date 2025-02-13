#pragma once
#include <iostream>
class clsEmployee : public clsPerson {


    string _Title;
    string _Department;
    int _Salary;


public:

    clsEmployee(short unsigned ID, string FirstName, string LastName, string Email, string PhoneNumber, string Title, string Department, int Salary)
        :clsPerson(ID, FirstName, LastName, Email, PhoneNumber) {

        _Salary = Salary;
        _Department = Department;
        _Title = Title;
    }




    void setTitle(string Title) {
        _Title = Title;
    }
    string Title() {
        return _Title;
    }

    void setDepartment(string Department) {
        _Department = Department;
    }
    string Department() {
        return _Department;
    }
    void setSalary(int Salary) {
        _Salary = Salary;
    }
    int Salary() {
        return _Salary;
    }
    void Print()
    {
        cout << "Info : \n";
        cout << "-----------------------\n";
        cout << "ID         :" << ID() << endl;
        cout << "First Name :" << FirstName() << endl;
        cout << "Last Name  :" << LastName() << endl;
        cout << "Full Name  :" << FullName() << endl;
        cout << "Email      :" << _Email << endl;
        cout << "Phone      :" << PhoneNumber() << endl;
        cout << "Title      :" << _Title << endl;
        cout << "Department :" << _Department << endl;
        cout << "Salary     :" << _Salary << endl;
        cout << "-----------------------\n\n";
    }






};
