class Solution {
public:
    vector<int> results;
    int numberOfMatches(int n) {
        results.push_back(-1);
        for (int i = 0; i < n; i++) {results.push_back(-1);}
        return getResult(n);
    }
    int getResult(int n) {
        if (n == 1) {return 0;}
        else if (n == 2) {return 1;}
        else if (results[n] != -1) {return results[n];}
        else {
            if (n % 2 == 0) {
                return n / 2 + getResult(n / 2);
            }
            else {
                return (n - 1) / 2 + getResult((n - 1) / 2) + 1;
            }
        }
    }
};
