// O(n^2) solution; too slow
/*
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int totalNum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int currentSum = 0;
            for (int j = i; j < arr.size(); j++) {
                currentSum += arr[j];
                if (currentSum % 2 != 0) {totalNum++;}
            }
        }
        return totalNum;
    }
};
*/
​
// binary O(n^2) solution; too slow
/*
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> arrBin;
        for (auto ele : arr) {arrBin.push_back(ele % 2);}
        int totalNum = 0; 
        for (int i = 0; i < arrBin.size(); i++) {
            bool currentSum = false; // false for odd
            for (int j = i; j < arrBin.size(); j++) {
                currentSum = arrBin[j] == 1 ? !currentSum : currentSum;
                if (currentSum) {totalNum++;}
            }
        }
        return totalNum;
    }
};
*/
​
// new solution at O(n) TBD
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> arrBin;
        for (auto ele : arr) {arrBin.push_back(ele % 2);}
        int totalNum = 0; 
        for (int i = 0; i < arrBin.size(); i++) {
            bool currentSum = false; // false for odd
            for (int j = i; j < arrBin.size(); j++) {
                currentSum = arrBin[j] == 1 ? !currentSum : currentSum;
                if (currentSum) {totalNum++;}
            }
        }
        return totalNum;
    }
};
