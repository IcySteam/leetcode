//         int n = slices.size() / 3;
//         vector<vector<int>> dp(n, vector<int>(m, 0));
//         for (int i = 0; i < n; i++) {
//             if (i == 0) {
//                 for (int j = 0; j < m; j++) {dp[0][j] = slices[j + start];}
//             }
//             else {
//                 for (int j = 0; j < m; j++) {
//                     if (j >= 2) {dp[i][j] = *max_element(dp[i - 1].begin(), dp[i - 1].begin() + j - 1) + slices[j + start];}
//                     else {dp[i][j] = dp[i - 1][j];}
//                 }
//             }
//         }
//         return *max_element(dp[n - 1].begin(), dp[n - 1].end());
//     }
// };
// // https://leetcode-cn.com/problems/pizza-with-3n-slices/solution/hua-wei-bu-xiang-lin-de-zi-shu-lie-de-zui-da-he-we/
​
​
​
​
class Node {
public:
    Node(){}
    int index;
    int val;
    Node* left;
    Node* right;
    bool deleted;
    ~Node(){}
};
​
class Compare {
public:
    bool operator() (Node* a, Node* b) {
        if (a->val == b->val) {
            int opportunityCostA = a->left->val + a->right->val;
            int opportunityCostB = b->left->val + b->right->val;
            return opportunityCostA > opportunityCostB;
        }
        return a->val < b->val;
    }
};
​
class Solution {
public:
    int maxSizeSlices(vector<int> &slices) {
        int m = slices.size();
        int n = m / 3;
        vector<Node*> myNodes;
        for (int i = 0; i < m; i++) {myNodes.emplace_back(new Node());}
        for (int i = 0; i < m; i++) {
            int left = i >= 1? i - 1: m - 1;
            int right = i <= m - 2? i + 1 : 0;
            myNodes[i]->index = i;
            myNodes[i]->val = slices[i];
            myNodes[i]->left = myNodes[left];
            myNodes[i]->right = myNodes[right];
            myNodes[i]->deleted = false;
        }
        priority_queue<Node*, vector<Node*>, Compare> myHeap;
        for (int i = 0; i < m; i++) {myHeap.push(myNodes[i]);}
        int output = 0;
        int count = 0;
        while (count < n && !myHeap.empty()) {
            Node* top = myHeap.top();
            myHeap.pop();
            vector<Node*> updating{top, top->left, top->right};
            if (!top->deleted) {
                count++;
                output += top->val;
                
                top->left->left->right = top;
                top->right->right->left = top;
                top->left->deleted = true;
                top->right->deleted = true;
                
                top->val = top->left->val + top->right->val - top->val;
                top->left = top->left->left;
                top->right = top->right->right;
                
                for (auto& ele : updating) {myHeap.push(ele);}
            }
        }
        for (auto& ele : myNodes) {delete ele;}
        return output;
    }
};
// https://leetcode-cn.com/problems/pizza-with-3n-slices/solution/shuang-xiang-lian-biao-tan-xin-suan-fa-shi-jian-fu/
