class Solution {
public:
    vector<vector<int>> distances;
    int size;
    int swimInWater(vector<vector<int>>& grid) {
        size = grid.size();
        vector<vector<int>> thisDistances(size, vector<int>(size, -1));
        distances.clear();
        distances = thisDistances;
        distances[0][0] = grid[0][0];
        queue<vector<int>> myQueue;
        vector<int> start{0, 0};
        myQueue.push(start);
        while (!myQueue.empty()) {
            vector<int> front = myQueue.front();
            vector<vector<int>> adjacents;
            if (front[0] > 0) {
                vector<int> temp{front[0] - 1, front[1]};
                adjacents.push_back(temp);
            }
            if (front[1] > 0) {
                vector<int> temp{front[0], front[1] - 1};
                adjacents.push_back(temp);
            }
            if (front[0] < size - 1) {
                vector<int> temp{front[0] + 1, front[1]};
                adjacents.push_back(temp);
            }
            if (front[1] < size - 1) {
                vector<int> temp{front[0], front[1] + 1};
                adjacents.push_back(temp);
            }
            vector<vector<int>> relaxed;
            for (auto& ele : adjacents) {
                if (distances[ele[0]][ele[1]] == -1 || max({grid[ele[0]][ele[1]], distances[front[0]][front[1]]}) < distances[ele[0]][ele[1]]) {
                    distances[ele[0]][ele[1]] = max({grid[ele[0]][ele[1]], distances[front[0]][front[1]]});
                    relaxed.push_back(ele);
                }
            }
            for (auto ele : relaxed) {myQueue.push(ele);}
            myQueue.pop();
        }   
        return distances[size - 1][size - 1];
    }
};
