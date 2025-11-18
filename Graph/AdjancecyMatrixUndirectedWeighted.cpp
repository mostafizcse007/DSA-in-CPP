#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int vertex, edges;
    cout << "Enter number of vertex: ";
    cin >> vertex;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<vector<int>> arr(vertex, vector<int>(vertex, 0));
    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        arr[u][v] = w;
        arr[v][u] = w;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}