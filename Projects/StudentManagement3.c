#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5

struct Student
{
    char rollNumber[15];
    char name[50];
    float marks[MAX_SUBJECTS];
    float average;
    int subjects;
    int isDeleted;
};

void calculateAverage(struct Student *s)
{
    float sum = 0;
    for (int i = 0; i < s->subjects; i++)
    {
        sum += s->marks[i];
    }
    s->average = sum / s->subjects;
}

void addStudent(struct Student students[], int *count)
{
    struct Student *s = &students[*count];

    int rollNumberExists;
    do
    {
        rollNumberExists = 0;
        printf("Enter roll number (max 14 characters): ");
        scanf("%s", s->rollNumber);

        for (int i = 0; i < *count; i++)
        {
            if (strcmp(students[i].rollNumber, s->rollNumber) == 0 && !students[i].isDeleted)
            {
                rollNumberExists = 1;
                printf("Roll number already exists! Try again.\n");
                break;
            }
        }
    } while (rollNumberExists);

    printf("Enter name: ");
    getchar();
    scanf("%[^\n]s", s->name);

    do
    {
        printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
        scanf("%d", &s->subjects);
        if (s->subjects > MAX_SUBJECTS || s->subjects < 1)
        {
            printf("Invalid number of subjects. Please enter between 1 and %d.\n", MAX_SUBJECTS);
        }
    } while (s->subjects > MAX_SUBJECTS || s->subjects < 1);

    printf("Enter marks for %d subjects: \n", s->subjects);
    for (int i = 0; i < s->subjects; i++)
    {
        do
        {
            printf("Marks for subject %d: ", i + 1);
            scanf("%f", &s->marks[i]);
            if (s->marks[i] < 0 || s->marks[i] > 100)
            {
                printf("Invalid marks. Please enter marks between 0 and 100.\n");
            }
        } while (s->marks[i] < 0 || s->marks[i] > 100);
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
    {
        printf("%.2f ", s.marks[i]);
    }
    printf("\nAverage Marks: %.2f\n", s.average);
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
        do
        {
            printf("Marks for subject %d: ", i + 1);
            scanf("%f", &s->marks[i]);
            if (s->marks[i] < 0 || s->marks[i] > 100)
            {
                printf("Invalid marks. Please enter marks between 0 and 100.\n");
            }
        } while (s->marks[i] < 0 || s->marks[i] > 100);
    }
    calculateAverage(s);
}

int searchStudent(struct Student students[], int count, char rollNumber[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].rollNumber, rollNumber) == 0 && !students[i].isDeleted)
        {
            return i;
        }
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
    char confirmation;
    printf("Are you sure you want to delete this student (y/n)? ");
    scanf(" %c", &confirmation);
    if (confirmation == 'y' || confirmation == 'Y')
    {
        s->isDeleted = 1;
        printf("Student record deleted.\n");
    }
    else
    {
        printf("Deletion cancelled.\n");
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
            {
                fprintf(fptr, "%.2f ", students[i].marks[j]);
            }
            fprintf(fptr, "%.2f\n", students[i].average);
        }
    }
    fclose(fptr);
    printf("Data saved successfully to 66_G2.txt.\n");
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
        {
            fscanf(fptr, "%f", &students[count].marks[i]);
        }
        fscanf(fptr, "%f", &students[count].average);
        students[count].isDeleted = 0;
        count++;
    }
    fclose(fptr);
    printf("Data loaded from file successfully.\n");
    return count;
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int choice, count = 0;
    char rollNumber[15];
    int index;

    count = loadFromFile(students);

    do
    {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Active Students\n");
        printf("3. Update Student\n");
        printf("4. Search Student by Roll Number\n");
        printf("5. Sort Students by Average Marks\n");
        printf("6. Delete Student\n");
        printf("7. Save Data to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count < MAX_STUDENTS)
            {
                addStudent(students, &count);
            }
            else
            {
                printf("Maximum student limit reached.\n");
            }
            break;
        case 2:
            for (int i = 0; i < count; i++)
            {
                displayStudent(students[i]);
            }
            break;
        case 3:
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
            saveToFile(students, count);
            break;
        case 8:
            printf("Exited Successfully...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}