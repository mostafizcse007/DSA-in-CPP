#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUBJECTS 10
#define MAX_NAME_LENGTH 50
#define MAX_ROLL_NUMBER_LENGTH 20
#define MAX_SUBJECT_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_BLOOD_GROUP_LENGTH 10
#define MAX_GENDER_LENGTH 10

enum Gender
{
    MALE,
    FEMALE,
    OTHER
};
enum BloodGroup
{
    A_POS,
    A_NEG,
    B_POS,
    B_NEG,
    AB_POS,
    AB_NEG,
    O_POS,
    O_NEG
};

struct Student
{
    char rollNumber[MAX_ROLL_NUMBER_LENGTH];
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char bloodGroup[MAX_BLOOD_GROUP_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char gender[MAX_GENDER_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int currentSemester;
    char subjectNames[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
    float marks[MAX_SUBJECTS];
    float average;
    char grade;
    int rank;
    int subjects;
    int isDeleted;
};

struct User
{
    char username[MAX_ROLL_NUMBER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int isAdmin;
};

struct StudentNode
{
    struct Student student;
    struct StudentNode *next;
};

struct UserNode
{
    struct User user;
    struct UserNode *next;
};

// Function to create a new student node
struct StudentNode *createStudentNode(struct Student student)
{
    struct StudentNode *newNode = (struct StudentNode *)malloc(sizeof(struct StudentNode));
    newNode->student = student;
    newNode->next = NULL;
    return newNode;
}

// Function to add a student to the linked list
void addStudentNode(struct StudentNode **head, struct Student student)
{
    struct StudentNode *newNode = createStudentNode(student);
    newNode->next = *head;
    *head = newNode;
}

// Function to search for a student by roll number
struct StudentNode *searchStudentNode(struct StudentNode *head, char rollNumber[])
{
    struct StudentNode *current = head;
    while (current != NULL)
    {
        if (strcmp(current->student.rollNumber, rollNumber) == 0 && !current->student.isDeleted)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a student node
void deleteStudentNode(struct StudentNode *node)
{
    if (node != NULL)
    {
        node->student.isDeleted = 1;
    }
}

// Function to display a student
void displayStudent(struct Student student)
{
    if (!student.isDeleted)
    {
        printf("Roll Number: %s\n", student.rollNumber);
        printf("Name: %s\n", student.name);
        printf("Email: %s\n", student.email);
        printf("Gender: %s\n", student.gender);
        printf("Blood Group: %s\n", student.bloodGroup);
        printf("Address: %s\n", student.address);
        printf("Current Semester: %d\n", student.currentSemester);
        printf("Average Marks: %.2f\n", student.average);
        printf("Grade: %c\n", student.grade);
        printf("Rank: %d\n", student.rank);
        printf("Subjects and Marks:\n");
        for (int i = 0; i < student.subjects; i++)
        {
            printf("  %s: %.2f\n", student.subjectNames[i], student.marks[i]);
        }
        printf("\n");
    }
}

// Function to calculate average marks
void calculateAverage(struct Student *s)
{
    float sum = 0;
    for (int i = 0; i < s->subjects; i++)
    {
        sum += s->marks[i];
    }
    s->average = sum / s->subjects;
}

// Function to assign grade based on average
void assignGrade(struct Student *s)
{
    if (s->average >= 90)
    {
        s->grade = 'A';
    }
    else if (s->average >= 80)
    {
        s->grade = 'B';
    }
    else if (s->average >= 70)
    {
        s->grade = 'C';
    }
    else if (s->average >= 60)
    {
        s->grade = 'D';
    }
    else
    {
        s->grade = 'F';
    }
}

// Function to add a student
void addStudent(struct StudentNode **head)
{
    struct Student s;
    int rollNumberExists;
    do
    {
        rollNumberExists = 0;
        printf("Enter roll number (max 14 characters): ");
        scanf("%14s", s.rollNumber);

        if (searchStudentNode(*head, s.rollNumber) != NULL)
        {
            rollNumberExists = 1;
            printf("Roll number already exists! Try again.\n");
        }
    } while (rollNumberExists);

    printf("Enter name: ");
    getchar(); // Clear newline character from buffer
    fgets(s.name, MAX_NAME_LENGTH, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline character

    printf("Enter password: ");
    fgets(s.password, MAX_PASSWORD_LENGTH, stdin);
    s.password[strcspn(s.password, "\n")] = 0; // Remove newline character

    printf("Enter blood group: ");
    fgets(s.bloodGroup, MAX_BLOOD_GROUP_LENGTH, stdin);
    s.bloodGroup[strcspn(s.bloodGroup, "\n")] = 0; // Remove newline character

    printf("Enter email: ");
    fgets(s.email, MAX_EMAIL_LENGTH, stdin);
    s.email[strcspn(s.email, "\n")] = 0; // Remove newline character

    printf("Enter gender: ");
    fgets(s.gender, MAX_GENDER_LENGTH, stdin);
    s.gender[strcspn(s.gender, "\n")] = 0; // Remove newline character

    printf("Enter home address: ");
    fgets(s.address, MAX_ADDRESS_LENGTH, stdin);
    s.address[strcspn(s.address, "\n")] = 0; // Remove newline character

    printf("Enter current semester: ");
    scanf("%d", &s.currentSemester);

    do
    {
        printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
        scanf("%d", &s.subjects);
        if (s.subjects > MAX_SUBJECTS || s.subjects < 1)
        {
            printf("Invalid number of subjects. Please enter between 1 and %d.\n", MAX_SUBJECTS);
        }
    } while (s.subjects > MAX_SUBJECTS || s.subjects < 1);

    for (int i = 0; i < s.subjects; i++)
    {
        printf("Enter name for subject %d: ", i + 1);
        getchar(); // Clear newline character from buffer
        fgets(s.subjectNames[i], MAX_SUBJECT_NAME_LENGTH, stdin);
        s.subjectNames[i][strcspn(s.subjectNames[i], "\n")] = 0; // Remove newline character
    }

    printf("Enter marks for %d subjects: \n", s.subjects);
    for (int i = 0; i < s.subjects; i++)
    {
        do
        {
            printf("Marks for %s: ", s.subjectNames[i]);
            scanf("%f", &s.marks[i]);
            if (s.marks[i] < 0 || s.marks[i] > 100)
            {
                printf("Invalid marks. Please enter marks between 0 and 100.\n");
            }
        } while (s.marks[i] < 0 || s.marks[i] > 100);
    }
    calculateAverage(&s);
    assignGrade(&s);
    s.isDeleted = 0;
    addStudentNode(head, s);
}

// Function to update a student
void updateStudent(struct StudentNode *node)
{
    if (node == NULL || node->student.isDeleted)
    {
        printf("This student record is deleted or not found.\n");
        return;
    }
    printf("Enter new marks for %d subjects: \n", node->student.subjects);
    for (int i = 0; i < node->student.subjects; i++)
    {
        do
        {
            printf("Marks for %s: ", node->student.subjectNames[i]);
            scanf("%f", &node->student.marks[i]);
            if (node->student.marks[i] < 0 || node->student.marks[i] > 100)
            {
                printf("Invalid marks. Please enter marks between 0 and 100.\n");
            }
        } while (node->student.marks[i] < 0 || node->student.marks[i] > 100);
    }
    calculateAverage(&node->student);
    assignGrade(&node->student);
}

// Function to sort students by average marks
void sortStudentsByAverage(struct StudentNode **head)
{
    if (*head == NULL)
        return;

    struct StudentNode *i;
    struct StudentNode *j;
    struct Student temp;

    for (i = *head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (!i->student.isDeleted && !j->student.isDeleted && i->student.average < j->student.average)
            {
                temp = i->student;
                i->student = j->student;
                j->student = temp;
            }
        }
    }
}

// Function to view top N students
void viewTopNStudents(struct StudentNode *head, int N)
{
    sortStudentsByAverage(&head); // Ensure students are sorted by average
    struct StudentNode *current = head;
    int count = 0;
    printf("Top %d Students:\n", N);
    while (current != NULL && count < N)
    {
        if (!current->student.isDeleted)
        {
            displayStudent(current->student);
            count++;
        }
        current = current->next;
    }
}

// Function to filter students by minimum average marks
void filterStudentsByMarks(struct StudentNode *head, float minMarks)
{
    struct StudentNode *current = head;
    printf("Students with average marks >= %.2f:\n", minMarks);
    while (current != NULL)
    {
        if (!current->student.isDeleted && current->student.average >= minMarks)
        {
            displayStudent(current->student);
        }
        current = current->next;
    }
}

// Function to count active and deleted students
void countStudents(struct StudentNode *head)
{
    int activeCount = 0, deletedCount = 0;
    struct StudentNode *current = head;
    while (current != NULL)
    {
        if (current->student.isDeleted)
        {
            deletedCount++;
        }
        else
        {
            activeCount++;
        }
        current = current->next;
    }
    printf("Active Students: %d\n", activeCount);
    printf("Deleted Students: %d\n", deletedCount);
}

// Function to reset a student's password
void resetStudentPassword(struct UserNode *userHead, char *username)
{
    struct UserNode *current = userHead;
    while (current != NULL)
    {
        if (strcmp(current->user.username, username) == 0)
        {
            printf("Enter new password for %s: ", username);
            scanf("%s", current->user.password);
            printf("Password reset successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("User not found.\n");
}

// Function to save deleted students to a separate file
void saveDeletedStudentsToFile(struct StudentNode *head)
{
    FILE *fptr = fopen("deleted_students.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    struct StudentNode *current = head;
    while (current != NULL)
    {
        if (current->student.isDeleted)
        {
            fprintf(fptr, "%s \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" %d %d ",
                    current->student.rollNumber, current->student.name, current->student.password,
                    current->student.bloodGroup, current->student.email, current->student.gender,
                    current->student.address, current->student.currentSemester, current->student.subjects);
            for (int j = 0; j < current->student.subjects; j++)
            {
                fprintf(fptr, "\"%s\" %.2f ", current->student.subjectNames[j], current->student.marks[j]);
            }
            fprintf(fptr, "%.2f\n", current->student.average);
        }
        current = current->next;
    }
    fclose(fptr);
    printf("Deleted students saved successfully to deleted_students.txt.\n");
}

// Function to rank students
void rankStudents(struct StudentNode *head)
{
    sortStudentsByAverage(&head);

    int rank = 1;
    struct StudentNode *current = head;
    while (current != NULL)
    {
        if (!current->student.isDeleted)
        {
            current->student.rank = rank++;
        }
        current = current->next;
    }
}

// Function to save students to file
void saveToFile(struct StudentNode *head)
{
    FILE *fptr = fopen("66_G2.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    struct StudentNode *current = head;
    while (current != NULL)
    {
        if (!current->student.isDeleted)
        {
            fprintf(fptr, "%s \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" \"%s\" %d %d ",
                    current->student.rollNumber, current->student.name, current->student.password,
                    current->student.bloodGroup, current->student.email, current->student.gender,
                    current->student.address, current->student.currentSemester, current->student.subjects);
            for (int j = 0; j < current->student.subjects; j++)
            {
                fprintf(fptr, "\"%s\" %.2f ", current->student.subjectNames[j], current->student.marks[j]);
            }
            fprintf(fptr, "%.2f\n", current->student.average);
        }
        current = current->next;
    }
    fclose(fptr);
    printf("Data saved successfully to 66_G2.txt.\n");
}

// Function to load students from file
int loadFromFile(struct StudentNode **head)
{
    FILE *fptr = fopen("66_G2.txt", "r");
    if (fptr == NULL)
    {
        printf("No existing data file found.\n");
        return 0;
    }

    int count = 0;
    struct Student s;
    while (fscanf(fptr, "%s \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" %d %d",
                  s.rollNumber, s.name, s.password,
                  s.bloodGroup, s.email, s.gender,
                  s.address, &s.currentSemester, &s.subjects) == 9)
    {
        for (int i = 0; i < s.subjects; i++)
        {
            if (fscanf(fptr, "\"%[^\"]\" %f", s.subjectNames[i], &s.marks[i]) != 2)
            {
                printf("Error reading student data for subject %d.\n", i + 1);
                break;
            }
        }
        if (fscanf(fptr, "%f", &s.average) != 1)
        {
            printf("Error reading student average for roll number %s.\n", s.rollNumber);
            break;
        }
        assignGrade(&s);
        s.isDeleted = 0;
        addStudentNode(head, s);
        count++;
    }
    fclose(fptr);
    printf("Data loaded from file successfully.\n");
    return count;
}

// Function to handle login
int login(struct UserNode *userHead)
{
    char username[MAX_ROLL_NUMBER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    struct UserNode *current = userHead;
    while (current != NULL)
    {
        if (strcmp(current->user.username, username) == 0 && strcmp(current->user.password, password) == 0)
        {
            return current->user.isAdmin;
        }
        current = current->next;
    }
    printf("Invalid username or password.\n");
    return -1;
}

// Main function
int main()
{
    struct StudentNode *studentHead = NULL;
    struct UserNode *userHead = NULL; // Assuming user management is also needed
    int choice;
    char rollNumber[MAX_ROLL_NUMBER_LENGTH];
    struct StudentNode *studentNode;

    // Load data from file
    loadFromFile(&studentHead);

    // Example user data for demonstration
    struct User admin = {"admin", "adminpass", 1};
    struct User student = {"student", "studentpass", 0};
    struct UserNode *adminNode = (struct UserNode *)malloc(sizeof(struct UserNode));
    struct UserNode *studentNodeUser = (struct UserNode *)malloc(sizeof(struct UserNode));
    adminNode->user = admin;
    adminNode->next = studentNodeUser;
    studentNodeUser->user = student;
    studentNodeUser->next = NULL;
    userHead = adminNode;

    int isAdmin = login(userHead);
    if (isAdmin == -1)
    {
        return 0; // Exit if login fails
    }

    while (1)
    {
        printf("\n--- Student Management System ---\n");
        if (isAdmin)
        {
            printf("1. Display All Active Students\n");
            printf("2. Add Student\n");
            printf("3. Update Student\n");
            printf("4. Search Student by Roll Number\n");
            printf("5. Sort Students by Average Marks\n");
            printf("6. Delete Student\n");
            printf("7. Save Data to File\n");
            printf("8. View Top N Students\n");
            printf("9. Filter Students by Minimum Average Marks\n");
            printf("10. Save Data to File\n");
            printf("11. Count Active and Deleted Students\n");
            printf("12. Rank Students by Average Marks\n");
            printf("13. Reset Student Password\n");
            printf("14. Save Deleted Students to File\n");
            printf("15. Logout\n");
            printf("0. Exit\n");
        }
        else
        {
            printf("1. View Your Data\n");
            printf("2. Change Password\n");
            printf("15. Logout\n");
            printf("0. Exit\n");
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (isAdmin)
        {
            switch (choice)
            {
            case 1:
                studentNode = studentHead;
                while (studentNode != NULL)
                {
                    displayStudent(studentNode->student);
                    studentNode = studentNode->next;
                }
                break;

            case 2:
                addStudent(&studentHead);
                rankStudents(studentHead);
                break;

            case 3:
                printf("Enter roll number of the student to update: ");
                scanf("%s", rollNumber);
                studentNode = searchStudentNode(studentHead, rollNumber);
                if (studentNode != NULL)
                {
                    updateStudent(studentNode);
                    printf("Student record updated.\n");
                    rankStudents(studentHead);
                }
                else
                {
                    printf("Student not found.\n");
                }
                break;

            case 4:
                printf("Enter roll number to search: ");
                scanf("%s", rollNumber);
                studentNode = searchStudentNode(studentHead, rollNumber);
                if (studentNode != NULL)
                {
                    displayStudent(studentNode->student);
                }
                else
                {
                    printf("Student not found.\n");
                }
                break;

            case 5:
                sortStudentsByAverage(&studentHead);
                printf("Students sorted by average marks.\n");
                break;

            case 6:
                printf("Enter roll number of the student to delete: ");
                scanf("%s", rollNumber);
                studentNode = searchStudentNode(studentHead, rollNumber);
                if (studentNode != NULL)
                {
                    deleteStudentNode(studentNode);
                    printf("Student record deleted.\n");
                    rankStudents(studentHead);
                }
                else
                {
                    printf("Student not found.\n");
                }
                break;

            case 7:
                saveToFile(studentHead);
                break;

            case 8:
            {
                int N;
                printf("Enter the number of top students to view: ");
                scanf("%d", &N);
                viewTopNStudents(studentHead, N);
            }
            break;

            case 9:
            {
                float minMarks;
                printf("Enter minimum average marks to filter: ");
                scanf("%f", &minMarks);
                filterStudentsByMarks(studentHead, minMarks);
            }
            break;

            case 10:
                saveToFile(studentHead);
                break;

            case 11:
                countStudents(studentHead);
                break;

            case 12:
                rankStudents(studentHead);
                printf("Students ranked by average marks.\n");
                break;

            case 13:
            {
                char studentUsername[MAX_NAME_LENGTH];
                printf("Enter student's username to reset password: ");
                scanf("%s", studentUsername);
                resetStudentPassword(userHead, studentUsername);
            }
            break;

            case 14:
                saveDeletedStudentsToFile(studentHead);
                break;

            case 15:
                printf("Logged out successfully.\n");
                isAdmin = login(userHead);
                if (isAdmin == -1)
                {
                    return 0; // Exit if login fails
                }
                break;

            case 0:
                printf("Exited Successfully...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
            }
        }
        else
        {
            switch (choice)
            {
            case 1:
                // View your data (for student)
                studentNode = searchStudentNode(studentHead, student.username);
                if (studentNode != NULL)
                {
                    displayStudent(studentNode->student);
                }
                else
                {
                    printf("Student data not found.\n");
                }
                break;

            case 2:
                // Change password (for student)
                printf("Enter new password: ");
                scanf("%s", student.password);
                printf("Password changed successfully.\n");
                break;

            case 15:
                printf("Logged out successfully.\n");
                isAdmin = login(userHead);
                if (isAdmin == -1)
                {
                    return 0; // Exit if login fails
                }
                break;

            case 0:
                printf("Exited Successfully...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
            }
        }
    }

    return 0;
}