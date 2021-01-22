class Solution { // O(n^2)
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int>> my_max_heap; // max heap
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                my_max_heap.push(matrix[i][j]);
                if (my_max_heap.size() > k) {my_max_heap.pop();}
            }
        }
        return my_max_heap.top();
    }
};
​
// pending binary search solution
