#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string stID, stName, stBlood, stEmail, stGender, stAddress, stGrade;
    string stPassHash;
    int subNo;
    double totalAvg;
    vector<double> subMarks;
    vector<string> subNames;
    Student *next;

    Student(const string &id, const string &name, const string &passHash, const string &blood,
            const string &email, const string &gender, const string &address, int number,
            bool readFromFile = true)
        : stID(id), stName(name), stPassHash(passHash), stBlood(blood), stEmail(email),
          stGender(gender), stAddress(address), subNo(number), next(nullptr)
    {
        if (subNo > 0)
        {
            if (readFromFile)
            {
                try
                {
                    calculateAvgFromFile("input.txt");
                    calculateGrade();
                }
                catch (const exception &e)
                {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }
        else
        {
            cerr << "Error: Number of subjects must be greater than 0." << endl;
        }
    }

    void calculateAvgFromFile(const string &inputFilePath)
    {
        ifstream inputFile(inputFilePath);
        if (!inputFile.is_open() || inputFile.peek() == ifstream::traits_type::eof())
        {
            cout << "File not found or empty. Please enter the subject names and marks." << endl;

            subMarks.clear();
            subNames.clear();
            double sum = 0;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            for (int i = 0; i < subNo; i++)
            {
                string subName;
                double mark;

                cout << "Enter subject name for subject " << i + 1 << ": ";
                getline(cin, subName);

                cout << "Enter marks for " << subName << ": ";
                while (!(cin >> mark) || mark < 0 || mark > 100)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid marks. Enter a number between 0 and 100: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer for next input

                subNames.push_back(subName);
                subMarks.push_back(mark);
                sum += mark;
            }

            totalAvg = sum / subNo;
            return;
        }

        subMarks.clear();
        subNames.clear();
        double sum = 0;
        int subjectCount = 0;

        while (true)
        {
            string subName;
            double mark;

            if (!getline(inputFile, subName))
                break;

            if (!(inputFile >> mark))
            {
                cerr << "Error: Failed to read marks for " << subName << ". Ensure file format is correct." << endl;
                return;
            }
            inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

            if (mark < 0 || mark > 100)
            {
                cerr << "Error: Invalid marks for " << subName << ". Marks should be between 0 and 100." << endl;
                return;
            }

            subNames.push_back(subName);
            subMarks.push_back(mark);
            sum += mark;
            subjectCount++;
        }

        if (subjectCount == 0)
        {
            cerr << "Error: No valid data found in the file." << endl;
            return;
        }

        totalAvg = sum / subjectCount;
    }

    void calculateGrade()
    {
        if (totalAvg >= 80)
            stGrade = "A+";
        else if (totalAvg >= 70)
            stGrade = "A";
        else if (totalAvg >= 65)
            stGrade = "A-";
        else if (totalAvg >= 60)
            stGrade = "B";
        else
            stGrade = "B-";
    }

    void PrintStudent() const
    {
        cout << "Student ID: " << stID << endl;
        cout << "Student Name: " << stName << endl;
        cout << "Student Blood Group: " << stBlood << endl;
        cout << "Student Email Address: " << stEmail << endl;
        cout << "Gender: " << stGender << endl;
        cout << "Home Address: " << stAddress << endl;
        cout << "Number of courses taken: " << subNo << endl;
        for (int i = 0; i < subNo; ++i)
        {
            cout << "Subject: " << subNames[i] << ", Marks: " << subMarks[i] << endl;
        }
        cout << "Total average: " << totalAvg << endl;
        cout << "Grade: " << stGrade << endl;
    }

    string toCSV() const
    {
        ostringstream ss;
        ss << stID << "," << stName << "," << stPassHash << "," << stBlood << ","
           << stEmail << "," << stGender << "," << stAddress << "," << subNo << ","
           << totalAvg << "," << stGrade;
        for (int i = 0; i < subNo; ++i)
        {
            ss << "," << subNames[i] << ":" << subMarks[i];
        }
        return ss.str();
    }

    static Student fromCSV(const string &line)
    {
        istringstream ss(line);
        string id, name, passHash, blood, email, gender, address, grade;
        int number;
        double avg;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, passHash, ',');
        getline(ss, blood, ',');
        getline(ss, email, ',');
        getline(ss, gender, ',');
        getline(ss, address, ',');
        ss >> number;
        ss.ignore();
        ss >> avg;
        ss.ignore();
        getline(ss, grade, ',');

        // Construct the student without reading from "input.txt"
        Student student(id, name, passHash, blood, email, gender, address, number, false);
        student.totalAvg = avg;
        student.stGrade = grade;

        string subNameMark;
        while (getline(ss, subNameMark, ','))
        {
            size_t pos = subNameMark.find(':');
            if (pos != string::npos)
            {
                string subName = subNameMark.substr(0, pos);
                double mark = stod(subNameMark.substr(pos + 1));
                student.subNames.push_back(subName);
                student.subMarks.push_back(mark);
            }
        }
        return student;
    }
};

class Management
{
public:
    Student *head;
    const string fileName = "students.csv";
    const string deletedFile = "deleted_students.txt";

    Management() : head(nullptr) {}

    ~Management()
    {
        // saveToCSV();
        clearMemory();
    }

    Student *findID(const string &id) const
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

    Student *findEmail(const string &email) const
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
    Student *findPass(const string &pass) const
    {
        Student *temp = head;
        while (temp)
        {
            if (temp->stPassHash == pass)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    vector<Student *> convertListToVector() const
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

    void addStudent(const string &id, const string &name, const string &passHash,
                    const string &blood, const string &email, const string &gender,
                    const string &address, int number)
    {
        if (findID(id) != nullptr)
        {
            cout << "Student with ID: " << id << " already present in our system." << endl;
            return;
        }
        if (findEmail(email) != nullptr)
        {
            cout << "Student with Email: " << email << " already present in our system." << endl;
            return;
        }
        Student *newStudent = new Student(id, name, passHash, blood, email, gender, address, number);
        newStudent->next = head;
        head = newStudent;
        cout << "Student information added successfully." << endl;
    }

    void removeStudent(const string &id)
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
            Student *toDelete = head;
            head = head->next;
            saveDeletedStudent(toDelete); // Save before deleting
            delete toDelete;
            cout << "Student with ID: " << id << " deleted successfully from our system." << endl;
            return;
        }
        Student *curr = head->next;
        Student *prev = head;
        while (curr && curr->stID != id)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr)
        {
            prev->next = curr->next;
            saveDeletedStudent(curr); // Save before deleting
            delete curr;
            cout << "Student with ID: " << id << " deleted successfully from our system." << endl;
        }
    }

    void restoreDeletedStudentByID(const string &id)
    {
        ifstream file(deletedFile);
        if (!file.is_open())
        {
            cout << "No deleted students to restore." << endl;
            return;
        }

        vector<string> lines;
        string line;
        bool found = false;

        while (getline(file, line))
        {
            Student student = Student::fromCSV(line);
            if (student.stID == id)
            {
                // Restore this student
                Student *newStudent = new Student(student.stID, student.stName, student.stPassHash,
                                                  student.stBlood, student.stEmail, student.stGender,
                                                  student.stAddress, student.subNo, false);
                newStudent->subNames = student.subNames;
                newStudent->subMarks = student.subMarks;
                newStudent->totalAvg = student.totalAvg;
                newStudent->stGrade = student.stGrade;
                newStudent->next = head;
                head = newStudent;
                found = true;
                cout << "Student with ID: " << id << " restored successfully." << endl;
            }
            else
            {
                // Keep the line for other students
                lines.push_back(line);
            }
        }
        file.close();

        if (!found)
        {
            cout << "Student with ID: " << id << " not found in deleted students." << endl;
        }
        else
        {
            // Rewrite the file without the restored student
            ofstream outFile(deletedFile);
            if (outFile.is_open())
            {
                for (const string &l : lines)
                {
                    outFile << l << endl;
                }
                outFile.close();
            }
            else
            {
                cerr << "Error updating deleted students file." << endl;
            }
        }
    }
    int totalStudent() const
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

    void changePassword(const string &id, const string &oldPassHash, const string &newPassHash)
    {
        Student *temp = findID(id);
        if (temp == nullptr)
        {
            cout << "Student with ID: " << id << " not found in our system." << endl;
            return;
        }
        if (oldPassHash == newPassHash)
        {
            cout << "Your current password matches previous password." << endl;
            cout << "Come again next time with something unique in mind." << endl;
            return;
        }
        if (oldPassHash == temp->stPassHash)
        {
            if (!isValidPassword(newPassHash))
            {
                cout << "New password does not meet security requirements." << endl;
                return;
            }
            temp->stPassHash = newPassHash;
            cout << "Password changed successfully." << endl;
        }
        else
        {
            cout << "Password doesn't match." << endl;
        }
    }

    bool isValidPassword(const string &password) const
    {
        if (password.length() < 8)
            return false;
        bool hasUpper = false, hasLower = false, hasDigit = false;
        for (char c : password)
        {
            if (isupper(c))
                hasUpper = true;
            if (islower(c))
                hasLower = true;
            if (isdigit(c))
                hasDigit = true;
        }
        return hasUpper && hasLower && hasDigit;
    }

    void loadFromCSV()
    {
        ifstream file(fileName);
        if (!file.is_open())
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            Student student = Student::fromCSV(line);
            Student *newStudent = new Student(student.stID, student.stName, student.stPassHash,
                                              student.stBlood, student.stEmail, student.stGender,
                                              student.stAddress, student.subNo, false);
            newStudent->subNames = student.subNames;
            newStudent->subMarks = student.subMarks;
            newStudent->totalAvg = student.totalAvg;
            newStudent->stGrade = student.stGrade;
            newStudent->next = head;
            head = newStudent;
        }
        file.close();
    }

    void saveDeletedStudent(Student *student) const
    {
        ofstream file(deletedFile, ios::app);
        if (!file.is_open())
        {
            cerr << "Error opening file to save deleted students." << endl;
            return;
        }
        file << student->toCSV() << endl;
        file.close();
    }

    void modifyStudent(const string &id, const string &newid, const string &name, const string &blood, const string &email, const string &gender, const string &address, int number)
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
        temp->stAddress = address;
        temp->subNo = number;
        temp->calculateAvgFromFile("input.txt");
        temp->calculateGrade();
        cout << "All information modified successfully." << endl;
    }

    void searchByID(const string &id) const
    {
        Student *temp = findID(id);
        if (temp == nullptr)
        {
            cout << "Student with ID: " << id << " not found in our system." << endl;
            return;
        }
        temp->PrintStudent();
    }

    void searchByName(const string &name) const
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

    void searchByEmail(const string &email) const
    {
        Student *temp = findEmail(email);
        if (temp == nullptr)
        {
            cout << "Student with Email: " << email << " not found in our system." << endl;
            return;
        }
        temp->PrintStudent();
    }

    void searchByRange(double low, double high) const
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
    void saveToCSV() const
    {
        ofstream file(fileName, ios::trunc);
        if (!file.is_open())
        {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        Student *curr = head;
        while (curr)
        {
            file << curr->toCSV() << endl;
            curr = curr->next;
        }
        file.close();
    }
};

class Control
{
    Management user;
    string adminUsername = "admin";
    string adminPassHash = "admin123";

public:
    Control()
    {
        user.loadFromCSV();
    }
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
            cout << "6. Save student's data to file" << endl;
            cout << "7. Restore Deleted Students" << endl;
            cout << "8. Log Out" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (choice)
            {
            case 1:
                cout << "Enter student ID: ";
                getline(cin, stID);
                cout << "Enter student name: ";
                getline(cin, stName);
                cout << "Enter a strong password: ";
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
                    break;
                }
                cout << "Enter student ID to remove: ";
                getline(cin, stID);
                user.removeStudent(stID);
                break;
            case 3:
                if (user.totalStudent() == 0)
                {
                    cout << "No student in our system." << endl;
                    break;
                }
                {
                    vector<Student *> students = user.convertListToVector();
                    for (Student *student : students)
                    {
                        student->PrintStudent();
                        cout << "------------------------" << endl;
                    }
                }
                break;
            case 4:
                cout << "Enter student ID to modify: ";
                getline(cin, stID);
                cout << "Enter new student ID: ";
                getline(cin, stID);
                cout << "Enter student name: ";
                getline(cin, stName);
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
                user.modifyStudent(stID, stID, stName, stBlood, stEmail, stGender, stAddress, subNo);
                break;
            case 5:
                int searchChoice;
                cout << "Search by: 1. ID 2. Name 3. Email 4. Average Range" << endl;
                cout << "Enter your choice: ";
                cin >> searchChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (searchChoice)
                {
                case 1:
                    cout << "Enter student ID: ";
                    getline(cin, stID);
                    user.searchByID(stID);
                    break;
                case 2:
                    cout << "Enter student name: ";
                    getline(cin, stName);
                    user.searchByName(stName);
                    break;
                case 3:
                    cout << "Enter student email: ";
                    getline(cin, stEmail);
                    user.searchByEmail(stEmail);
                    break;
                case 4:
                    double low, high;
                    cout << "Enter low range: ";
                    cin >> low;
                    cout << "Enter high range: ";
                    cin >> high;
                    user.searchByRange(low, high);
                    break;
                default:
                    cout << "Invalid choice." << endl;
                }
                break;
            case 6:
                user.saveToCSV();
                cout << "Information updated successfully." << endl;
                break;
            case 7:
            {
                cout << "Enter student ID to restore: ";
                string restoreID;
                getline(cin, restoreID);
                user.restoreDeletedStudentByID(restoreID);
                break;
            }
            case 8:
                cout << "Logging out..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    void userMenu(const string &studentID)
    {
        Student *student = user.findID(studentID);
        if (!student)
        {
            cout << "Student not found." << endl;
            return;
        }

        int choice;
        string newPass;
        while (true)
        {
            cout << "------- User Menu -------" << endl;
            cout << "1. View Details" << endl;
            cout << "2. Update Information" << endl;
            cout << "3. Change Password" << endl;
            cout << "4. Log Out" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (choice)
            {
            case 1:
                student->PrintStudent();
                break;
            case 2:
                cout << "Enter new student name: ";
                getline(cin, student->stName);
                cout << "Enter new student's blood group: ";
                getline(cin, student->stBlood);
                cout << "Enter new student's email address: ";
                getline(cin, student->stEmail);
                cout << "Enter new student's gender: ";
                getline(cin, student->stGender);
                cout << "Enter new student's address: ";
                getline(cin, student->stAddress);
                cout << "Number of subject to be enrolled: ";
                cin >> student->subNo;
                student->calculateAvgFromFile("input.txt");
                student->calculateGrade();
                cout << "Information updated successfully." << endl;
                break;
            case 3:
                cout << "Enter your old password: ";
                getline(cin, student->stPassHash);
                cout << "Enter a new password: ";
                getline(cin, newPass);
                user.changePassword(student->stID, student->stPassHash, newPass);
                break;
            case 4:
                cout << "Logging out..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    void login()
    {
        int choice;
        string userAdmin, passAdmin, stuId, stuPass;

        while (true)
        {
            cout << "------- Login Menu -------" << endl;
            cout << "1. Admin Login" << endl;
            cout << "2. Student Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            try
            {
                switch (choice)
                {
                case 1:
                    cout << "Enter admin username: ";
                    getline(cin, userAdmin);
                    cout << "Enter admin password: ";
                    getline(cin, passAdmin);
                    if (userAdmin == adminUsername && passAdmin == adminPassHash)
                    {
                        adminMenu();
                    }
                    else
                    {
                        cout << "Invalid information." << endl;
                    }
                    break;

                case 2:
                    cout << "Enter student ID: ";
                    getline(cin, stuId);
                    cout << "Enter student password: ";
                    getline(cin, stuPass);
                    {
                        Student *student = user.findID(stuId);
                        if (student && student->stPassHash == stuPass)
                        {
                            cout << "Student login successful!" << endl;
                            userMenu(stuId);
                        }
                        else
                        {
                            cout << "Invalid student ID or password." << endl;
                        }
                    }
                    break;

                case 3:
                    cout << "Exiting system. Goodbye!" << endl;
                    return;

                default:
                    cout << "Invalid choice." << endl;
                }
            }
            catch (const exception &e)
            {
                cerr << "An error occurred: " << e.what() << endl;
            }
        }
    }
};

int main()
{
    Control control;
    control.login();
    return 0;
}