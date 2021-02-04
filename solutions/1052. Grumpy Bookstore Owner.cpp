class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int initSum = 0;
        for (int i = 0; i < customers.size(); i++) {
            initSum += grumpy[i] == 0? customers[i] : 0;
        }
        
        int windowSumHigh = 0;
        int windowSumLow = 0;
        for (int i = 0; i < X; i++) {
            windowSumHigh += customers[i];
            windowSumLow += grumpy[i] == 0? customers[i] : 0;
        }
        int output = initSum - windowSumLow + windowSumHigh;
        int windowStart = 1;
        while (windowStart <= customers.size() - X) {
            windowSumLow -= grumpy[windowStart - 1] == 0? customers[windowStart - 1] : 0;
            windowSumLow += grumpy[windowStart - 1 + X] == 0? customers[windowStart - 1 + X] : 0;
            windowSumHigh -= customers[windowStart - 1];
            windowSumHigh += customers[windowStart - 1 + X];
            output = max({output, initSum - windowSumLow + windowSumHigh});
            windowStart++;
        }
        return output;
    }
};
