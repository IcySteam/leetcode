class Solution {
public:
    unordered_map<int, int> result_dict;
    
    Solution() {
        result_dict[1] = 1;
        result_dict[2] = 2;
    }
    
    int numTrees(int n) {
        if (result_dict.find(n) != result_dict.end()) {
            return result_dict[n];
        }
        else {
            int result = 0;
            for (int i = 1; i <= n; i++) {
                if (i == 1 || i == n) {result += numTrees(n - 1);}
                else {
                    result += numTrees(i - 1) * numTrees(n - i);
                }
            }
            result_dict[n] = result;
            return result;
        }
    }
    
    int factorial(int n) {
        if (n == 0 || n == 1) {return 1;}
        else {
            return n * (factorial(n - 1));
        }
    }
};
