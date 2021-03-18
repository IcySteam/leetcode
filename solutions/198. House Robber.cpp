class Solution {
public:
    vector<vector<int>> memo;
    
    int myRob(vector<int>& nums, int start, int end) {
        if (start > end) {return 0;}
        if (start == end) {return nums[start];}
        if (memo[start][end] != -1) {return memo[start][end];}
        
        vector<int> candidates;
        candidates.push_back(nums[start] + myRob(nums, start + 2, end));
        candidates.push_back(myRob(nums, start + 1, end));
        int output =  *max_element(candidates.begin(), candidates.end());
        memo[start][end] = output;
        return output;
    }
    
    int rob(vector<int>& nums) {
        vector<vector<int>> memo_temp(nums.size(), vector<int>(nums.size(), -1));
        memo = memo_temp;
        return myRob(nums, 0, nums.size() - 1); 
    }
};
