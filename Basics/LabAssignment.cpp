#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int id;
    string address;
    float cgpa;
    Student *next;

    Student(string name, int id, string address, float cgpa)
    {
        this->name = name;
        this->id = id;
        this->address = address;
        this->cgpa = cgpa;
        this->next = nullptr;
    }
};

class StudentLinkedList
{
private:
    Student *head;

public:
    StudentLinkedList()
    {
        head = nullptr;
    }

    ~StudentLinkedList()
    {
        Student *current = head;
        while (current != nullptr)
        {
            Student *nextStudent = current->next;
            delete current;
            current = nextStudent;
        }
        head = nullptr;
    }

    void insert(string name, int id, string address, float cgpa)
    {
        Student *newStudent = new Student(name, id, address, cgpa);
        if (!head)
        {
            head = newStudent;
        }
        else
        {
            Student *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    void deleteStudent(int id)
    {
        Student *current = head;
        Student *previous = nullptr;

        if (current != nullptr && current->id == id)
        {
            head = current->next;
            delete current;
            return;
        }

        while (current != nullptr && current->id != id)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
            return;

        previous->next = current->next;
        delete current;
    }

    Student *searchById(int id)
    {
        Student *current = head;
        while (current)
        {
            if (current->id == id)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void searchByCgpa(float cgpa)
    {
        Student *current = head;
        bool found = false;
        while (current)
        {
            if (current->cgpa == cgpa)
            {
                cout << "Found student: " << current->name << ", ID: " << current->id << ", Address: " << current->address << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found)
        {
            cout << "No students found with CGPA " << cgpa << endl;
        }
    }

    void searchByName(string name)
    {
        Student *current = head;
        bool found = false;
        while (current)
        {
            if (current->name == name)
            {
                cout << "Found student: " << current->name << ", ID: " << current->id << ", Address: " << current->address << ", CGPA: " << current->cgpa << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found)
        {
            cout << "No students found with name " << name << endl;
        }
    }

    void update(int id, string name = "", string address = "", float cgpa = -1)
    {
        Student *current = searchById(id);
        if (current)
        {
            if (!name.empty())
                current->name = name;
            if (!address.empty())
                current->address = address;
            if (cgpa != -1)
                current->cgpa = cgpa;
            cout << "Student with ID " << id << " updated successfully." << endl;
        }
        else
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void display()
    {
        Student *current = head;
        if (!current)
        {
            cout << "No students in the list." << endl;
            return;
        }

        cout << "--- Student List ---" << endl;
        while (current)
        {
            cout << "Name: " << current->name << ", ID: " << current->id << ", Address: " << current->address << ", CGPA: " << current->cgpa << endl;
            current = current->next;
        }
    }
};

int main()
{
    StudentLinkedList list;
    int choice;

    do
    {
        cout << "\n--- Student Linked List Menu ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Search Student by CGPA\n";
        cout << "4. Search Student by Name\n";
        cout << "5. Update Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Display All Students\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name, address;
            int id;
            float cgpa;
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter student address: ";
            getline(cin, address);
            cout << "Enter student CGPA: ";
            cin >> cgpa;
            list.insert(name, id, address, cgpa);
            break;
        }
        case 2:
        {
            int idToSearch;
            cout << "Enter student ID to search: ";
            cin >> idToSearch;
            Student *student = list.searchById(idToSearch);
            if (student)
            {
                cout << "Student with ID " << idToSearch << " found: Name - " << student->name << ", Address - " << student->address << ", CGPA - " << student->cgpa << endl;
            }
            else
            {
                cout << "Student with ID " << idToSearch << " not found." << endl;
            }
            break;
        }
        case 3:
        {
            float cgpaToSearch;
            cout << "Enter CGPA to search: ";
            cin >> cgpaToSearch;
            list.searchByCgpa(cgpaToSearch);
            break;
        }
        case 4:
        {
            string nameToSearch;
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, nameToSearch);
            list.searchByName(nameToSearch);
            break;
        }
        case 5:
        {
            int idToUpdate;
            string newName, newAddress;
            float newCgpa;
            cout << "Enter student ID to update: ";
            cin >> idToUpdate;
            cin.ignore();
            cout << "Enter new name (or press Enter to keep current): ";
            getline(cin, newName);
            cout << "Enter new address (or press Enter to keep current): ";
            getline(cin, newAddress);
            cout << "Enter new CGPA (or -1 to keep current): ";
            cin >> newCgpa;
            list.update(idToUpdate, newName, newAddress, newCgpa);
            break;
        }
        case 6:
        {
            int idToDelete;
            cout << "Enter student ID to delete: ";
            cin >> idToDelete;
            list.deleteStudent(idToDelete);
            break;
        }
        case 7:
        {
            list.display();
            break;
        }
        case 8:
        {
            cout << "Exiting program." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        }
    } while (choice != 8);

    return 0;
}
