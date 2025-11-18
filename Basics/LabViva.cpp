#include <iostream>
using namespace std;
class Member
{
public:
    string ID, accName, accType;
    double accBal, accInt;
    Member *next;
    Member(string ID, string accName, string accType, double accBal)
    {
        this->ID = ID;
        this->accName = accName;
        this->accType = accType;
        this->accBal = accBal;
        Member *next = nullptr;
        calculateInterest();
    }
    void calculateInterest()
    {
        if (accBal > 100000)
            accInt = accBal * .05;
        else if (accBal <= 100000 && accBal >= 50000)
            accInt = accBal * .02;
        else
            accInt = 0;
    }
    void printMember()
    {
        cout << "Account number: " << ID << endl;
        cout << "Account holder name: " << accName << endl;
        cout << "Type of account: " << accType << endl;
        cout << "Main Balance: " << accBal << endl;
        cout << "Interest: " << accInt << endl;
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
    Member *findMember(string id)
    {
        Member *temp = head;
        while (temp)
        {
            if (temp->ID == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    void addMember(string id, string name, string type, double balance)
    {
        if (findMember(id) != nullptr)
        {
            cout << "Member with ID: " << id << " already exists." << endl;
            return;
        }
        Member *newMember = new Member(id, name, type, balance);
        newMember->next = head;
        head = newMember;
        cout << "Member with ID: " << id << " added sucessfully." << endl;
    }
    void removeMember(string id)
    {
        Member *temp = findMember(id);
        if (temp == nullptr)
        {
            cout << "Member with ID: " << id << " not found." << endl;
            return;
        }
        if (head->ID == id)
        {
            Member *dummy = head;
            head = head->next;
            delete dummy;
            cout << "Member with ID: " << id << " deleted successfully." << endl;
            return;
        }
        Member *curr = head;
        Member *prev = nullptr;
        while (curr && curr->ID != id)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Member with ID: " << id << " deleted successfully." << endl;
    }
    void modifyMember(string id, string newid, string name, string type, double balance)
    {
        Member *temp = findMember(id);
        if (temp == nullptr)
        {
            cout << "Member with ID: " << id << " not found." << endl;
            return;
        }
        temp->ID = newid;
        temp->accName = name;
        temp->accType = type;
        temp->accBal = balance;
        temp->calculateInterest();
        cout << "Account modified sucessfully." << endl;
    }
    void searchMember(string id)
    {
        Member *temp = findMember(id);
        if (temp == nullptr)
        {
            cout << "Member with ID: " << id << " not found." << endl;
            return;
        }
        temp->printMember();
    }
    void CashIn(string id, double amount)
    {
        Member *temp = findMember(id);
        if (temp == nullptr)
        {
            cout << "Account not found." << endl;
            return;
        }
        temp->accBal += amount;
        temp->calculateInterest();
    }
    void CashOut(string id, double amount)
    {
        Member *temp = findMember(id);
        if (temp == nullptr)
        {
            cout << "Account not found." << endl;
            return;
        }
        if (temp->accBal < amount)
        {
            cout << "Insufficient balance." << endl;
            return;
        }
        temp->accBal -= amount;
        temp->calculateInterest();
    }
    void printAllMember()
    {
        Member *temp = head;
        while (temp)
        {
            temp->printMember();
            temp = temp->next;
        }
    }
    int totalMember()
    {
        Member *temp = head;
        int cnt = 0;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};
class ControlPanel
{
    BankSystem control;
    string adminUsername = "admin";
    string adminPass = "admin123";

public:
    void adminMenu()
    {
        int choice;
        string myID, myName, myType, newID;
        double myBalance;
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
                cout << "Enter account number: ";
                cin.ignore();
                getline(cin, myID);
                cout << "Enter account name: ";
                getline(cin, myName);
                cout << "Enter account type: ";
                getline(cin, myType);
                cout << "Enter initial balance: ";
                cin >> myBalance;
                control.addMember(myID, myName, myType, myBalance);
                break;
            case 2:
                if (control.totalMember() == 0)
                {
                    cout << "No members in the database." << endl;
                    return;
                }
                cout << "Enter account number to remove: ";
                cin.ignore();
                getline(cin, myID);
                control.removeMember(myID);
                break;
            case 3:
                if (control.totalMember() == 0)
                {
                    cout << "No members in the database." << endl;
                    return;
                }
                control.printAllMember();
                break;
            case 4:
                cout << "Enter account number: ";
                cin.ignore();
                getline(cin, myID);
                cout << "Enter new account number: ";
                getline(cin, newID);
                cout << "Enter new account name: ";
                getline(cin, myName);
                cout << "Enter new account type: ";
                getline(cin, myType);
                cout << "Enter new initial balance: ";
                cin >> myBalance;
                control.modifyMember(myID, newID, myName, myType, myBalance);
                break;
            case 5:
                cout << "Enter account number: ";
                cin.ignore();
                getline(cin, myID);
                control.searchMember(myID);
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice." << endl;
            }
        }
    }
    void userMenu(string id)
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
                control.CashIn(id, amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                control.CashOut(id, amount);
                break;
            case 3:
                control.searchMember(id);
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
        int choice;
        string id, username, password;
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
                cin.ignore();
                getline(cin, username);
                cout << "Enter admin password: ";
                getline(cin, password);
                if (username == adminUsername && password == adminPass)
                {
                    adminMenu();
                }
                else
                {
                    cout << "Invalid credentials." << endl;
                }
                break;
            case 2:
                if (control.totalMember() == 0)
                {
                    cout << "No members in the database." << endl;
                }
                else
                {
                    cout << "Enter account number: ";
                    cin.ignore();
                    getline(cin, id);
                    if (control.findMember(id))
                    {
                        userMenu(id);
                    }
                    else
                    {
                        cout << "Invalid account number." << endl;
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
    }
};
int main()
{
    ControlPanel set1;
    set1.login();
}