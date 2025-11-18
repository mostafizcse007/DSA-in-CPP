#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Form
{
public:
    string email, username, password, sName, sPass, sEmail;
    fstream file;
    From(string username = "", string email = "", string password = "")
    {
        this->username = username;
        this->email = email;
        this->password = password;
    }
    void signup()
    {
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, username);
        cout << "Enter your email: ";
        getline(cin, email);
        cout << "Enter a strong password: ";
        getline(cin, password);
        file.open("loginInfo.txt", ios::out | ios::app);
        if (file.is_open())
        {
            file << username << "*" << email << "*" << password << endl;
            file.close();
            cout << "Sign-up successful!" << endl;
        }
        else
        {
            cout << "Error opening file for writing!" << endl;
        }
    }
    void login()
    {
        cout << "Login Page" << endl;
        cout << "Enter your username: ";
        cin.ignore();
        getline(cin, sName);
        cout << "Enter your password: ";
        getline(cin, sPass);
        file.open("loginInfo.txt", ios::in);
        getline(file, username, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
        while (!file.eof())
        {
            if (username == sName)
            {
                if (password == sPass)
                {
                    cout << "Logged in successfully" << endl;
                    cout << "Username: " << username << endl;
                    cout << "Email: " << email << endl;
                    break;
                }
                else
                    cout << "Wrong Password" << endl;
            }
            else
                cout << "Wrong username" << endl;
            getline(file, username, '*');
            getline(file, email, '*');
            getline(file, password, '\n');
        }
        file.close();
    }
    void forgot()
    {
        cout << "Enter your username: ";
        cin.ignore();
        getline(cin, sName);
        cout << "Enter your email: ";
        getline(cin, sEmail);
        file.open("loginInfo.txt", ios::in);
        getline(file, username, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
        while (!file.eof())
        {
            if (username == sName)
            {
                if (email == sEmail)
                {
                    cout << "Account found" << endl;
                    cout << "Your password: " << password << endl;
                    break;
                }
                else
                    cout << "Account not found" << endl;
            }
            else
                cout << "Account not found" << endl;
        }
        file.close();
    }
};
int main()
{
    Form f1;
    cout << "Enter your choice: " << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign-Up" << endl;
    cout << "3. Forget Password" << endl;
    cout << "4. Exit" << endl;
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        f1.login();
        break;
    case '2':
        f1.signup();
        break;
    case '3':
        f1.forgot();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "Invalid input" << endl;
    }
    return 0;
}