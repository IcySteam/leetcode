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
    // const static int SUM_UNINITIALIZED = INT_MIN + 69420;
    bool found = false;
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        DFS(root, targetSum, 0);
        return found;
    }
    
    void DFS(TreeNode* node, int target, int currentSum) {
        if (!node || found) {
            return;
        }
        
        currentSum += node->val;
        
        if (!node->left && !node->right && currentSum == target) {
            found = true;
            return;
        }
        
        DFS(node->left, target, currentSum);
        DFS(node->right, target, currentSum);
    }
};
