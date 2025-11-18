#include <bits/stdc++.h>
using namespace std;
class Member
{
public:
    int accNum;
    string accName, accType;
    double balance, interest;
    Member *next;
    Member(int accNum, string accName, string accType, double balance)
    {
        this->accNum = accNum;
        this->accName = accName;
        this->accType = accType;
        this->balance = balance;
        next = nullptr;
        calculateInterest();
    }
    void calculateInterest()
    {
        if (balance > 100000)
        {
            interest = balance * .05;
        }
        else
        {
            interest = balance * .02;
        }
    }
    void printMember()
    {
        cout << "Account number: " << accNum << endl;
        cout << "Account holder name: " << accName << endl;
        cout << "Type of account: " << accType << endl;
        cout << "Main Balance: " << balance << endl;
        cout << "Interest: " << interest << endl;
    }
};
class BankSystem
{
public:
    Member *head;
    BankSystem()
    {
        head = nullptr;
    }
    Member *findMemberID(int id)
    {
        Member *temp = head;
        while (temp != nullptr)
        {
            if (temp->accNum == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    Member *findMemberName(string name)
    {
        Member *temp = head;
        while (temp != nullptr)
        {
            if (temp->accName == name)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    void addMember(int id, string name, string type, double balance)
    {
        if (findMemberID(id) != nullptr)
        {
            cout << "Account with number " << id << " already exists." << endl;
            return;
        }
        Member *newMember = new Member(id, name, type, balance);
        newMember->next = head;
        head = newMember;
    }
    void removeMember(int id)
    {
        Member *temp = findMemberID(id);
        if (temp == nullptr)
        {
            cout << "No member found with " << id << " account number." << endl;
            return;
        }
        Member *curr = head;
        Member *prev = nullptr;
        if (head->accNum == id)
        {
            Member *dummy = head;
            head = head->next;
            delete dummy;
            cout << "Account number " << id << " deleted successfully." << endl;
            return;
        }
        while (curr != nullptr && curr->accNum != id)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Account number " << id << " deleted successfully." << endl;
    }
    void printAllMember()
    {
        Member *temp = head;
        while (temp != nullptr)
        {
            temp->printMember();
            cout << "------------------" << endl;
            temp = temp->next;
        }
    }
    void CashIn(int id, double amount)
    {
        Member *temp = findMemberID(id);
        if (temp == nullptr)
        {
            cout << "Account not found." << endl;
            return;
        }
        temp->balance = temp->balance + amount;
        temp->calculateInterest();
    }
    void CashOut(int id, double amount)
    {
        Member *temp = findMemberID(id);
        if (temp == nullptr)
        {
            cout << "Account not found." << endl;
            return;
        }
        temp->balance = temp->balance - amount;
        temp->calculateInterest();
    }
    void searchName(string name)
    {
        Member *temp = findMemberName(name);
        if (temp == nullptr)
        {
            cout << "Account with name " << name << " not found." << endl;
            return;
        }
        temp->printMember();
    }
    void searchID(int id)
    {
        Member *temp = findMemberID(id);
        if (temp == nullptr)
        {
            cout << "Account with id " << id << " not found." << endl;
            return;
        }
        temp->printMember();
    }
};
int main()
{
    BankSystem mySys;
    int choice, myID;
    double myBal;
    string myName, myType;
    while (true)
    {
        cout << "---------------------Bank Management System---------------------" << endl;
        cout << "1. Add account" << endl;
        cout << "2. Remove Account" << endl;
        cout << "3. Show all accounts" << endl;
        cout << "4. Cash In" << endl;
        cout << "5. Cash Out" << endl;
        cout << "6. Search by accout number" << endl;
        cout << "7. Search by account name" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter your account number: ";
            cin >> myID;
            cout << "Enter your account name: ";
            cin.ignore();
            getline(cin, myName);
            cout << "Enter your account type(Ex: Student, Regular, etc): ";
            getline(cin, myType);
            cout << "Enter the amount you want to store: ";
            cin >> myBal;
            mySys.addMember(myID, myName, myType, myBal);
            break;
        case 2:
            cout << "Enter account number to delete: ";
            cin >> myID;
            mySys.removeMember(myID);
            break;
        case 3:
            mySys.printAllMember();
            break;
        case 4:
            cout << "Enter your account number: ";
            cin >> myID;
            cout << "Enter the amount you want to deposit: ";
            cin >> myBal;
            mySys.CashIn(myID, myBal);
            break;
        case 5:
            cout << "Enter your account number: ";
            cin >> myID;
            cout << "Enter the amount you want to withdraw: ";
            cin >> myBal;
            mySys.CashOut(myID, myBal);
            break;
        case 6:
            cout << "Enter your account number: ";
            cin >> myID;
            mySys.searchID(myID);
            break;
        case 7:
            cout << "Enter your account name: ";
            cin >> myName;
            mySys.searchName(myName);
            break;
        case 8:
            cout << "Exitted successfully." << endl;
            return 0;
            break;
        default:
            cout << "Invalid input." << endl;
        }
    }
    return 0;
}