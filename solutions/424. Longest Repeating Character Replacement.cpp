//                 if (s[p2] == s[p1]) {
//                     lastCount++;
//                     p2++;
//                 }
//                 else {
//                     if (rem_k > 0) {
//                         rem_k--;
//                         lastCount++;
//                         p2++;
//                     }
//                     else {
//                         char tmp = s[p1];
//                         while (p1 < s.size()) {
//                             if (s[p1] != tmp) {break;}
//                             last = s[p1];
//                             p1++;
//                         }
//                         if (p1 >= s.size()) {break;}
//                         p2 = p1 + 1;
//                         rem_k = k;
//                         myMap[tmp] = max({myMap[tmp], lastCount});
//                         lastCount = 1;
//                         if (myMap.find(s[p1]) == myMap.end()) {myMap[s[p1]] = 1;}
//                     }
//                 }
//             }
//         }
//         if (myMap.find(last) == myMap.end()) {myMap[last] = 1;}
//         else {myMap[last] = max({myMap[last], lastCount});}
        
//         int res = 0;
//         for (auto it = myMap.begin(); it != myMap.end(); it++) {
//             res = max({res, it->second});
//         }
//         return res;
//     } 
// };
​
// sliding window with count and majority tracking
class Solution {
public:
    int characterReplacement(string s, int k) {
        if (!s.size()) {return 0;}
        unordered_map<char, int> window;
        int p1 = 0, p2 = 1;
        window[s[p1]]++;
        int res = 0;
        
        while (p1 < s.size()) {
            char mode;
            int modeCount = 0;
            int newRes = 0;
            int uniqueChars = 0;
            for (auto it = window.begin(); it != window.end(); it++) {
                if (it->second > 0) {uniqueChars++;}
                newRes += it->second;
                if (it->second > modeCount) {
                    mode = it->first;
                    modeCount = it->second;
                }
            }
            res = max({res, newRes});
            int k_used = newRes - modeCount;
            // cout << k_used << endl;
            
            if (p2 < s.size()) {
                if ((modeCount != 0 && s[p2] == mode) || modeCount == 0) {
                    window[s[p2]]++;
                    p2++;
                }
                else {
                    if (k_used < k) {
                        window[s[p2]]++;
                        p2++;
                    }
                    else {
                        window[s[p1]]--;
                        p1++;
                    }
                }
            }
