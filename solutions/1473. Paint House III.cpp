class Solution {
public:
    vector<vector<vector<int>>> dp;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp.clear();
        vector<vector<vector<int>>> dpInit(m, vector<vector<int>>(n + 1, vector<int>(m + 2, -1)));
        dp = dpInit;
        if (houses[0] == 0) {
            for (int i = 1; i <= n; i++) {
                dp[0][i][1] = cost[0][i - 1];
            }
        }
        else {
            dp[0][houses[0]][1] = 0;
        }
        for (int i = 1; i < m; i++) {
            if (houses[i] != 0) {
                if (houses[i - 1] != 0) {
                    for (int k = 1; k <= target; k++) {
                        if (houses[i] == houses[i - 1]) {
                            update(&dp[i][houses[i]][k], dp[i - 1][houses[i]][k]);
                        }
                        else {
                            update(&dp[i][houses[i]][k + 1], dp[i - 1][houses[i - 1]][k]);
                        }
                    }
                }
                else {
                    for (int j = 1; j <= n; j++) {
                        for (int k = 1; k <= target; k++) {
                            if (j == houses[i]) {
                                update(&dp[i][houses[i]][k], dp[i - 1][j][k]);
                            }
                            else {
                                update(&dp[i][houses[i]][k + 1], dp[i - 1][j][k]);
                            }
                        }
                    }
                }
            }
            else {
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= target; k++) {
                        if (houses[i - 1] != 0) {
                            if (houses[i - 1] == j) {
                                if (dp[i - 1][houses[i - 1]][k] != -1) {update(&dp[i][j][k], dp[i - 1][houses[i - 1]][k] + cost[i][j - 1]);}
                            }
                            else {
                                if (dp[i - 1][houses[i - 1]][k] != -1) {update(&dp[i][j][k + 1], dp[i - 1][houses[i - 1]][k] + cost[i][j - 1]);}
                            }
                        }
                        else {
                            for (int l = 1; l <= n; l++) {
                                if (j == l) {
                                    if (dp[i - 1][l][k] != -1) {update(&dp[i][j][k], dp[i - 1][l][k] + cost[i][j - 1]);}
                                }
                                else {
                                    if (dp[i - 1][l][k] != -1) {update(&dp[i][j][k + 1], dp[i - 1][l][k] + cost[i][j - 1]);}
                                }
                            }
                        }
                    }
                }
            }
        }
        int output = -1;
        for (int i = 1; i <= n; i++) {
            update(&output, dp[m - 1][i][target]);
        }
        return output;
    }
    void update(int* target, int input) {
        if ((*target == -1 || *target > input) && input != -1) {*target = input;}
    }
};
​
​
​
// t=3 [2,3,0] [[5,2,3],[3,4,1],[1,2,1]] res=1 
// dp[0][2][1]=0 dp[1][3][2]=0 dp[2][1][3]=dp[][][]
// 
// 
// 
// 
// 
// 
// 
