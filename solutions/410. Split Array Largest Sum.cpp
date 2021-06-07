// my OG solution; too slow at O(mn^2) aka. O(n^2)
class Solution {
public:
    int splitArray(const vector<int>& nums, int m) {
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp; // part. no. -> start pos. -> end pos.
        unordered_map<int, int> sums;
        unordered_map<int, unordered_map<int, int>> minStarts;
        sums[0] = nums[0];
        sums[-1] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        
        int res = INT_MAX;
        for (int part = 0; part < m; ++part) {
            int startPosFloor = part;
            int startPosCeil = nums.size() - 1;
            if (part == 0) {startPosCeil = 0;}
            for (int startPos = startPosFloor; startPos <= startPosCeil; ++startPos) {
                int endPosFloor = startPos;
                int endPosCeil = nums.size() - 1 - ((m - 1) - part);
                for (int endPos = endPosFloor; endPos <= endPosCeil; ++endPos) {                    
                    // int lastVal = INT_MAX;
                    // for (int i = 0; i < nums.size(); ++i) {
                    //     if (dp.find(part - 1) != dp.end()) {
                    //         if (dp[part - 1].find(i) != dp[part - 1].end()) {
                    //             if (dp[part - 1][i].find(startPos - 1) != dp[part - 1][i].end()) {
                    //                 lastVal = min({lastVal, dp[part - 1][i][startPos - 1]});
                    //             }
                    //         }
                    //     }
                    // }
                    
                    int lastVal = minStarts[part - 1][startPos - 1];
                    dp[part][startPos][endPos] = max({part == 0? INT_MIN : lastVal, sums[endPos] - sums[startPos - 1]});
                    // cout << part << ", " << startPos << ", " << endPos << ": " << dp[part][startPos][endPos] << endl;
                    if (minStarts.find(part) != minStarts.end()) {
                        if (minStarts[part].find(endPos) != minStarts[part].end()) {
                            minStarts[part][endPos] = min({minStarts[part][endPos], dp[part][startPos][endPos]});
                        }
                        else {
                            minStarts[part][endPos] = dp[part][startPos][endPos];
                        }
                    }
                    else {
                        minStarts[part][endPos] = dp[part][startPos][endPos];
                    }
                    if (part == m - 1 && endPos == nums.size() - 1) {res = min({res, dp[part][startPos][endPos]});}
                }
            }
        }
        return res;
    }
};
