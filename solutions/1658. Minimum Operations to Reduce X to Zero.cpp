class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (nums.size() == 1) {return nums[0] == x? 1 : -1;}
        
        unordered_map<int, int> sum2count;
        int currentSum = 0;
        for (int i = 0; i < nums.size() && currentSum <= x; i++) {
            if (sum2count.find(currentSum) == sum2count.end()) {sum2count[currentSum] = i;}
            currentSum += nums[i];
        }
        
        currentSum = 0;
        int output = INT_MAX;
        for (int i = nums.size() - 1; i >= 0 && currentSum <= x; i--) {
            if (sum2count.find(x - currentSum) != sum2count.end()) {
                output = min({output, sum2count[x - currentSum] + ((int)nums.size() - i - 1)});
            }
            currentSum += nums[i];
        }
        return output != INT_MAX? output : -1;
    }
};
