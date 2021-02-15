// no idea why this doesn't work while the second one, which is virtually identical, does
/*
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> mySet;
        for (auto ele : arr) {mySet.insert(ele);}
        int output = 0;
        for (int i = 0; i < arr.size() - 2; i++) {
            int seed1 = arr[i];
            for (int j = i + 1; j < arr.size() - 1; j++) {
                int seed2 = arr[j];
                int currentLen = 2;
                while (mySet.find(seed1 + seed2) != mySet.end()) {
                    currentLen++;
                    int sum12 = seed1 + seed2;
                    seed1 = seed2;
                    seed2 = sum12;
                }
                output = currentLen >= 3? max({output, currentLen}) : output;
            }
        }
        return output;
    }
};
*/
​
// copied solution
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        unordered_set<int> S(A.begin(), A.end());
​
        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j) {
                /* With the starting pair (A[i], A[j]),
                 * y represents the future expected value in
                 * the fibonacci subsequence, and x represents
                 * the most current value found. */
                int x = A[j], y = A[i] + A[j];
                int length = 2;
                while (S.find(y) != S.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    ans = max(ans, ++length);
                }
            }
​
        return ans >= 3 ? ans : 0;
    }
};
