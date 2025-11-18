#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void bfs(vector<int> adj[], vector<bool> &visited, int node)
    {
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (auto it : adj[temp])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int size = isConnected.size();
        vector<int> adj[size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                if (i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        vector<bool> visited(size, false);
        int cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                cnt++;
                bfs(adj, visited, i);
            }
        }
        return cnt;
    }
};