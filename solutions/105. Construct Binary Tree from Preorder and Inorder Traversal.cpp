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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        int size = preorder.size();
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < size; ++i) {inorderMap[inorder[i]] = i;}
        return buildFromPreorder(preorder, inorder, inorderMap, 0, size - 1, 0, size - 1);
    }
    
    TreeNode* buildFromPreorder(const vector<int>& preorder, const vector<int>& inorder, const unordered_map<int, int>& inorderMap, int lowerPre, int upperPre, int lowerIn, int upperIn) {
        if (lowerPre > upperPre) {return nullptr;}
        TreeNode* currentRoot = new TreeNode(preorder[lowerPre]);
        int leftTreeSize = inorderMap.at(currentRoot->val) - lowerIn;
        int rightTreeSize = upperIn - inorderMap.at(currentRoot->val);
        currentRoot->left = buildFromPreorder(preorder, inorder, inorderMap, lowerPre + 1, lowerPre + leftTreeSize, lowerIn, inorderMap.at(currentRoot->val) - 1);
        currentRoot->right = buildFromPreorder(preorder, inorder, inorderMap, lowerPre + leftTreeSize + 1, lowerPre + leftTreeSize + rightTreeSize, inorderMap.at(currentRoot->val) + 1, upperIn);
        return currentRoot;
    }
};
