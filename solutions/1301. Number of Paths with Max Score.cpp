                }
            }
            if (startX >= 1) {
                int newValue = (int)board[startX - 1][startY] - '0';
                if (newValue != 40) {
                    int passedCurrentSum = currentSum;
                    if (newValue >= 1 && newValue <= 9) {passedCurrentSum += newValue;}
                    DFS(board, startX - 1, startY, passedCurrentSum);
                }
            }
            if (startY >= 1) {
                int newValue = (int)board[startX][startY - 1] - '0';
                if (newValue != 40) {
                    int passedCurrentSum = currentSum;
                    if (newValue >= 1 && newValue <= 9) {passedCurrentSum += newValue;}
                    DFS(board, startX, startY - 1, passedCurrentSum);
                }
            }
        }
    }
};
*/
​
// DP approach
class Solution {
public:
    vector<vector<int>> maxSums;
    vector<vector<int>> pathCountCache;
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int sizeX = (int)board.size();
        int sizeY = (int)board[0].length();
        maxSums.clear();
        pathCountCache.clear();
        for (int i = 0; i < sizeX; i++) {
            vector<int> emptyRowVector;
            maxSums.push_back(emptyRowVector);
            pathCountCache.push_back(emptyRowVector);
            for (int j = 0; j < sizeY; j++) {
                maxSums[i].push_back(-1);
                pathCountCache[i].push_back(-1);
            }
        }
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                maxSums[i][j] = getMaxSum(board, i, j);
            }
        }
        
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                cout << maxSums[i][j] << "\t";
            }
            cout << endl;
        }
        int maxSum = maxSums[sizeX - 1][sizeY - 1];
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
