class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int waiting = 0;
        int max_profit = 0;
        int current_profit = 0;
        int current_rotation = 0;
        int max_rotation = 0;
        for (int i = 0; i < customers.size(); i++) {
            current_rotation++;
            waiting += customers[i];
            if (waiting < 4) {
                current_profit += waiting * boardingCost - runningCost;
                waiting = 0;
            }
            else {
                current_profit += 4 * boardingCost - runningCost;
                waiting -= 4;
            }
            if (current_profit > max_profit) {
                max_profit = current_profit;
                max_rotation = current_rotation;
            }
        }
        while (waiting > 0) {
            current_rotation++;
            if (waiting < 4) {
                current_profit += waiting * boardingCost - runningCost;
                waiting = 0;
            }
            else {
                current_profit += 4 * boardingCost - runningCost;
                waiting -= 4;
            }
            if (current_profit > max_profit) {
                max_profit = current_profit;
                max_rotation = current_rotation;
            }
        }
        if (max_profit <= 0) {return -1;}
        else {return max_rotation;}
    }
};
