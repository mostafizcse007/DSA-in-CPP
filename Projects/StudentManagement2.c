#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define MAX_USERS 10

struct Student
{
    char rollNumber[15];
    char name[50];
    float marks[MAX_SUBJECTS];
    float average;
    int rank;
    int subjects;
    int isDeleted;
};

struct User
{
    char username[20];
    char password[20];
    int isAdmin;
};

void resetStudentPassword(struct User users[], int userCount, char studentUsername[])
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, studentUsername) == 0 && users[i].isAdmin == 0)
        {
            char newPassword[20];
            printf("Enter new password for %s: ", studentUsername);
            scanf("%s", newPassword);
            strcpy(users[i].password, newPassword);
            printf("Password reset successfully.\n");
            return;
        }
    }
    printf("Student with username %s not found.\n", studentUsername);
}

void calculateAverage(struct Student *s)
{
    float sum = 0;
    for (int i = 0; i < s->subjects; i++)
        sum += s->marks[i];

    s->average = sum / s->subjects;
}

int login(struct User users[], int userCount)
{
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
            return users[i].isAdmin;
    }
    printf("Invalid username or password.\n");
    return -1;
}

void initializeUsers(struct User users[], int *userCount)
{
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin123");
    users[0].isAdmin = 1;

    strcpy(users[1].username, "student1");
    strcpy(users[1].password, "stud1");
    users[1].isAdmin = 0;

    strcpy(users[2].username, "student2");
    strcpy(users[2].password, "stud2");
    users[2].isAdmin = 0;

    *userCount = 3;
}

void addStudent(struct Student students[], int *count)
{
    struct Student *s = &students[*count];
    printf("Enter roll number (max 14 characters): ");
    scanf("%s", s->rollNumber);

    for (int i = 0; i < *count; i++)
    {
        if (strcmp(students[i].rollNumber, s->rollNumber) == 0 && !students[i].isDeleted)
        {
            printf("Roll number already exists! Try again.\n");
            return;
        }
    }

    printf("Enter name: ");
    getchar();
    scanf("%[^\n]s", s->name);

    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &s->subjects);

    if (s->subjects > MAX_SUBJECTS || s->subjects < 1)
    {
        printf("Invalid number of subjects. Please enter between 1 and %d.\n", MAX_SUBJECTS);
        return;
    }

    printf("Enter marks for %d subjects: \n", s->subjects);
    for (int i = 0; i < s->subjects; i++)
    {
        printf("Marks for subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
    }

    calculateAverage(s);
    s->isDeleted = 0;
    (*count)++;
}

void displayStudent(struct Student s)
{
    if (s.isDeleted)
        return;

    printf("\nRoll Number: %s", s.rollNumber);
    printf("\nName: %s", s.name);
    printf("\nMarks: ");
    for (int i = 0; i < s.subjects; i++)
        printf("%.2f ", s.marks[i]);

    printf("\nAverage Marks: %.2f", s.average);
    printf("\nRank: %d\n", s.rank);
}

void updateStudent(struct Student *s)
{
    if (s->isDeleted)
    {
        printf("This student record is deleted.\n");
        return;
    }
    printf("Enter new marks for %d subjects: \n", s->subjects);
    for (int i = 0; i < s->subjects; i++)
    {
        printf("Marks for subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
    }
    calculateAverage(s);
}

int searchStudent(struct Student students[], int count, char rollNumber[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].rollNumber, rollNumber) == 0 && !students[i].isDeleted)
            return i;
    }
    return -1;
}

void sortStudentsByAverage(struct Student students[], int count)
{
    struct Student temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (!students[i].isDeleted && !students[j].isDeleted && students[i].average < students[j].average)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void deleteStudent(struct Student *s)
{
    if (s->isDeleted)
    {
        printf("Student already deleted.\n");
        return;
    }
    s->isDeleted = 1;
    printf("Student record deleted.\n");
}

void rankStudents(struct Student students[], int count)
{
    sortStudentsByAverage(students, count);

    int rank = 1;
    for (int i = 0; i < count; i++)
    {
        if (!students[i].isDeleted)
            students[i].rank = rank++;
    }
}

void saveToFile(struct Student students[], int count)
{
    FILE *fptr = fopen("66_G2.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (!students[i].isDeleted)
        {
            fprintf(fptr, "%s \"%s\" %d ", students[i].rollNumber, students[i].name, students[i].subjects);
            for (int j = 0; j < students[i].subjects; j++)
                fprintf(fptr, "%.2f ", students[i].marks[j]);

            fprintf(fptr, "%.2f\n", students[i].average);
        }
    }
    fclose(fptr);
    printf("Data saved successfully to 66_G2.txt.\n");
}

void saveDeletedStudentsToFile(struct Student students[], int count)
{
    FILE *file = fopen("deleted_students.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for saving deleted students.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (students[i].isDeleted)
        {
            fprintf(file, "%s \"%s\" %d ", students[i].rollNumber, students[i].name, students[i].subjects);
            for (int j = 0; j < students[i].subjects; j++)
                fprintf(file, "%.2f ", students[i].marks[j]);

            fprintf(file, "%.2f\n", students[i].average);
        }
    }
    fclose(file);
    printf("Deleted students saved successfully to deleted_students.txt.\n");
}

int loadFromFile(struct Student students[])
{
    FILE *fptr = fopen("66_G2.txt", "r");
    if (fptr == NULL)
    {
        printf("No existing data file found.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(fptr, "%s \"%[^\"]\" %d", students[count].rollNumber, students[count].name, &students[count].subjects) != EOF)
    {
        for (int i = 0; i < students[count].subjects; i++)
            fscanf(fptr, "%f", &students[count].marks[i]);

        fscanf(fptr, "%f", &students[count].average);
        students[count].isDeleted = 0;
        count++;
    }
    fclose(fptr);
    printf("Data loaded from file successfully.\n");
    return count;
}

void viewOwnData(struct Student students[], int count, char rollNumber[])
{
    int index = searchStudent(students, count, rollNumber);
    if (index != -1)
        displayStudent(students[index]);
    else
        printf("Student data not found.\n");
}

void restoreStudent(struct Student *s)
{
    if (s->isDeleted)
    {
        s->isDeleted = 0;
        printf("Student record restored successfully.\n");
    }
    else
    {
        printf("Student record is not marked as deleted.\n");
    }
}
void filterStudentsByMarks(struct Student students[], int count, float minAverage)
{
    printf("\nStudents with average marks >= %.2f:\n", minAverage);
    for (int i = 0; i < count; i++)
    {
        if (!students[i].isDeleted && students[i].average >= minAverage)
        {
            displayStudent(students[i]);
        }
    }
}

void countStudents(struct Student students[], int count)
{
    int activeCount = 0, deletedCount = 0;
    for (int i = 0; i < count; i++)
    {
        if (students[i].isDeleted)
        {
            deletedCount++;
        }
        else
        {
            activeCount++;
        }
    }
    printf("Total Active Students: %d\n", activeCount);
    printf("Total Deleted Students: %d\n", deletedCount);
}

int main()
{
    struct Student students[MAX_STUDENTS];
    struct User users[MAX_USERS];
    int choice, count = 0, userCount = 0;
    int isAdmin;
    char rollNumber[15];
    int index;

    initializeUsers(users, &userCount);

    count = loadFromFile(students);

    printf("\n--- Login Panel ---\n");
    do
    {
        isAdmin = login(users, userCount);
    } while (isAdmin == -1);
    if (!isAdmin)
    {

        printf("Logged in as student.\n");
        printf("Your details:\n");
        viewOwnData(students, count, users[0].username);
    }

    do
    {
        printf("\n--- Student Management System ---\n");
        printf("1. Display All Active Students\n");

        if (!isAdmin)
        {
            printf("2. View Your Data\n");
            printf("3. Change Password\n");
        }

        if (isAdmin)
        {
            printf("2. Add Student\n");
            printf("3. Update Student\n");
            printf("4. Search Student by Roll Number\n");
            printf("5. Sort Students by Average Marks\n");
            printf("6. Delete Student\n");
            printf("7. Restore Deleted Student\n");
            printf("8. View Top N Students\n");
            printf("9. Filter Students by Minimum Average Marks\n");
            printf("10. Save Data to File\n");
            printf("11. Count Active and Deleted Students\n");
            printf("12. Rank Students by Average Marks\n");
            printf("13. Reset Student Password\n");
            printf("14. Deleted students list:\n ");
        }

        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (int i = 0; i < count; i++)
            {
                displayStudent(students[i]);
            }
            break;

        case 2:
            if (isAdmin)
            {

                if (count < MAX_STUDENTS)
                {
                    addStudent(students, &count);
                }
                else
                {
                    printf("Maximum student limit reached.\n");
                }
            }
            else
            {

                viewOwnData(students, count, users[0].username);
            }
            break;

        case 3:
            if (isAdmin)
            {

                printf("Enter roll number of the student to update: ");
                scanf("%s", rollNumber);
                index = searchStudent(students, count, rollNumber);
                if (index != -1)
                {
                    updateStudent(&students[index]);
                    printf("Student record updated.\n");
                }
                else
                {
                    printf("Student not found.\n");
                }
            }
            else
            {

                changePassword(&users[0]);
            }
            break;
        case 4:
            printf("Enter roll number to search: ");
            scanf("%s", rollNumber);
            index = searchStudent(students, count, rollNumber);
            if (index != -1)
            {
                displayStudent(students[index]);
            }
            else
            {
                printf("Student not found.\n");
            }
            break;
        case 5:
            sortStudentsByAverage(students, count);
            printf("Students sorted by average marks.\n");
            break;
        case 6:
            printf("Enter roll number of the student to delete: ");
            scanf("%s", rollNumber);
            index = searchStudent(students, count, rollNumber);
            if (index != -1)
            {
                deleteStudent(&students[index]);
            }
            else
            {
                printf("Student not found.\n");
            }
            break;

        case 7:
            if (isAdmin)
            {
                printf("Enter roll number of the student to restore: ");
                scanf("%s", rollNumber);
                index = searchDelStudent(students, count, rollNumber);
                if (index != -1)
                {
                    restoreStudent(&students[index]);
                }
                else
                {
                    printf("Student not found.\n");
                }
            }
            break;

        case 8:
            if (isAdmin)
            {
                int N;
                printf("Enter the number of top students to view: ");
                scanf("%d", &N);
                viewTopNStudents(students, count, N);
            }
            break;

        case 9:
            if (isAdmin)
            {
                float minMarks;
                printf("Enter minimum average marks to filter: ");
                scanf("%f", &minMarks);
                filterStudentsByMarks(students, count, minMarks);
            }
            break;
        case 10:
            if (isAdmin)
            {
                saveToFile(students, count);
            }
            break;
        case 11:
            if (isAdmin)
            {
                countStudents(students, count);
            }
            break;
        case 12:
            if (isAdmin)
            {
                rankStudents(students, count); // Assign ranks
                printf("Students ranked by average marks.\n");
            }
            break;
        case 13:
            if (isAdmin)
            {
                char studentUsername[20];
                printf("Enter student's username to reset password: ");
                scanf("%s", studentUsername);
                resetStudentPassword(users, userCount, studentUsername);
            }
            break;
        case 14:
            if (isAdmin)
            {
                saveDeletedStudentsToFile(students, count);
            }
            break;
        case 0:
            printf("Exited Successfully...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
