    }
    
    int DFS(vector<vector<int>>& grid, int m, int n) {
        if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size() || grid[m][n] <= 0) {return 0;}
        vector<vector<int>> adjacent = getAdjacent(grid, m, n);
        if (adjacent.size() == 0) {return grid[m][n];}
        vector<int> results;
        results.push_back(grid[m][n]);
        for (auto& ele : adjacent) {
            int x, y;
            x = ele[0];
            y = ele[1];
            int temp = grid[m][n];
            grid[m][n] = -grid[m][n];
            temp += DFS(grid, x, y);
            grid[m][n] = -grid[m][n];
            results.push_back(temp);
        }
        return *max_element(results.begin(), results.end());
    }
    
    vector<vector<int>> getAdjacent(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>> output;
        vector<int> temp;
        if(m < grid.size() - 1) {
            if (grid[m + 1][n] > 0) {
                temp.clear();
                temp.push_back(m + 1);
                temp.push_back(n);
                output.push_back(temp);
            }
        }
        if(m > 0) {
            if (grid[m - 1][n] > 0) {
                temp.clear();
                temp.push_back(m - 1);
                temp.push_back(n);
                output.push_back(temp);
            }
        }
        if(n < grid[0].size() - 1) {
            if (grid[m][n + 1] > 0) {
                temp.clear();
                temp.push_back(m);
                temp.push_back(n + 1);
                output.push_back(temp);
            }
        }
        if(n > 0) {
            if (grid[m][n - 1] > 0) {
                temp.clear();
                temp.push_back(m);
                temp.push_back(n - 1);
                output.push_back(temp);
            }
        }
        return output;
    }
};
​
//solution by vutrubac
/*
class Solution {
    int dfs(vector<vector<int>>& g, int i, int j) {
      if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] <= 0)  return 0;
      g[i][j] = -g[i][j];
      auto res = max({ dfs(g, i + 1, j), dfs(g, i, j + 1), dfs(g, i - 1, j), dfs(g, i, j - 1) });
      g[i][j] = -g[i][j];
      return g[i][j] + res;
    }
    int getMaximumGold(vector<vector<int>>& grid, int res = 0) {
      for (auto i = 0; i < grid.size(); ++i)
        for (auto j = 0; j < grid[i].size(); ++j)
          res = max(res, dfs(grid, i, j));
      return res;
    }
};
*/
