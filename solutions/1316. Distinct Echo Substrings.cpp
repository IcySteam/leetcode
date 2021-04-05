class Solution {
public:
    int distinctEchoSubstrings(string& text) {
        unordered_map<int, unordered_map<int, size_t>> substrHashes;
        hash<string> strHasher;
        for (int subLen = 1; subLen <= text.size() / 2; subLen++) {
            for (int i = 0; i <= text.size() - subLen; i++) {
                substrHashes[i][i + subLen - 1] = strHasher(text.substr(i, subLen));
                // cout << text.substr(i, subLen) << "\t" << strHasher(text.substr(i, subLen)) << endl;
                
            }
        }
        
        unordered_set<string> hits;
        for (int subLen = 1; subLen <= text.size() / 2; subLen++) {
            for (int i = 0; i <= text.size() - 2 * subLen; i++) {
                if (substrHashes[i][i + subLen - 1] == substrHashes[i + subLen][i + subLen + subLen - 1]) {
                    hits.insert(text.substr(i, subLen * 2));
                }
            }
        }
        return hits.size();
    }
};
