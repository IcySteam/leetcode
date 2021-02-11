class Solution {
public:
    vector<int> groups;
    bool found;
    
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0 || sum == 0) {return false;}
        groups.clear();
        for (int i = 0; i < nums.size(); i++) {groups.push_back(0);}
        found = false;
        DFS(nums, 0);
        return found;
    }
    
    void DFS(vector<int>& nums, int pos) {
        if (found) {return;}
        if (pos == nums.size()) {
            vector<int> sums(4, 0);
            for (int i = 0; i < nums.size(); i++) {
                sums[groups[i] - 1] += nums[i];
            }
            cout << sums[0] << " " << sums[1] << " " << sums[2] << " " << sums[3] << "\n";
            if (sums[0] == sums[1] && sums[0] == sums[2] && sums[0] == sums[3]) {
                found = true;
            }
        }
        else {
            for (int i = 1; i <= 4; i++) {
                groups[pos] = i;
                DFS(nums, pos + 1);
            }
        }
    }
};
