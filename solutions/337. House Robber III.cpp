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
    unordered_map<TreeNode*, int> cache;
    int rob(TreeNode* root) {
        if (root == nullptr) {return 0;}
        if (root->left == nullptr && root->right == nullptr) {return root->val;}
        if (cache.find(root) != cache.end()) {return cache[root];}
        vector<int> candidates;
        int temp0 = 0, temp1 = 0, temp2 = 0, temp3 = 0;
        if (root->left != nullptr) {
            temp0 = rob(root->left->left);
            temp1 = rob(root->left->right);
        }
        if (root->right != nullptr) {
            temp2 = rob(root->right->left);
            temp3 = rob(root->right->right);
        }
        candidates.push_back(root->val + temp0 + temp1 + temp2 + temp3);
        candidates.push_back(rob(root->left) + rob(root->right));
        int result = *max_element(candidates.begin(), candidates.end());
        cache[root] = result;
        return result;
    }
};
