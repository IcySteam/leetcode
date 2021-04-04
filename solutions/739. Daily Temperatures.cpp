class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> output(T.size(), 0);
        stack<int> pendingIndexes;
        pendingIndexes.push(0);
        for (int i = 1; i < T.size(); i++) {
            while (!pendingIndexes.empty()) {
                int top = pendingIndexes.top();
                if (T[top] < T[i]) {
                    pendingIndexes.pop();
                    output[top] = i - top;
                }
                else {break;}
            }
            pendingIndexes.push(i);
        }
        return output;
    }
};
