#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    max += 1;
    int hash_array[max] = {0};
    for (int i = 0; i < n; i++)
    {
        hash_array[arr[i]]++;
    }
    cout << "Enter number of queries: ";
    int que;
    cin >> que;
    while (que--)
    {
        int num;
        cin >> num;
        cout << num << " " << hash_array[num] << endl;
    }
    return 0;
}