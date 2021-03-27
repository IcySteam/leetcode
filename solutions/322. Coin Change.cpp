class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;
    
    int DFS(vector<int>& coins, int index, int amount, int count) {
        if (memo.find(index) != memo.end()) {
            if (memo[index].find(amount) != memo[index].end()) {
                if (memo[index][amount] == INT_MAX) {return INT_MAX;}
                return memo[index][amount] + count;
            }
        }
           
        if (amount == 0) {
            return count;
        }
        else if (amount < 0 || index >= coins.size()) { // going over / having amount left after running out of denominations
            return INT_MAX;
        }
        
        vector<int> candidates;
        for (int i = 0; i < (amount / coins[index]) + 1; i++) { // +1 important!!!
            int res_tmp = DFS(coins, index + 1, amount - coins[index] * i, count + i);
            // cout << res_tmp << endl;
            candidates.push_back(res_tmp);
        }
        if (candidates.empty()) {
            memo[index][amount] = INT_MAX;
            return INT_MAX;
        }
        
        int res = *min_element(candidates.begin(), candidates.end());
        if (res != INT_MAX) {memo[index][amount] = res - count;}
        else {memo[index][amount] = res;}
        return res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int output = DFS(coins, 0, amount, 0);
        if (output == INT_MAX) {output = -1;}
        return output;
    }
};
