// sub-optimal O(n * log(n)) solution
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> numsOG;
        vector<int> output;
        for (auto ele : nums) {numsOG.push_back(ele);}
        sort(nums.begin(), nums.end());
        for (int i = 0; i < numsOG.size(); i++) {
            int complement = doBinSearch(nums, target - numsOG[i], 0, numsOG.size() - 1);
            if ((complement != -1) && ((target != numsOG[i] * 2) || (target == numsOG[i] * 2 && count(numsOG.begin(), numsOG.end(), numsOG[i]) > 1))) {
                output.push_back(i);
                for (int j = 0; j < numsOG.size(); j++) {
                    if (numsOG[j] == target - numsOG[i] && i != j) output.push_back(j);
                }
                break;
            }
        }
        return output;
    }
    int doBinSearch(vector<int>& nums, int target, int start, int end) {
        if (start == end) {return nums[start] == target? start : -1;}
        int mid = (start + end) / 2;
        if (nums[mid] == target) {return mid;}
        else if (nums[mid] < target) {return doBinSearch(nums, target, mid + 1, end);}
        else {return doBinSearch(nums, target, start, mid);}
    }
};
*/
​
// optimal O(n) solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> myMap;
        vector<int> emptyVector;
        for (int i = 0; i < nums.size(); i++) {
            myMap[nums[i]] = emptyVector;
        }
        for (int i = 0; i < nums.size(); i++) {
            myMap[nums[i]].push_back(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (myMap.find(target - nums[i]) != myMap.end()) {
                for (int j = 0; j < myMap[target - nums[i]].size(); j++) {
                    if (myMap[target - nums[i]][j] != i) {
                        vector<int> output;
                        output.push_back(i);
                        output.push_back(myMap[target - nums[i]][j]);
                        return output;
                    }
                }
            }
        }
        return emptyVector; // just in case
    }
};
​
