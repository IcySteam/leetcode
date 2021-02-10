class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        map<vector<int>, double> probs; // could use vector of unordered_maps to improve time complexity
        for (int i = 0; i < edges.size(); i++) {
            vector<int> revEdge{edges[i][1], edges[i][0]};
            probs[edges[i]] = succProb[i];
            probs[revEdge] = succProb[i];
        }
        unordered_map<int, set<int>> graph; // not necessary actually
        set<int> emptySet;
        for (int i = 0; i < n; i++) {graph[i] = emptySet;}
        for (auto& ele : edges) {
            int a = ele[0];
            int b = ele[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        vector<double> visitedProbs(n, 0);
        visitedProbs[start] = 1;
        
        queue<int> myQueue;
        myQueue.push(start);
        while (!myQueue.empty()) {
            int front = myQueue.front();
            for (auto it = graph[front].begin(); it != graph[front].end(); it++) {
                vector<int> edgeVector{front, *it};
                double newProb = visitedProbs[front] * probs[edgeVector];
                if (newProb > visitedProbs[*it]) { // acts as log keeping, IMPORTANT
                    visitedProbs[*it] = newProb;
                    myQueue.push(*it);
                }
            }
            myQueue.pop();
        }
        return visitedProbs[end];
    }
};
