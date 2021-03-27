class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> A(amount + 1, amount + 1); // since smallest coin is 1, biggest potential res is amount
        A[0] = 0; // 0 coin needed to get to amount 0
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                A[i] = min(A[i], A[i - coin] + 1); // at A[coin] it is 1; 
            }
        }
        return A[amount] > amount ? -1 : A[amount];
    }
};
