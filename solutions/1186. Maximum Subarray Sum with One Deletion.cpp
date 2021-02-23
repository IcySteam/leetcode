class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int size = arr.size();
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = arr[0];
        dp[0][1] = arr[0];
        int output = arr[0];
        for (int i = 1; i < size; i++) {
            dp[i][0] = max({arr[i], dp[i - 1][0] + arr[i]});
            dp[i][1] = max({dp[i - 1][0], dp[i - 1][1] + arr[i]});
            output = max({output, dp[i][0], dp[i][1]});
        }
        return output;
    }
};
