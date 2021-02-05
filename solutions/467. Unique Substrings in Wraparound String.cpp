class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> endWithCount(26, 0);
        int currentCount = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i > 0) {
                if ((p[i] - p[i - 1] == 1) || (p[i] == 'a' && p[i - 1] == 'z')) {
                    currentCount++;
                }
                else {
                    currentCount = 1;
                }
            }
            else {
                currentCount = 1;
            }
            endWithCount[p[i] - 'a'] = max({endWithCount[p[i] - 'a'], currentCount});
        }
        int output = 0;
        for (int i = 0; i < 26; i++) {output += endWithCount[i];}
        return output;
    }
};
