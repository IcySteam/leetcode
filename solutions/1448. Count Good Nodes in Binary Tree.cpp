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
    int res = 0;
    
    void DFS(TreeNode* node, int maxVal) {
        if (node == nullptr) {return;}
        if (maxVal <= node->val) {res++;}
        DFS(node->left, max({maxVal, node->val}));
        DFS(node->right, max({maxVal, node->val}));
    }
    
    int goodNodes(TreeNode* root) {
        DFS(root, -10001);
        return res;
    }
};
