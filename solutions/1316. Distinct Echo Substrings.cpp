const unsigned int SMALL_PRIME = 257;
const unsigned int BIG_PRIME = 1000000007;
​
long long myHash(const string& s)
{
    long long ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret *= SMALL_PRIME; //shift over by one
        ret += s[i]; //add the current char
        ret %= BIG_PRIME; //don't overflow
    }
    return ret;
}
​
long long myPow(int base, int exponent) {
    long long ret = 1;
    for (int i = 0; i < exponent; i++) {
        ret = (ret * base) % BIG_PRIME;
    }
    return ret;
}
​
class Solution {
public:
    int distinctEchoSubstrings(string& text) {
        unordered_map<int, unordered_map<int, long long>> substrHashes;
        long long ogHash = 0;
        for (int subLen = 1; subLen <= text.size() / 2; subLen++) {
            ogHash = (ogHash * SMALL_PRIME + text[subLen - 1]) % BIG_PRIME;
            long long initHash = ogHash;
            
            substrHashes[0][subLen - 1] = initHash;
            long long power = myPow(SMALL_PRIME, subLen); // memo
            // cout << text.substr(0, subLen) << "\t" << initHash << endl;
            for (int i = 0; i <= text.size() - subLen - 1; i++) {
                initHash = (initHash * SMALL_PRIME + text[i + subLen]) % BIG_PRIME;
                initHash = (initHash - power * text[i]) % BIG_PRIME;
                if (initHash < 0) {initHash += BIG_PRIME;}
                
                substrHashes[i + 1][i + subLen] = initHash;
                // cout << text.substr(i + 1, subLen) << "\t" << initHash << endl;
            }
        }
        
        unordered_set<string> hits;
        // for (int subLen = 1; subLen <= text.size() / 2; subLen++) {
        //     for (int i = 0; i <= text.size() - 2 * subLen; i++) {
        //         if (substrHashes[i][i + subLen - 1] == substrHashes[i + subLen][i + subLen + subLen - 1]) {
        //             hits.insert(text.substr(i, subLen * 2));
        //         }
        //     }
        // }
        return hits.size();
    }
};
