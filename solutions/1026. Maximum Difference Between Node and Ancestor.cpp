/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// slow but it's O(n)
class Solution {
public:
    unordered_map<TreeNode*, vector<int>> myMap;
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {return 0;}
        myMap.clear();
        vector<int> initVector{-1, -1};
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myMap[front] = initVector;
            if (front->left != nullptr) {myQueue.push(front->left);}
            if (front->right != nullptr) {myQueue.push(front->right);}
            myQueue.pop();
        }
        myQueue.push(root);
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            myMap[front] = getMinMax(front);
            if (front->left != nullptr) {myQueue.push(front->left);}
            if (front->right != nullptr) {myQueue.push(front->right);}
            myQueue.pop();
        }
        int output = 0;
        myQueue.push(root);
        while (!myQueue.empty()) {
            TreeNode* front = myQueue.front();
            vector<int> candidates{0};
            if (myMap[front][0] != -1) {candidates.push_back(abs(front->val - myMap[front][0]));}
            if (myMap[front][1] != -1) {candidates.push_back(abs(front->val - myMap[front][1]));}
            int max = *max_element(candidates.begin(), candidates.end());
            if (max > output) {output = max;}
            if (front->left != nullptr) {myQueue.push(front->left);}
            if (front->right != nullptr) {myQueue.push(front->right);}
            myQueue.pop();
        }
        return output;
    }
    vector<int> getMinMax(TreeNode* node) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            vector<int> initVector{-1, -1};
            return initVector;
        }
        if (myMap[node][0] != -1 && myMap[node][1] != -1) {
            return myMap[node];
        }
        int min, max;
        vector<int> candidates;
        if (node->left != nullptr) {candidates.push_back(node->left->val);}
        if (node->right != nullptr) {candidates.push_back(node->right->val);}
        if (getMinMax(node->left)[0] != -1) {candidates.push_back(getMinMax(node->left)[0]);}
        if (getMinMax(node->left)[1] != -1) {candidates.push_back(getMinMax(node->left)[1]);}
        if (getMinMax(node->right)[0] != -1) {candidates.push_back(getMinMax(node->right)[0]);}
        if (getMinMax(node->right)[1] != -1) {candidates.push_back(getMinMax(node->right)[1]);}
        min = *min_element(candidates.begin(), candidates.end());
        max = *max_element(candidates.begin(), candidates.end());
        vector<int> output{min, max};
        myMap[node] = output;
        return output;
    }
};
​
