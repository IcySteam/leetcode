// pure BFS TOO SLOW
/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<list<vector<int>>> myGraph;
        list<vector<int>> myEmptyList;
        for (int i = 0; i < n; i++) {myGraph.push_back(myEmptyList);}
        for (auto& ele : flights) {
            vector<int> thisFlight;
            thisFlight.push_back(ele[1]);
            thisFlight.push_back(ele[2]);
            myGraph[ele[0]].push_back(thisFlight);
        }
        //cout << myGraph[0].back()[1] << endl; // testing adjacency list
        int minCost = -1;
        queue<vector<int>> myQueue;
        vector<int> seed{src, 0};
        myQueue.push(seed);
        for (int i = -1; i < K; i++) {
            queue<vector<int>> myQueueCpy = myQueue;
            while (!myQueueCpy.empty()) {
                vector<int> front = myQueueCpy.front();
                if (front[0] == dst && (front[1] <= minCost || minCost == -1)) {minCost = front[1];}
                myQueueCpy.pop();
            }
            int queueSizePre = myQueue.size();
            for (int j = 0; j < queueSizePre; j++) {
                vector<int> front = myQueue.front();
                for (auto it = myGraph[front[0]].begin(); it != myGraph[front[0]].end(); it++) {
                    vector<int> thisPush;
                    thisPush.push_back((*it)[0]);
                    thisPush.push_back(front[1] + (*it)[1]);
                    myQueue.push(thisPush);
                }
                myQueue.pop();
            }
        }
        while (!myQueue.empty()) {
            vector<int> front = myQueue.front();
            if (front[0] == dst && (front[1] <= minCost || minCost == -1)) {minCost = front[1];}
            myQueue.pop();
        }
        return minCost;
    }
};
*/
​
// Dijkstra
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<list<vector<int>>> myGraph;
        list<vector<int>> myEmptyList;
        for (int i = 0; i < n; i++) {myGraph.push_back(myEmptyList);}
        for (auto& ele : flights) {
            vector<int> thisFlight;
            thisFlight.push_back(ele[1]);
            thisFlight.push_back(ele[2]);
            myGraph[ele[0]].push_back(thisFlight);
        }
        //cout << myGraph[0].back()[1] << endl; // testing adjacency list
        int minCost = -1;
        queue<vector<int>> myQueue;
        vector<int> seed{src, 0};
        myQueue.push(seed);
        for (int i = -1; i < K; i++) {
            queue<vector<int>> myQueueCpy = myQueue;
            while (!myQueueCpy.empty()) {
                vector<int> front = myQueueCpy.front();
                if (front[0] == dst && (front[1] <= minCost || minCost == -1)) {minCost = front[1];}
                myQueueCpy.pop();
            }
            int queueSizePre = myQueue.size();
            for (int j = 0; j < queueSizePre; j++) {
                vector<int> front = myQueue.front();
                for (auto it = myGraph[front[0]].begin(); it != myGraph[front[0]].end(); it++) {
                    vector<int> thisPush;
                    thisPush.push_back((*it)[0]);
                    thisPush.push_back(front[1] + (*it)[1]);
                    myQueue.push(thisPush);
                }
                myQueue.pop();
            }
        }
        while (!myQueue.empty()) {
            vector<int> front = myQueue.front();
            if (front[0] == dst && (front[1] <= minCost || minCost == -1)) {minCost = front[1];}
            myQueue.pop();
        }
        return minCost;
    }
};
