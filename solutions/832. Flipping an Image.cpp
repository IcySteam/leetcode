class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> output;
        vector<int> empty;
        for (int i = 0; i < A.size(); i++) {output.push_back(empty);}
        for (int i = 0; i < A.size(); i++) {
            for (int j = A.size() - 1; j >= 0; j--) {
                output[i].push_back(A[i][j] == 0? 1 : 0);
            }
        }
        return output;
    }
};
