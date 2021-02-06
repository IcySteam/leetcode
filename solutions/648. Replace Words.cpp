// set O(n^2)
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> mySet;
        for (auto& ele : dictionary) {mySet.insert(ele);}
        vector<string> words;
        string word = "";
        for (auto& letter : sentence) 
        {
            if (letter == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else {
                word.push_back(letter);
            }
        }
        words.push_back(word);
        string output = "";
        for (auto& word : words) {
            string currentWord = "";
            bool wordComplete = false;
            for (auto& letter : word) {
                if (wordComplete == false) {
                    currentWord.push_back(letter);
                    if (mySet.find(currentWord) != mySet.end()) {
                        output.append(currentWord + " ");
                        wordComplete = true;
                    }
                }
            }
            if (wordComplete == false) {output.append(word + " ");}
        }
        return output.substr(0, output.size() - 1);
    }
};
​
// trie TO BE IMPLEMENTED
