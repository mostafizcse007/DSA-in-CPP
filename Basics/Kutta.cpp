#include <iostream>
using namespace std;
class Member
{
public:
    string accID, accName, accType;
    double accBal, accInt;
    Member *next;
    Member(string accID, string accName, string accType, double accBal)
    {
        this->accID = accID;
        this->accName = accName;
        this->accType = accType;
        this->accBal = accBal;
        Member *next = nullptr;
        calculateInterest();
    }
    void calculateInterest()
    {
        if (accBal >= 100000)
            accInt = accBal * .05;
        else if (accBal >= 50000)
            accInt = accBal * .02;
        else
            accInt = 0;
    }
    void printStudent()
    {
        cout << "Account number: " << accID << endl;
        cout << "Account holder name: " << accName << endl;
        cout << "Type of account: " << accType << endl;
        cout << "Main Balance: " << accBal << endl;
        cout << "Interest: " << accInt << endl;
    }
};
class System
{
public:
    Member *head;
    System()
    {
        head = nullptr;
    }
    Member *findID(string id)
    {
        Member *temp = head;
        while (temp)
        {
            if (temp->accID == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    Member *findName(string name)
    {
        Member *temp = head;
        while (temp)
        {
            if (temp->accName == name)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};