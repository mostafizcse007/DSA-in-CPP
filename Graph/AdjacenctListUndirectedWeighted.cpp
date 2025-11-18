#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<pair<int, int>> arr[vertex];
    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
        arr[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i < vertex; i++)
    {
        cout << i << "->";
        for (int j = 0; j < arr[i].size(); j++)
            cout << "(" << arr[i][j].first << "," << arr[i][j].second << ") ";
        cout << endl;
    }
    return 0;
}