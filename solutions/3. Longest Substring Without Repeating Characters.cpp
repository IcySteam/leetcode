class Solution {
public:
    int lengthOfLongestSubstring(string& s) 
    {
        unordered_set<char> mySet;
        int lastDuplicate = -1, currentIndex = 0, output = 0;
        while (lastDuplicate < (int)s.size() && currentIndex < s.size()) { // oof dat auto conversion from signed to unsigned
            // cout << lastDuplicate << "\t" << currentIndex << endl;
            if (mySet.find(s[currentIndex]) == mySet.end()) {
                mySet.insert(s[currentIndex]);
                output = max({output, currentIndex - lastDuplicate});
                currentIndex++;
            }
            else {
                lastDuplicate++;
                mySet.erase(s[lastDuplicate]);
            }
        }
        return output;
    }
};
​
