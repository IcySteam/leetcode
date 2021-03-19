class Solution {
public:
    int lengthOfLongestSubstring(string& s) 
    {
        unordered_set<char> mySet;
        int duplicateTracker = -1, currentIndex = 0, output = 0;
        while (duplicateTracker < (int)s.size() && currentIndex < s.size()) { // oof dat auto conversion from signed to unsigned
            // cout << duplicateTracker << "\t" << currentIndex << endl;
            if (mySet.find(s[currentIndex]) == mySet.end()) {
                mySet.insert(s[currentIndex]);
                output = max({output, currentIndex - duplicateTracker});
                currentIndex++;
            }
            else {
                duplicateTracker++;
                mySet.erase(s[duplicateTracker]);
            }
        }
        return output;
    }
};
​
