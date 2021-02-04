class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        unordered_map<int, int> myMap;
        vector<int> numsSorted = nums;
        sort(numsSorted.begin(), numsSorted.end(), greater<int>());
        for (int i = 0; i < numsSorted.size(); i++) {
            myMap[numsSorted[i]] = i + 1;
        }
        vector<string> output;
        for (int i = 0; i < nums.size(); i++) {
            if (myMap[nums[i]] == 1) {
                output.push_back("Gold Medal");
            }
            else if (myMap[nums[i]] == 2) {
                output.push_back("Silver Medal");
            }
            else if (myMap[nums[i]] == 3) {
                output.push_back("Bronze Medal");
            }
            else {
                output.push_back(to_string(myMap[nums[i]]));
            }
        }
        return output;
    }
};
