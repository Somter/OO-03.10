// OO 03.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//#include<iostream>
#include <iostream> 
#include <string>   
using namespace std;    

class Person
{
protected:
    char* name;
    int age;
public:
    Person() = default;
    Person(const char* n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    const char* GetName() const
    {
        return name;
    }

    void SetName(const char* n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    int GetAge() const
    {
        return age;
    }

    void SetAge(int a)
    {
        age = a;
    }

    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void Input()
    {
        char buff[20];
        cin.getline(buff, 20);
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
    }

    ~Person()
    {
        delete[] name;
    }
};

class Student : public Person
{
    char* university;
public:
    Student() = default;
    Student(const char* n, int a, const char* Univer) : Person(n, a)
    {
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);
    }

    const char* GetUniversity() const
    {
        return university;
    }

    void SetUniversity(const char* Univer)
    {
        delete[] university;
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);
    }

    void Input(const char* Univer)
    {
        delete[] university;
        university = new char[strlen(Univer) + 1];
        strcpy_s(university, strlen(Univer) + 1, Univer);
        Person::Input();
    }

    void Print()
    {
        Person::Print();
        cout << "University: " << university << endl;
    }

    ~Student()
    {
        delete[] university;
    }
};

class Teacher : public Person
{
    string school;
    string items[6];
    double salary;
public:
    Teacher() = default;
    Teacher(const char* n, int a, string sch, double sal) : Person(n, a)
    {
        school = sch;
        salary = sal;
        items[0] = "Physics";
        items[1] = "Algebra";
        items[2] = "Geometry";
        items[3] = "Chemistry";
        items[4] = "Computer science";
        items[5] = "Driver wifia";
    }

    string GetSchool() const
    {
        return school;
    }

    void SetSchool(string sch)
    {
        school = sch;
    }

    double GetSalary() const
    {
        return salary;
    }

    void SetSalary(double sal)
    {
        salary = sal;
    }

    string GetItem(int index) const
    {
        if (index >= 0 && index < 6)
        {
            return items[index];
        }
        else
        {
            return "";
        }
    }

    void SetItem(int index, string item)
    {
        if (index >= 0 && index < 6)
        {
            items[index] = item;
        }
    }

    void Print()
    {
        Person::Print();
        cout << "School: " << school << endl;
        cout << "Salary: " << salary << "$" << endl;
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << " item: ";
            cout << items[i] << '\n';
        }
    }
};

class Driver : public Person
{
    int CarNumber;
    string Series;
    string IdDriverslicense;
public:
    Driver() = default;
    Driver(const char* n, int a, int cn, string ser, string id) : Person(n, a)
    {
        CarNumber = cn;
        Series = ser;
        IdDriverslicense = id;
    }

    int GetCarNumber() const
    {
        return CarNumber;
    }

    void SetCarNumber(int cn)
    {
        CarNumber = cn;
    }

    string GetSeries() const
    {
        return Series;
    }

    void SetSeries(string ser)
    {
        Series = ser;
    }

    string GetIdDriverslicense() const
    {
        return IdDriverslicense;
    }

    void SetIdDriverslicense(string id)
    {
        IdDriverslicense = id;
    }

    void Print()
    {
        Person::Print();
        cout << "Car number: " << CarNumber << endl;
        cout << "series: " << Series << endl;
        cout << "Id: " << IdDriverslicense << endl;
    }
};

class Doctor : public Person
{
    string speciality;
    int experience;
    bool FamilyDoctor;
public:
    Doctor() = default;
    Doctor(const char* n, int a, string sp, int exp, bool f) : Person(n, a)
    {
        speciality = sp;
        experience = exp;
        FamilyDoctor = f;
    }

    string GetSpeciality() const
    {
        return speciality;
    }

    void SetSpeciality(string sp)
    {
        speciality = sp;
    }

    int GetExperience() const
    {
        return experience;
    }

    void SetExperience(int exp)
    {
        experience = exp;
    }

    bool IsFamilyDoctor() const
    {
        return FamilyDoctor;
    }

    void SetFamilyDoctor(bool f)
    {
        FamilyDoctor = f;
    }

    void Print()
    {
        Person::Print();
        cout << "Speciality: " << speciality << endl;
        cout << "Experience: " << experience << endl;
        if (FamilyDoctor) {
            cout << "He's a family doctor" << endl;
        }
        else {
            cout << "He isn't a family doctor" << endl;
        }
    }
};

int main()
{
    cout << "1) Person Student: " << endl;
    Student objS("Irina", 18, "ITStep");
    objS.Print();

    cout << "\n";
    cout << "2) Person Teacher: " << endl;
    Teacher objT("Elon", 5, "#85", 1000.50);
    objT.Print();

    cout << '\n';
    cout << "3) Person Driver: " << endl;
    Driver objD("Elon", 7, 7777, "BH 7777 BH", "AB123456");
    objD.Print();

    cout << '\n';
    cout << "4) Person Doctor: " << endl;
    Doctor objDr("Elon", 30, "Neurosurgeon", 25, true);
    objDr.Print();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
