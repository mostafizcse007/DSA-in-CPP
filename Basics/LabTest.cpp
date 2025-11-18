#include <bits/stdc++.h>
using namespace std;
class Cafe
{
public:
    int id;
    string customerName;
    string productName;
    double price;
    Cafe *next;
    double myBonus;
    Cafe(int identy, string cName, string pName, double pr)
    {
        id = identy;
        customerName = cName;
        productName = pName;
        price = pr;
        next = nullptr;
        calculateDiscount();
    }
    void displayCustomerInfo()
    {
        cout << "Orderer Id : " << id << "\n"
             << "Customer Name: " << customerName << "\n"
             << "Product Name: " << productName << "\n"
             << "Product Price: " << price << "\n"
             << "Bonus: " << myBonus << "\n";
    }
    void calculateDiscount()
    {
        if (price > 10000)
        {
            myBonus = price * 0.1;
            // price *= 0.9;
        }
        else if (price >= 5000 && price <= 10000)
        {
            myBonus = price * 0.05;
            // .33
            price *= 0.95;
        }
        else
        {
            price = price;
            myBonus = 0;
        }
    }
};
class System
{
public:
    stack<Cafe *> historyStack;
    queue<Cafe *> newCustomerQueue;
    Cafe *head;
    System()
    {
        head = nullptr;
    }
    void addCustomer(int cID, const string &name, const string &pName, double pr)
    {
        if (findCustomer(cID) != nullptr)
        {
            cout << "Error: Customer with ID " << cID << " already exists.\n";
            return;
        }
        Cafe *newCafe = new Cafe(cID, name, pName, pr);
        newCustomerQueue.push(newCafe);
        cout << "Customer added to the queue for confirmation.\n";
    }
    Cafe *findCustomer(int cID) const
    {
        Cafe *current = head;
        while (current != nullptr)
        {
            if (current->id == cID)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    void confirmNewCustomer()
    {
        while (!newCustomerQueue.empty())
        {
            Cafe *newCafe = newCustomerQueue.front();
            newCustomerQueue.pop();
            newCafe->next = head;
            head = newCafe;
            historyStack.push(newCafe);
            cout << "Customer with ID " << newCafe->id << " added successfully.\n";
        }
    }
    void removeCustomer(int cID)
    {
        Cafe *current = head;
        Cafe *previous = nullptr;

        while (current != nullptr && current->id != cID)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Error: Customer with ID " << cID << " not found.\n";
            return;
        }

        if (previous == nullptr)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        historyStack.push(current);
        cout << "Customer with ID " << cID << " removed successfully.\n";
    }
    void modifyCustomer(int cID, const string &newName, const string &newProduct, double newPrice)
    {
        Cafe *emp = findCustomer(cID);
        if (emp == nullptr)
        {
            cout << "Error: Customer with ID " << cID << " not found.\n";
            return;
        }
        emp->customerName = newName;
        emp->productName = newProduct;
        emp->calculateDiscount();
        cout << "Customer information updated successfully.\n";
    }
    void displayAllCustomer() const
    {
        if (head == nullptr)
        {
            cout << "No customer in the system.\n";
            return;
        }

        Cafe *temp = head;
        while (temp != nullptr)
        {
            temp->displayCustomerInfo();
            cout << "--------------------------------\n";
            temp = temp->next;
        }
    }
};

int main()
{
    System ems;
    int choice, cID;
    string name, prName;
    double pr;

    while (true)
    {
        cout << "Order Management System\n"
             << "1. Add Order\n"
             << "2. Confirm New Order\n"
             << "3. Remove Order\n"
             << "4. Modify Customer Information\n"
             << "5. Display All Customers\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Customer ID: ";
            cin >> cID;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Product Name: ";
            getline(cin, prName);
            cout << "Enter Price: ";
            cin >> pr;
            ems.addCustomer(cID, name, prName, pr);
            break;

        case 2:
            ems.confirmNewCustomer();
            break;

        case 3:
            cout << "Enter Customer ID to remove: ";
            cin >> cID;
            ems.removeCustomer(cID);
            break;

        case 4:
            cout << "Enter Customer ID to modify: ";
            cin >> cID;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Product name: ";
            getline(cin, prName);
            cout << "Enter New Price: ";
            cin >> pr;
            ems.modifyCustomer(cID, name, prName, pr);
            break;

        case 5:
            ems.displayAllCustomer();
            break;
        case 6:
            cout << "Exited Successfully" << endl;
            return 0;
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
