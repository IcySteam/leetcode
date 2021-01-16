        int maxPathCount = getMaxPathCount(maxSums, sizeX - 1, sizeY - 1);
        vector<int> output{maxSum, maxPathCount};
        //cout << maxSum << endl;
        if (maxPathCount == 0) {output[0] = 0;}
        return output;
    }
    
    int getMaxSum(vector<string>& board, int X, int Y) {
        int currentValue = (int)board[X][Y] - '0';
        if (X == 0 && Y == 0) {return 0;}
        else if (currentValue == 40) {return -1;}
        else {
            int val1 = -1;
            int val2 = -1;
            int val3 = -1;
            int plusValue = 0;
            if (currentValue >= 1 && currentValue <= 9) {plusValue = currentValue;}
            if (X >= 1 && Y >= 1) {
                if ((int)board[X - 1][Y - 1] - '0' != 40) {
                    int operandLeft = maxSums[X - 1][Y - 1];
                    if (operandLeft == -1) {val1 = getMaxSum(board, X - 1, Y - 1) + plusValue;}
                    else {val1 = operandLeft + plusValue;}
                }
            }
            if (X >= 1) {
                if ((int)board[X - 1][Y] - '0' != 40) {
                    int operandLeft = maxSums[X - 1][Y];
                    if (operandLeft == -1) {val2 = getMaxSum(board, X - 1, Y) + plusValue;}
                    else {val2 = operandLeft + plusValue;}
                }
            }
            if (Y >= 1) {
                if ((int)board[X][Y - 1] - '0' != 40) {
                    int operandLeft = maxSums[X][Y - 1];
                    if (operandLeft == -1) {val3 = getMaxSum(board, X, Y - 1) + plusValue;}
                    else {val3 = operandLeft + plusValue;}
                }
            }
            return max(max(val1, val2), max(val2, val3));
        }
    }
    
    int getMaxPathCount(vector<vector<int>>& maxSums, int X, int Y) {
        if (X == 0 && Y == 0) {return 1;}
        else {
            int currentValue = maxSums[X][Y];
            if (currentValue == -1) {return 0;}
            int val1 = -1;
            int val2 = -1;
            int val3 = -1;
            if (X >= 1 && Y >= 1) {val1 = maxSums[X - 1][Y - 1];}
            if (X >= 1) {val2 = maxSums[X - 1][Y];}
            if (Y >= 1) {val3 = maxSums[X][Y - 1];}
            int myMax = max(max(val1, val2), max(val2, val3));
            if (myMax == -1) {return 0;}
            
            int component1 = 0;
            int component2 = 0;
            int component3 = 0;
            if (val1 >= myMax) {component1 = getMaxPathCount(maxSums, X - 1, Y - 1);}
            if (val2 >= myMax) {component2 = getMaxPathCount(maxSums, X - 1, Y);}
            if (val3 >= myMax) {component3 = getMaxPathCount(maxSums, X, Y - 1);}
            return component1 + component2 + component3;
        }
        return 0;
    }
};
