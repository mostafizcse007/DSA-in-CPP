#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> BFS(vector<int> adj[], int vertex)
{
    queue<int> q;
    vector<bool> visited(vertex, 0);
    q.push(0);
    visited[0] = 1;
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                visited[adj[node][i]] = true;
                q.push(adj[node][i]);
            }
        }
    }
    return ans;
}
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<int> adj[vertex];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = BFS(adj, vertex);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}