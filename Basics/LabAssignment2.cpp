#include <bits/stdc++.h>
using namespace std;

class Student // Creating class for its members
{
public:
    string name;
    int id;
    string address;
    float cgpa;
    Student *next;
    Student *prev; // Adding previous pointer for doubly linked list

    Student(string name, int id, string address, float cgpa) // Defining a constructor
    {
        this->name = name;
        this->id = id;
        this->address = address;
        this->cgpa = cgpa;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class StudentLinkedList // Creating class for handling all functions
{
private:
    Student *head;

public:
    StudentLinkedList()
    {
        head = nullptr;
    }

    ~StudentLinkedList() // Destructor to clean up memory
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

    void insert(string name, int id, string address, float cgpa) // Insert at the tail
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
            newStudent->prev = current; // Set the previous pointer
        }
    }

    void deleteStudent(int id) // Deleting a student by ID
    {
        Student *current = head;

        while (current != nullptr && current->id != id)
        {
            current = current->next;
        }

        if (current == nullptr) // Student not found
        {
            return;
        }

        // Update head if necessary
        if (current == head)
        {
            head = current->next;
        }

        // Update the previous and next pointers
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }

        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }

        delete current;
    }

    Student *searchById(int id) // Searching by ID
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

    void searchByCgpa(float cgpa) // Searching by CGPA
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

    void searchByName(string name) // Searching by name
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

    void update(int id, string name = "", string address = "", float cgpa = -1) // Updating a student
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

    void display() // Displaying all students
    {
        Student *current = head;
        if (!current)
        {
            cout << "No students in the list." << endl;
            return;
        }

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

        switch (choice)
        {
        case 1:
        {
            string name, address;
            int id;
            float cgpa;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student address: ";
            cin >> address;
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
            cin >> nameToSearch;
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
            cout << "Enter new name (or press Enter to keep current): ";
            cin >> newName;
            cout << "Enter new address (or press Enter to keep current): ";
            cin >> newAddress;
            cout << "Enter new CGPA (or -1 to keep the current one): ";
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
            cout << "Developed by Md. Mostafizur Rahman Antu\n"
                 << "ID: 241-15-631\n";
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
