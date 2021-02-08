class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> mySet;
        for (auto ele : arr) {mySet.insert(ele);}
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
        int diff = maxi - mini;
        if (diff == 0) {return true;}
        if (diff % (arr.size() - 1) != 0) {return false;}
        for (int i = mini; i <= maxi; i += diff/(arr.size() - 1)) {
            if (mySet.find(i) == mySet.end()) {return false;}
        }
        return true;
    }
};
