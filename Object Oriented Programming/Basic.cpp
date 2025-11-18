#include <iostream>
using namespace std;
class Student
{
public:
    string name, location, blood_group;
    int age, marks;
    double height, cgpa;
};
int main()
{
    Student s1;
    getline(cin, s1.name);
    cin >> s1.location >> s1.blood_group >> s1.age >> s1.marks >> s1.height >> s1.cgpa;
    cout << "Name: " << s1.name << endl
         << "Hometown: " << s1.location << endl
         << "Blood Group: " << s1.blood_group << endl
         << "Age: " << s1.age << endl
         << "Total Marks: " << s1.marks << endl
         << "Height: " << s1.height << endl
         << "Total CGPA: " << s1.cgpa << endl;
    return 0;
}