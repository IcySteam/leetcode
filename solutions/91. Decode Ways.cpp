class Solution {
public:
    int countValid = 0;
    vector<int> memo;
    
    int DFS(string& s, int start) {
        if (start >= s.size()) {
            return 1;
        }
        
        if (memo[start] != -1) {return memo[start];}
        
        if (s[start] == '0') {return 0;}
        
        if (s[start] == '1') {
            int res = DFS(s, start + 1);
            if (start + 1 < s.size()) {
                res += DFS(s, start + 2);
            }
            memo[start] = res;
            return res;
        }
        else if (s[start] == '2') {
            int res = DFS(s, start + 1);
            if (start + 1 < s.size()) {
                if (s[start + 1] >= '0' && s[start + 1] <= '6') {
                    res += DFS(s, start + 2);
                }
            }
            memo[start] = res;
            return res;
        }
        else {
            int res = DFS(s, start + 1);
            memo[start] = res;
            return res;
        }
    }
    
    int numDecodings(string& s) {
        vector<int> memo_temp(s.size(), -1);
        memo = memo_temp;
        return DFS(s, 0);
    }
};
