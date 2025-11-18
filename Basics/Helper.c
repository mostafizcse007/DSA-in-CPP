#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member
{
    int accNum;
    char accName[100];
    char accType[100];
    double balance;
    double interest;
    struct Member *next;
} Member;

typedef struct BankSystem
{
    Member *head;
} BankSystem;
void calculateInterest(Member *member);
void printMember(Member *member);
Member *createMember(int accNum, const char *accName, const char *accType, double balance);
Member *findMemberID(BankSystem *bank, int id);
Member *findMemberName(BankSystem *bank, const char *name);
void addMember(BankSystem *bank, int id, const char *name, const char *type, double balance);
void removeMember(BankSystem *bank, int id);
void modifyAccountInfo(BankSystem *bank, int id);
void printAllMember(BankSystem *bank);
void CashIn(BankSystem *bank, int id, double amount);
void CashOut(BankSystem *bank, int id, double amount);
void searchName(BankSystem *bank, const char *name);
void searchID(BankSystem *bank, int id);
void freeAllMembers(BankSystem *bank);

void calculateInterest(Member *member)
{
    if (member->balance > 100000)
    {
        member->interest = member->balance * 0.05;
    }
    else
    {
        member->interest = member->balance * 0.02;
    }
}

void printMember(Member *member)
{
    printf("Account number: %d\n", member->accNum);
    printf("Account holder name: %s\n", member->accName);
    printf("Type of account: %s\n", member->accType);
    printf("Main Balance: %.2lf\n", member->balance);
    printf("Interest: %.2lf\n", member->interest);
}

Member *createMember(int accNum, const char *accName, const char *accType, double balance)
{
    Member *newMember = (Member *)malloc(sizeof(Member));
    newMember->accNum = accNum;
    strcpy(newMember->accName, accName);
    strcpy(newMember->accType, accType);
    newMember->balance = balance;
    newMember->next = NULL;
    calculateInterest(newMember);
    return newMember;
}

Member *findMemberID(BankSystem *bank, int id)
{
    Member *temp = bank->head;
    while (temp != NULL)
    {
        if (temp->accNum == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

Member *findMemberName(BankSystem *bank, const char *name)
{
    Member *temp = bank->head;
    while (temp != NULL)
    {
        if (strcmp(temp->accName, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void addMember(BankSystem *bank, int id, const char *name, const char *type, double balance)
{
    if (findMemberID(bank, id) != NULL)
    {
        printf("Account with number %d already exists.\n", id);
        return;
    }
    Member *newMember = createMember(id, name, type, balance);
    newMember->next = bank->head;
    bank->head = newMember;
}

void removeMember(BankSystem *bank, int id)
{
    Member *temp = bank->head;
    Member *prev = NULL;

    while (temp != NULL && temp->accNum != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("No member found with %d account number.\n", id);
        return;
    }

    if (prev == NULL)
    {
        bank->head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Account number %d deleted successfully.\n", id);
}

void modifyAccountInfo(BankSystem *bank, int id)
{
    Member *member = findMemberID(bank, id);
    if (member == NULL)
    {
        printf("Account with id %d not found.\n", id);
        return;
    }

    char newName[100];
    char newType[100];

    printf("Enter new account name (leave empty to keep unchanged): ");
    getchar();
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';

    printf("Enter new account type (leave empty to keep unchanged): ");
    fgets(newType, sizeof(newType), stdin);
    newType[strcspn(newType, "\n")] = '\0';

    if (strlen(newName) > 0)
    {
        strcpy(member->accName, newName);
    }
    if (strlen(newType) > 0)
    {
        strcpy(member->accType, newType);
    }

    printf("Account information updated successfully.\n");
}

void printAllMember(BankSystem *bank)
{
    Member *temp = bank->head;
    while (temp != NULL)
    {
        printMember(temp);
        printf("------------------\n");
        temp = temp->next;
    }
}

void CashIn(BankSystem *bank, int id, double amount)
{
    Member *temp = findMemberID(bank, id);
    if (temp == NULL)
    {
        printf("Account not found.\n");
        return;
    }
    temp->balance += amount;
    calculateInterest(temp);
}

void CashOut(BankSystem *bank, int id, double amount)
{
    Member *temp = findMemberID(bank, id);
    if (temp == NULL)
    {
        printf("Account not found.\n");
        return;
    }
    temp->balance -= amount;
    calculateInterest(temp);
}

void searchName(BankSystem *bank, const char *name)
{
    Member *temp = findMemberName(bank, name);
    if (temp == NULL)
    {
        printf("Account with name %s not found.\n", name);
        return;
    }
    printf("Account found...\n");
    printMember(temp);
}

void searchID(BankSystem *bank, int id)
{
    Member *temp = findMemberID(bank, id);
    if (temp == NULL)
    {
        printf("Account with id %d not found.\n", id);
        return;
    }
    printMember(temp);
}

void freeAllMembers(BankSystem *bank)
{
    Member *temp = bank->head;
    while (temp != NULL)
    {
        Member *next = temp->next;
        free(temp);
        temp = next;
    }
    bank->head = NULL;
}

int main()
{
    BankSystem mySys;
    mySys.head = NULL;
    int choice, myID;
    double myBal;
    char myName[100], myType[100];

    while (1)
    {
        printf("---------------------Bank Management System---------------------\n");
        printf("1. Add account\n");
        printf("2. Remove Account\n");
        printf("3. Show all accounts\n");
        printf("4. Cash In\n");
        printf("5. Cash Out\n");
        printf("6. Search by account number\n");
        printf("7. Search by account name\n");
        printf("8. Exit\n");
        printf("9. Modify account info\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter your account number: ");
            scanf("%d", &myID);
            getchar();
            printf("Enter your account name: ");
            fgets(myName, sizeof(myName), stdin);
            myName[strcspn(myName, "\n")] = '\0';
            printf("Enter your account type (Ex: Student, Regular, etc): ");
            fgets(myType, sizeof(myType), stdin);
            myType[strcspn(myType, "\n")] = '\0';
            printf("Enter the amount you want to store: ");
            scanf("%lf", &myBal);
            addMember(&mySys, myID, myName, myType, myBal);
            break;
        case 2:
            printf("Enter account number to delete: ");
            scanf("%d", &myID);
            getchar();
            removeMember(&mySys, myID);
            break;
        case 3:
            printAllMember(&mySys);
            break;
        case 4:
            printf("Enter your account number: ");
            scanf("%d", &myID);
            printf("Enter the amount you want to deposit: ");
            scanf("%lf", &myBal);
            CashIn(&mySys, myID, myBal);
            break;
        case 5:
            printf("Enter your account number: ");
            scanf("%d", &myID);
            printf("Enter the amount you want to withdraw: ");
            scanf("%lf", &myBal);
            CashOut(&mySys, myID, myBal);
            break;
        case 6:
            printf("Enter your account number: ");
            scanf("%d", &myID);
            searchID(&mySys, myID);
            break;
        case 7:
            printf("Enter your account name: ");
            fgets(myName, sizeof(myName), stdin);
            myName[strcspn(myName, "\n")] = '\0';
            searchName(&mySys, myName);
            break;
        case 8:
            printf("Exited successfully.\n");
            freeAllMembers(&mySys);
            return 0;
        case 9:
            printf("Enter your account number: ");
            scanf("%d", &myID);
            modifyAccountInfo(&mySys, myID);
            break;
        default:
            printf("Invalid input.\n");
        }
    }
    return 0;
}