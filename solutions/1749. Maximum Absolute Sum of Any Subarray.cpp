class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int output = abs(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            vector<int> candidates{dp[i - 1][0] + nums[i], dp[i - 1][1] + nums[i], nums[i]};
            int newMin = *min_element(candidates.begin(), candidates.end());
            int newMax = *max_element(candidates.begin(), candidates.end());
            dp[i][0] = newMin;
            dp[i][1] = newMax;
            output = max({output, abs(newMin), abs(newMax)});
        }
        return output;
    }
};
