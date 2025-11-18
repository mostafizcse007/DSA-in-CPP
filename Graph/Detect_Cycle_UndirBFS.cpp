#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
public:
    vector<vector<int>> adj;
    Graph(vector<vector<int>> adj)
    {

        this->adj = adj;
    }
    bool helper(int src, vector<int> &vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle()
    {
        int size = adj.size();
        vector<int> vis(size, 0);
        for (int i = 0; i < size; i++)
        {
            if (!vis[i])
            {
                if (helper(i, vis))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> arr(vertex);
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    Graph g1(arr);
    cout << g1.isCycle() << endl;
    return 0;
}