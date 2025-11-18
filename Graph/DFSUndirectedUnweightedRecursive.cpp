#include <iostream>
#include <vector>
using namespace std;
void Helper(int node, vector<int> &ans, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[node] = true;
    ans.push_back(node);
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            Helper(adj[node][i], ans, visited, adj);
    }
}
vector<int> DFS(int vertex, vector<vector<int>> &adj)
{
    vector<int> ans;
    vector<bool> visited(vertex, 0);
    Helper(0, ans, visited, adj);
    return ans;
}
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> adj(vertex);
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = DFS(vertex, adj);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}