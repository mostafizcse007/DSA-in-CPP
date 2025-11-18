#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<int> arr[vertex];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
    }
    for (int i = 0; i < vertex; i++)
    {
        cout << i << "->";
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}