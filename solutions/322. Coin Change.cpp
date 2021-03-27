class Solution {
public:
    int notMyCoinChange(vector<int>& coins, int amount) {
        vector<int> A(amount + 1, amount + 1); // since smallest coin is 1, biggest potential res is amount
        A[0] = 0; // 0 coin needed to get to amount 0
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                A[i] = min(A[i], A[i - coin] + 1); // at A[coin] it is 1; 
            }
        }
        return A[amount] > amount ? -1 : A[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // since smallest coin is 1, biggest potential res is amount
        dp[0] = 0; // 0 coin needed to get to amount 0
        for (auto ele : coins) {
            for (int i = ele; i <= amount; i++) {
                dp[i] = min({dp[i], dp[i - ele] + 1}); // goes from ele to amount incrementing 1 each time, equivalent to using every amount of each coin denomination (but it's combination, NOT permutation)
            }
        }
        return dp[amount] <= amount? dp[amount] : -1;
    }
};
