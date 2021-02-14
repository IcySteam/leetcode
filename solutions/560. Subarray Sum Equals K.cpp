class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        myMap[0] = 1;
        int currentSum = 0;
        int output = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            if (myMap.find(currentSum - k) != myMap.end()) {
                output += myMap[currentSum - k];
            }
            
            if (myMap.find(currentSum) == myMap.end()) {
                myMap[currentSum] = 1;
            }
            else {myMap[currentSum]++;}
        }
        return output;
    }
};
