class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (!words.size()) {return 0;}
        vector<unordered_set<char>> sets;
        for (auto& word : words) {
            unordered_set<char> mySet;
            for (auto& letter : word) {
                mySet.insert(letter);
            }
            sets.push_back(mySet);
        }
        int output = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            int currentMax = 0;
            string& currentWord = words[i];
            unordered_set<char>& currentSet = sets[i];
            for (int j = i + 1; j < words.size(); j++) {
                bool distinct = true;
                string& targetWord = words[j];
                unordered_set<char>& targetSet = sets[j];
                for (auto it = currentSet.begin(); it != currentSet.end(); it++) {
                    if (targetSet.find(*it) != targetSet.end()) {
                        distinct = false;
                        break;
                    }
                }
                if (distinct) {currentMax = max({currentMax, (int)(currentWord.size() * targetWord.size())});}
            }
            output = max({output, currentMax});
        }
        return output;
    }
};
