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
// new DP solution at O(n)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int BIG_PRIME = 1000000007;
        if (!arr.size()) {return 0;}
        vector<int> odds; // can only keep last vals to improve space complexity to O(1)
        vector<int> evens;
        if (arr[0] % 2 == 0) {
            evens.push_back(1);
            odds.push_back(0);
        }
        else {
            evens.push_back(0);
            odds.push_back(1);
        }
        int output = odds[0];
        for (int i = 1; i < arr.size(); i++) {
            int lastOdd = odds[i - 1];
            int lastEven = evens[i - 1];
            if (arr[i] % 2 == 0) {
                evens.push_back(lastEven + 1);
                odds.push_back(lastOdd);
            }
            else {
                evens.push_back(lastOdd);
                odds.push_back(lastEven + 1);
            }
            output = (output + odds[odds.size() - 1]) % BIG_PRIME;
        }
        return output;
    }
};
​
    
​
