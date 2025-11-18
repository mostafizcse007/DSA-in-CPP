#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<bool>> arr(vertex, vector<bool>(vertex, 0));
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    for (auto it : arr)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}