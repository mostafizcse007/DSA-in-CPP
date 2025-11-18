#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    string id;
    double cgpa;
    Student(string name, string id, double cgpa)
    {
        this->name = name;
        this->id = id;
        this->cgpa = cgpa;
    }
};
int main()
{
    string name1, id1, name2, id2;
    double cgpa1, cgpa2;
    cout << "Enter first student name, id and cgpa" << endl;
    cin >> name1 >> id1;
    cin >> cgpa1;
    cout << "Enter second student name, id and cgpa" << endl;
    cin >> name2 >> id2;
    cin >> cgpa2;
    Student s1(name1, id1, cgpa1);
    cout << "Name: " << s1.name << " ID: " << s1.id << " CGPA: " << s1.cgpa << endl;
    Student s2(name2, id2, cgpa2);
    cout << "Name: " << s2.name << " ID: " << s2.id << " CGPA: " << s2.cgpa << endl;
    return 0;
}