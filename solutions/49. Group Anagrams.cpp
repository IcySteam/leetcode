class Solution {
public:
    unordered_map<string,string> strToSet;
    
    string convertToSet(string& inStr) {
        if (strToSet.find(inStr) != strToSet.end()) {return strToSet[inStr];}
        vector<int> letterCount(26, 0);
        for (int i = 0; i < inStr.size(); i++) {
            letterCount[inStr[i] - 97]++;
        }
        string output = "";
        for (int i = 0; i < letterCount.size(); i++) {
            output.append(to_string(letterCount[i]));
            output.push_back(',');
        }
        strToSet[inStr] = output;
        return output;
    }
​
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int currentIndex = 0;
        unordered_map<string, int> setToIndex;
        for (int i = 0; i < strs.size(); i++) {
            string letterCountStr = convertToSet(strs[i]);
            if (setToIndex.find(letterCountStr) == setToIndex.end()) {
                setToIndex[letterCountStr] = currentIndex;
                currentIndex++;
            }
        }
        
        vector<vector<string>> output(setToIndex.size());
        for (int i = 0; i < strs.size(); i++) {
            int thisIndex = setToIndex[convertToSet(strs[i])];
            output[thisIndex].push_back(strs[i]);
        }
        return output;
    }
};
