#include <bits/stdc++.h>
using namespace std;
struct Student
{
public:
    string name;
    string id;
    double cgpa;
    Student *next;
    Student(string name, string id, double cgpa)
    {
        this->name = name;
        this->id = id;
        this->cgpa = cgpa;
        next = NULL;
    }
};
void Display(Student *head)
{
    Student *temp = head;
    while (temp != NULL)
    {
        cout << temp->name << " " << temp->id << " " << temp->cgpa << " ->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Student *insertTail(Student *&head, string name, string id, double cgpa)
{
    Student *newNode = new Student(name, id, cgpa);
    if (head == NULL)
        return newNode;
    else
    {
        Student *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
int main()
{
    Student *head = NULL;
    head = insertTail(head, "Antu", "241-15-631", 4.00);
    head = insertTail(head, "Shanito", "214-15-854", 4.00);
    head = insertTail(head, "Sinha", "241-15-565", 4.00);
    head = insertTail(head, "Wali", "214-15-655", 4.00);
    Display(head);
    return 0;
}