class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int output = 0;
        vector<int> ambiguous(strs.size() - 1, 1);
        for (int i = 0; i < strs[0].size(); i++) {
            bool pass = true;
            bool del = false;
            vector<int> pendingAmbiguous = ambiguous;
            for (int j = 1; j < strs.size(); j++) {
                if (ambiguous[j - 1] == 1) {
                    if (strs[j][i] > strs[j - 1][i]) {pendingAmbiguous[j - 1] = 0;}
                    else {
                        pass = false;
                        if (strs[j][i] < strs[j - 1][i]) {del = true;}
                    }
                }
            }
            if (pass) {break;}
            if (del) {output++;}
            else {
                ambiguous = pendingAmbiguous;
            }
        }
        return output;
    }
};
