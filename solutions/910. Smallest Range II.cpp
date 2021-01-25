// heuristics; passed 62/68 test cases
/*
class Solution {}
public:
    int smallestRangeII(vector<int>& A, int K) {
        // vector<int> A_org;
        // A_org = A;
        sort(A.begin(), A.end());
        int min1 = A[A.size() - 1] - A[0];
        float mid = ((A[0] + A[A.size() - 1]) / 2);
        // cout << mid << endl;
        for (auto& ele : A) {
            if (ele <= mid) {ele += K;}
            else {ele -= K;}
        }
        sort(A.begin(), A.end());
        // for (const auto& ele : A) {
        //     cout << ele << " ";
        // }
        //cout << endl;
        int min2 = A[A.size() - 1] - A[0];
        return min(min1, min2);
    }
};
*/
​
// linear scan algorithm: sort first; for every element in the sorted array, if we were to shift this element to the right, then every element that comes before it has to be shifted right, and every element that comes after it has to be shifted left, and vice versa.
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int output = A[A.size() - 1] - A[0];
        for (int i = 0; i < A.size() - 1; i++) {
            int variationMin = min(A[0] + K, A[i + 1] - K);
            int variationMax = max(A[i] + K, A[A.size() - 1] - K);
            if (variationMax - variationMin < output) {output = variationMax - variationMin;}
        }
        return output;
    }        
};
