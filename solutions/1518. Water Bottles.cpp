class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int output = 0;
        int full = numBottles;
        int empty = 0;
        while (full > 0) {
            output += full;
            empty += full;
            full = 0;
            int emptyTaken = empty - empty % numExchange;
            empty -= emptyTaken;
            full += emptyTaken / numExchange;
        }
        return output;
    }
};
