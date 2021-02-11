class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {next[i] = nullptr;}
        end = false;
    }
    bool end;
    TrieNode* next[26];
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (next[i] != nullptr) {delete next[i];}
        }
    }
};
​
class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* head;
    bool found;
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = head;
        for (auto& ele : word) {
            int letter = ele - 'a';
            if (current->next[letter] == nullptr) {
                current->next[letter] = new TrieNode();
            }
            current = current->next[letter];
        }
        current->end = true;
    }
    
    bool search(string word) {
        found = false;
        DFS(word, 0, head);
        return found;
    }
    
    void DFS(string& word, int wordPos, TrieNode* currentNode) {
        if (found) {return;}
        if (wordPos == word.size()) {
            if (currentNode->end) {found = true;}
            return;
        }
        if (word[wordPos] != '.') {
            int letter = word[wordPos] - 'a';
            if (currentNode->next[letter] != nullptr) {DFS(word, wordPos + 1, currentNode->next[letter]);}
        }
        else {
            for (int i = 0; i < 26; i++) {
                if (currentNode->next[i] != nullptr) {DFS(word, wordPos + 1, currentNode->next[i]);}
            }
        }
    }
    
    ~WordDictionary() {
        delete head;
    }
};
​
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
