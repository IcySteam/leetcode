class Solution {
public:
    vector<int> sums;
    int sum;
    bool found;
    
    bool makesquare(vector<int>& nums) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0 || sum == 0) {return false;}
        sums.clear();
        for (int i = 0; i < 4; i++) {sums.push_back(0);}
        sort(nums.begin(), nums.end(), greater<int>()); // trick to save some time
        found = false;
        DFS(nums, 0);
        return found;
    }
    
    void DFS(vector<int>& nums, int pos) {
        if (found) {return;}
        if (pos == nums.size()) {
            cout << sums[0] << " " << sums[1] << " " << sums[2] << " " << sums[3] << "\n";
            if (sums[0] == sums[1] && sums[0] == sums[2] && sums[0] == sums[3]) {
                found = true;
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                if (sums[i] + nums[pos] <= sum / 4) { // another small trick
                    sums[i] += nums[pos];
                    DFS(nums, pos + 1);
                    sums[i] -= nums[pos];
                }
            }
        }
    }
};
