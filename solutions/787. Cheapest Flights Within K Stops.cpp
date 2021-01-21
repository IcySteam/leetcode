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
        for (int i = 0; i < n; i++) { // myGraph debug
            cout << i << "\t";
            for (auto it = myGraph[i].begin(); it != myGraph[i].end(); it++) {
                cout << (*it)[0] << " " << (*it)[1] << "\t";
            }
            cout << endl;
        }
        vector<int> minCosts;
        for (int i = 0; i < n; i++) {minCosts.push_back(-1);}
        minCosts[src] = 0;
        queue<int> myQueue;
        myQueue.push(src);
        for (int i = 0; i < K + 1; i++) {
            if (myQueue.empty()) {break;}
            vector<int> minCostsPre = minCosts;
            int queueSizePre = myQueue.size();
            for (int j = 0; j < queueSizePre; j++) {
                int front = myQueue.front();
                for (auto it = myGraph[front].begin(); it != myGraph[front].end(); it++) {
                    if ((minCosts[(*it)[0]] == -1) || (minCosts[(*it)[0]] > minCosts[front] + (*it)[1])) {
                        minCosts[(*it)[0]] = minCostsPre[front] + (*it)[1]; // OMFG this took me so long
                        myQueue.push((*it)[0]);
                    }
                }
                myQueue.pop();
            }
        }
        return minCosts[dst];
    }
};
