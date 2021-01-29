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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> output;
        if (root == nullptr) {return output;}
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int depth = 0;
        while (!myQueue.empty()) {
            int sizePre = myQueue.size();
            int maxNode = -2147483648;
            for (int i = 0; i < sizePre; i++) {
                TreeNode* front = myQueue.front();
                maxNode = max(maxNode, front->val);
                if (front->left != nullptr) {myQueue.push(front->left);}
                if (front->right != nullptr) {myQueue.push(front->right);}
                myQueue.pop();
            }
            depth++;
            output.push_back(maxNode);
        }
        return output;
    }
};
