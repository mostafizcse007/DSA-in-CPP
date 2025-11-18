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
            cout << "No member found with account number " << id << "." << endl;
            return;
        }
        if (head->accNum == id)
        {
            Member *dummy = head;
            head = head->next;
            delete dummy;
            cout << "Account number " << id << " deleted successfully." << endl;
            return;
        }
        Member *curr = head;
        Member *prev = nullptr;
        while (curr != nullptr && curr->accNum != id)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
            return;
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
        temp->balance += amount;
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
        if (temp->balance < amount)
        {
            cout << "Insufficient balance." << endl;
            return;
        }
        temp->balance -= amount;
        temp->calculateInterest();
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

class System
{
    BankSystem bank;
    string adminUsername = "admin";
    string adminPassword = "password";

public:
    void adminMenu()
    {
        int choice, id;
        double balance;
        string name, type;
        while (true)
        {
            cout << "------- Admin Menu -------" << endl;
            cout << "1. Add Account" << endl;
            cout << "2. Remove Account" << endl;
            cout << "3. Show All Accounts" << endl;
            cout << "4. Log Out" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter account number: ";
                cin >> id;
                cin.ignore();
                cout << "Enter account name: ";
                getline(cin, name);
                cout << "Enter account type: ";
                getline(cin, type);
                cout << "Enter initial balance: ";
                cin >> balance;
                bank.addMember(id, name, type, balance);
                break;
            case 2:
                cout << "Enter account number to remove: ";
                cin >> id;
                bank.removeMember(id);
                break;
            case 3:
                bank.printAllMember();
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice." << endl;
            }
        }
    }

    void userMenu(int userID)
    {
        int choice;
        double amount;
        while (true)
        {
            cout << "------- User Menu -------" << endl;
            cout << "1. Cash In" << endl;
            cout << "2. Cash Out" << endl;
            cout << "3. View Account Details" << endl;
            cout << "4. Log Out" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.CashIn(userID, amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.CashOut(userID, amount);
                break;
            case 3:
                bank.searchID(userID);
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice." << endl;
            }
        }
    }

    void login()
    {
        int choice, userID;
        string username, password;
        while (true)
        {
            cout << "------- Login Menu -------" << endl;
            cout << "1. Admin Login" << endl;
            cout << "2. User Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter admin username: ";
                cin >> username;
                cout << "Enter admin password: ";
                cin >> password;
                if (username == adminUsername && password == adminPassword)
                {
                    adminMenu();
                }
                else
                {
                    cout << "Invalid credentials." << endl;
                }
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> userID;
                if (bank.findMemberID(userID))
                {
                    userMenu(userID);
                }
                else
                {
                    cout << "Invalid account number." << endl;
                }
                break;
            case 3:
                cout << "Exiting system. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice." << endl;
            }
        }
    }
};

int main()
{
    System system;
    system.login();
    return 0;
}
