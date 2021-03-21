class Solution {
public:
    const int BIG_PRIME = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 0));
        int output = 0;
        dp[0][0] = arr[0] % 2 == 0? 1 : 0;
        dp[0][1] = arr[0] % 2 != 0? 1 : 0;
        output += dp[0][1];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
            }
            else {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + 1;
            }
            output = (output + dp[i][1]) % BIG_PRIME;
        }
        return output;
    }
};
