#include <iostream>
#include <vector>
using namespace std;
void selSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[mini] > arr[j])
                mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selSort(arr);
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
    return 0;
}