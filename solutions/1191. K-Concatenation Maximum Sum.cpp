class Solution {
public:
    const long long BIG_PRIME = 1000000007;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sumAll = 0;
        for (int i = 0; i < arr.size(); i++) {sumAll += (long long)arr[i];}
        
        vector<long long> leftSums(arr.size(), 0);
        vector<long long> rightSums(arr.size(), 0);
        leftSums[0] = (long long)arr[0];
        rightSums[arr.size() - 1] = (long long)arr[arr.size() - 1];
        for (int i = 1; i < arr.size(); i++) {
            leftSums[i] = leftSums[i - 1] + (long long)arr[i];
        }
        for (int i = arr.size() - 2; i >= 0; i--) {
            rightSums[i] = rightSums[i + 1] + (long long)arr[i];
        }
        
        long long maxLSum = LLONG_MIN, maxRSum = LLONG_MIN, minLSum = LLONG_MAX, minRSum = LLONG_MAX;
        for (int i = 0; i < arr.size(); i++) {
            maxLSum = leftSums[i] > maxLSum? leftSums[i] : maxLSum;
            maxRSum = rightSums[i] > maxRSum? rightSums[i] : maxRSum;
            minLSum = leftSums[i] < minLSum? leftSums[i] : minLSum;
            minRSum = rightSums[i] < minRSum? rightSums[i] : minRSum;
        }
        maxLSum = maxLSum > 0? maxLSum : 0;
        maxRSum = maxRSum > 0? maxRSum : 0;
        minLSum = minLSum < 0? minLSum : 0;
        minRSum = minRSum < 0? minRSum : 0;
        
        long long temp0 = sumAll * k;
        temp0 = temp0 - minLSum - minRSum;
        int temp1 = (int)(temp0 % BIG_PRIME);
        if (sumAll > 0) {return temp1;}
        
        vector<long long> dp(arr.size(), 0);
        dp[0] = (long long)arr[0];
        for (int i = 1; i < arr.size(); i++) {
            long long a = (long long)dp[i - 1] + (long long)arr[i];
            long long b = (long long)arr[i];
            dp[i] = a > b? a : b;
        }
        long long midLongLong = *max_element(dp.begin(), dp.end());
        int midInt = max({(int)(midLongLong % BIG_PRIME), 0});
        
        long long maxLRSum = maxLSum + maxRSum;
        int maxLRSumInt = (int)(maxLRSum % BIG_PRIME);
        if (k == 1) {maxLRSumInt = 0;}
        // cout << midInt << "\t" << maxLRSumInt << endl;
        return max({maxLRSumInt, midInt});
    }
};
