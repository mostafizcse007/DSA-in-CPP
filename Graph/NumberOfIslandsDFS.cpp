#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    dfs(row, col, visited, grid, n, m);
                }
            }
        }
        return cnt;
    }

private:
    void dfs(int i, int j, vector<vector<bool>> &visited,
             vector<vector<char>> &grid, int n, int m)
    {
        visited[i][j] = 1;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + dx[k];
            int ncol = j + dy[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol, visited, grid, n, m);
            }
        }
    }
};