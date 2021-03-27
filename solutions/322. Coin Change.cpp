class Solution {
public:
    unordered_map<int, int> memo;
    
    int DFS(vector<int>& coins, int amount, int count) {
        if (memo.find(amount) != memo.end()) {
            if (memo[amount] == INT_MAX) {return INT_MAX;}
            return memo[amount] + count;
        }
        
        if (amount == 0) {
            return count;
        }
        else if (amount < 0) {
            return INT_MAX;
        }
        else {
            vector<int> candidates;
            for (int i = 0; i < coins.size(); i++) {
                candidates.push_back(DFS(coins, amount - coins[i], count + 1));
            }
            int res = *min_element(candidates.begin(), candidates.end());
            if (res != INT_MAX) {memo[amount] = res - count;}
            else {memo[amount] = res;}
            return res;
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int output = DFS(coins, amount, 0);
        if (output == INT_MAX) {output = -1;}
        return output;
    }
};
