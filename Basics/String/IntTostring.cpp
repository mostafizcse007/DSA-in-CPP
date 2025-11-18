#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void printLocalTime()
{
    time_t now = time(0);
    tm *localtm = localtime(&now);
    cout << "Local time: " << put_time(localtm, "%Y-%m-%d %H:%M:%S") << endl;
}

void printUTCTime()
{
    time_t now = time(0);
    tm *utctm = gmtime(&now);
    cout << "UTC time: " << put_time(utctm, "%Y-%m-%d %H:%M:%S") << endl;
}

int main()
{
    printLocalTime();
    printUTCTime();
    return 0;
}