#include <iostream>
using namespace std;
class Student
{
public:
    string name, school, district;
    int age;
    Student()
    {
    }
    Student(string s1, string s2, string s3, int a)
    {
        name = s1;
        school = s2;
        district = s3;
        age = a;
    }
};
void print(Student pass)
{
    cout << pass.name << endl;
    cout << pass.school << endl;
    cout << pass.district << endl;
    cout << pass.age;
}
int main()
{
    Student s1("Antu", "Sugar Mills", "Natore", 22);
    print(s1);
}