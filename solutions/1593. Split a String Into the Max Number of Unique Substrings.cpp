class Solution {
public:
    set<string> mySet;
    int maxUniqueSplit(string s) {
        if (s.size() == 0) {return 0;}
        int numSplit = 1;
        int output = 1;
        bool noOption = true;
        for (int i = 1; i <= s.size(); i++) {
            string currentString;
            currentString = s.substr(0, i);
            if (mySet.find(currentString) == mySet.end()) {
                noOption = false;
                mySet.insert(currentString);
                int newVal = maxUniqueSplit(s.substr(i, s.size() - i));
                numSplit += newVal;
                output = max({output, numSplit});
                mySet.erase(currentString);
                numSplit -= newVal;
            }
        }
        return noOption? 0 : output;
    }
};
