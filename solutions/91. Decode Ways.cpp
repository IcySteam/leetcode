class Solution {
public:
    int countValid = 0;
    
    void DFS(string& s, int start) {
        if (start >= s.size()) {
            countValid++;
            return;
        }
        
        if (s[start] == '0') {return;}
        
        if (s[start] == '1') {
            DFS(s, start + 1);
            if (start + 1 < s.size()) {
                DFS(s, start + 2);
            }
        }
        else if (s[start] == '2') {
            DFS(s, start + 1);
            if (start + 1 < s.size()) {
                if (s[start + 1] >= '0' && s[start + 1] <= '6') {
                    DFS(s, start + 2);
                }
            }
        }
        else {
            DFS(s, start + 1);
        }
    }
    
    int numDecodings(string& s) {
        DFS(s, 0);
        return countValid;
    }
};
