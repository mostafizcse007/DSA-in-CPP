#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string stID, stName, stAge, stBlood, stEmail, stGender, stAdress, stGrade, stPass;
    int subNo;
    double totalAvg;
    vector<double> subMarks;
    Student *next;
    Student(string id, string name, string pass, string blood, string email, string gender, string address, int number)
    {
        stID = id;
        stName = name;
        stPass = pass;
        stBlood = blood;
        stEmail = email;
        stGender = gender;
        stAdress = address;
        subNo = number;
        next = nullptr;
        calculateAvg();
        calculateGrade();
    }
    void calculateAvg()
    {
        if (subNo <= 0)
        {
            cout << "At least 1 subject needs to be enrolled." << endl;
            return;
        }

        subMarks.clear();
        double sum = 0;

        for (int i = 0; i < subNo; i++)
        {
            double temp;
            do
            {
                cout << "Enter marks for subject " << i + 1 << " (0 to 100): ";
                cin >> temp;

                if (temp < 0 || temp > 100)
                    cout << "Invalid marks. Please enter a value between 0 and 100." << endl;

            } while (temp < 0 || temp > 100);

            subMarks.push_back(temp);
            sum += temp;
        }

        totalAvg = sum / subNo;
    }

    void calculateGrade()
    {
        if (totalAvg >= 80)
            stGrade = "A+";
        else if (totalAvg >= 70)
            stGrade = "A";
        else if (totalAvg >= 65)
            stGrade = "A-";
        if (totalAvg >= 60)
            stGrade = "B";
        else
            stGrade = "B-";
    }
    void PrintStudent()
    {
        cout << "Student ID: " << stID << endl;
        cout << "Student Name: " << stName << endl;
        cout << "Student Blood Group: " << stBlood << endl;
        cout << "Student Email Address: " << stEmail << endl;
        cout << "Gender: " << stGender << endl;
        cout << "Home Address: " << stAdress << endl;
        cout << "Number of course taken: " << subNo << endl;
        cout << "Total average: " << totalAvg << endl;
        cout << "Grade: " << stGrade << endl;
    }
    string toString()
    {
        ostringstream ss;
        ss << stID << "," << stName << "," << stPass << "," << stBlood << ","
           << stEmail << "," << stGender << "," << stAdress << "," << subNo << ","
           << totalAvg << "," << stGrade << "\n";
        for (double mark : subMarks)
            ss << mark << " ";
        ss << "\n";
        return ss.str();
    }
    static Student fromString(const string &line, const string &marksLine)
    {
        istringstream ss(line), marksSS(marksLine);
        string id, name, pass, blood, email, gender, address, grade;
        int number;
        double avg;
        vector<double> marks;

        ss >> id >> name >> pass >> blood >> email >> gender >> address >> number >> avg >> grade;
        Student student(id, name, pass, blood, email, gender, address, number);
        student.totalAvg = avg;
        student.stGrade = grade;

        for (int i = 0; i < number; ++i)
        {
            double mark;
            marksSS >> mark;
            student.subMarks.push_back(mark);
        }
        return student;
    }
};
class Management
{
public:
    Student *head;
    const string fileName = "students.txt";
    const string deletedFile = "deleted_students.txt";
    Management()
    {
        head = nullptr;
    }
    ~Management()
    {
        saveToFile();
        clearMemory();
    }
    Student *findID(string id)
    {
        Student *temp = head;
        while (temp)
        {
            if (temp->stID == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    Student *findEmail(string email)
    {
        Student *temp = head;
        while (temp)
        {
            if (temp->stEmail == email)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    Student *findName(string name)
    {
        Student *temp = head;
        while (temp)
        {
            if (temp->stName == name)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    vector<Student *> convertListToVector()
    {
        vector<Student *> studentVector;
        Student *temp = head;
        while (temp)
        {
            studentVector.push_back(temp);
            temp = temp->next;
        }
        return studentVector;
    }
    void sortStudentsByAverage()
    {
        vector<Student *> studentVector = convertListToVector();

        sort(studentVector.begin(), studentVector.end(), [](Student *a, Student *b)
             { return a->totalAvg > b->totalAvg; });

        head = nullptr;
        for (auto student : studentVector)
        {
            student->next = head;
            head = student;
        }
        cout << "Students sorted by their average marks." << endl;
    }
    void addStudent(string id, string name, string pass, string blood, string email, string gender, string address, int number)
    {
        Student *temp1 = findID(id);
        Student *temp2 = findEmail(email);
        if (temp1 != nullptr)
        {
            cout << "Student with ID: " << id << " already present in our system." << endl;
            return;
        }
        if (temp2 != nullptr)
        {
            cout << "Student with Email: " << email << " already present in our system." << endl;
            return;
        }
        Student *newStudent = new Student(id, name, pass, blood, email, gender, address, number);
        newStudent->next = head;
        head = newStudent;
        cout << "Student information added successfully." << endl;
    }
    void removeStudent(string id)
    {
        if (!head)
        {
            cout << "The student list is empty. No student to remove." << endl;
            return;
        }
        Student *temp = findID(id);
        if (temp == nullptr)
        {
            cout << "Student with ID: " << id << " is not found in our system." << endl;
            return;
        }
        if (head->stID == id)
        {
            Student *dummy = head;
            head = head->next;
            delete dummy;
            cout << "Student with ID: " << id << " deleted successfully from our system." << endl;
            return;
        }
        Student *curr = head;
        Student *prev = nullptr;
        while (curr && curr->stID != id)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Student with ID: " << id << " deleted successfully from our system." << endl;
    }
    void restoreDeletedStudent()
    {
        ifstream file(deletedFile);
        if (!file.is_open())
        {
            cout << "No deleted students to restore." << endl;
            return;
        }
        string line, marksLine;
        while (getline(file, line) && getline(file, marksLine))
        {
            Student restored = Student::fromString(line, marksLine);
            addStudent(restored.stID, restored.stName, restored.stPass, restored.stBlood, restored.stEmail, restored.stGender, restored.stAdress, restored.subNo);
        }
        file.close();
        ofstream clearFile(deletedFile, ios::trunc);
        clearFile.close();
        cout << "Deleted students restored successfully." << endl;
    }
    int totalStudent()
    {
        Student *temp = head;
        int cnt = 0;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    void saveToFile()
    {
        ofstream file(fileName, ios::trunc);
        Student *curr = head;
        while (curr)
        {
            file << curr->toString();
            curr = curr->next;
        }
        file.close();
    }
    void loadFromFile()
    {
        ifstream file(fileName);
        if (!file.is_open())
            return;
        string line, marksLine;
        while (getline(file, line) && getline(file, marksLine))
        {
            Student s = Student::fromString(line, marksLine);
            addStudent(s.stID, s.stName, s.stPass, s.stBlood, s.stEmail, s.stGender, s.stAdress, s.subNo);
        }
        file.close();
    }
    void saveDeletedStudent(Student *student)
    {
        ofstream file(deletedFile, ios::app);
        file << student->toString();
        file.close();
    }
    void modifyStudent(string id, string newid, string name, string blood, string email, string gender, string address, int number)
    {
        Student *temp = findID(id);
        if (temp == nullptr)
        {
            cout << "Student with ID: " << id << " is not found in our system." << endl;
            return;
        }
        temp->stID = newid;
        temp->stName = name;
        temp->stBlood = blood;
        temp->stEmail = email;
        temp->stGender = gender;
        temp->stAdress = address;
        temp->subNo = number;
        temp->calculateAvg();
        temp->calculateGrade();
        cout << "All information modified successfully." << endl;
    }
    void searchByID(string id)
    {
        Student *temp = findID(id);
        if (temp == nullptr)
        {
            cout << "Student with ID: " << id << " not found in our system." << endl;
            return;
        }
        temp->PrintStudent();
    }
    void searchByName(string name)
    {
        Student *temp = head;
        bool found = false;

        while (temp)
        {
            if (temp->stName == name)
            {
                found = true;
                temp->PrintStudent();
                cout << "------------------------" << endl;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "No student with the name '" << name << "' found in the system." << endl;
        }
    }
    void searchByEmail(string email)
    {
        Student *temp = findEmail(email);
        if (temp == nullptr)
        {
            cout << "Student with Email: " << email << " not found in our system." << endl;
            return;
        }
        temp->PrintStudent();
    }
    void searchByRange(double low, double high)
    {
        Student *temp = head;
        bool found = false;

        while (temp)
        {
            if (temp->totalAvg >= low && temp->totalAvg <= high)
            {
                found = true;
                temp->PrintStudent();
                cout << "------------------------" << endl;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "No student found in the marks range of '" << low << " , " << high << "' found in the system." << endl;
        }
    }
    void clearMemory()
    {
        while (head)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
class Control
{
    Management user;
    string adminUsername = "admin";
    string adminPass = "admin123";

public:
    void adminMenu()
    {
        int choice;
        string stID, stName, stPass, stBlood, stEmail, stGender, stAddress;
        int subNo;
        while (true)
        {
            cout << "------- Admin Menu -------" << endl;
            cout << "1. Add Account" << endl;
            cout << "2. Remove Account" << endl;
            cout << "3. Show All Accounts" << endl;
            cout << "4. Modify Account" << endl;
            cout << "5. Search Account" << endl;
            cout << "6. Log Out" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter student ID: ";
                cin.ignore();
                getline(cin, stID);
                cout << "Enter student name: ";
                getline(cin, stName);
                cout << "Enter a storng password: ";
                getline(cin, stPass);
                cout << "Enter student's blood group: ";
                getline(cin, stBlood);
                cout << "Enter student's email address: ";
                getline(cin, stEmail);
                cout << "Enter student's gender: ";
                getline(cin, stGender);
                cout << "Enter student's address: ";
                getline(cin, stAddress);
                cout << "Number of subject to be enrolled: ";
                cin >> subNo;
                user.addStudent(stID, stName, stPass, stBlood, stEmail, stGender, stAddress, subNo);
                break;
            case 2:
                if (user.totalStudent() == 0)
                {
                    cout << "No student in our system." << endl;
                    return;
                }
                cout << "Enter student ID to remove: ";
                cin.ignore();
                getline(cin, stID);
                user.removeStudent(stID);
                break;
            }
        }
    }
};
