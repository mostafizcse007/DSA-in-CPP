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
    vector<vector<bool>> arr(vertex, vector<bool>(vertex, 0));
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        arr[u][v] = 1;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}