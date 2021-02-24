class Solution {
public:
    int m, n;
    int maxStudents(vector<vector<char>>& seats) {
        m = seats.size();
        n = seats[0].size();
        vector<int> seatMasks(m);
        for (int i = 0; i < m; i++) {
            int thisMask = 0;
            for (int j = n - 1; j >= 0; j--) {
                thisMask += seats[i][j] == '.'? pow(2, j) : 0;
            }
            seatMasks[i] = thisMask;
        }
        // cout << seatMasks[0] << " " << seatMasks[1] << " " << seatMasks[2] << "\n";
        
        vector<vector<int>> dp(m, vector<int>(pow(2, n), -1));
        vector<set<int>> validNonEmpty(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < pow(2, n); j++) {
                dp[i][j] = calcDP(dp, validNonEmpty, seatMasks, i, j);
                if (dp[i][j] != 0) {validNonEmpty[i].insert(j);}
            }
        }
        
        return *max_element(dp[m - 1].begin(), dp[m - 1].end());
    }
    
    bool validate(int prev, int current) {
        if (current % 2 == 1 && (prev >> 1) % 2 == 1) {return false;}
        while (prev > 0 && current > 0) {
            if ((current >> 1) % 2 == 1 && (prev % 2 == 1 || (prev >> 2) % 2 == 1)) {return false;}
            prev /= 2;
            current /= 2;
        }
        return true;
    }
    
    int calcDP(vector<vector<int>>& dp, vector<set<int>>& validNonEmpty, vector<int>& seatMasks, int row, int studentMask) {
        if (dp[row][studentMask] != -1) {return dp[row][studentMask];}
        else {
            if (row == 0) {
                if ((studentMask | seatMasks[0]) == seatMasks[0]) {
                    int temp = studentMask;
                    while (temp > 0) {
                        if (temp % 2 == 1 && (temp >> 1) % 2 == 1) {return 0;}
                        temp /= 2;
                    }
                    
                    // cout << studentMask << endl;
                    return __builtin_popcount(studentMask);
                }
                else {return 0;}
            }
            else {
                if ((studentMask | seatMasks[row]) == seatMasks[row]) {
                    int temp = studentMask;
                    while (temp > 0) {
                        if (temp % 2 == 1 && (temp >> 1) % 2 == 1) {return 0;}
                        temp /= 2;
                    }
                    
                    if (!validNonEmpty[row - 1].size()) {return dp[row - 1][0] + __builtin_popcount(studentMask);}
                    else {
                        vector<int> candidates;
                        candidates.push_back(0);
                        for (auto it = validNonEmpty[row - 1].begin(); it != validNonEmpty[row - 1].end(); it++) {
                            if (validate(*it, studentMask)) {candidates.push_back(*it);}
                        }
                        vector<int> candidateResults;
                        for (auto& ele : candidates) {candidateResults.push_back(dp[row - 1][ele]);}
                        return *max_element(candidateResults.begin(), candidateResults.end()) + __builtin_popcount(studentMask);
                    }
                }
                else {return 0;}
            }
        }
    }
};
