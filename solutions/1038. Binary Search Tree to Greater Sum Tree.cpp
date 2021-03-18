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
    map<int, int> countMap;
    void iOTBuildCountMap(TreeNode* node) {
        if (node == nullptr) {return;}
        iOTBuildCountMap(node->left);
        countMap[node->val]++;
        iOTBuildCountMap(node->right);
    }
    TreeNode* iOTBuildOutput(TreeNode* node, unordered_map<int, int> & myMap) {
        if (node == nullptr) {return nullptr;}
        TreeNode* output = new TreeNode();
        output->left = iOTBuildOutput(node->left, myMap);
        output->val = myMap[node->val];
        output->right = iOTBuildOutput(node->right, myMap);
        return output;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if (root == nullptr) {return nullptr;}
        if (root->left == nullptr && root->right == nullptr) {return root;}
        iOTBuildCountMap(root);
        
        unordered_map<int, int> myMap;
        int currentRes = next(countMap.end(), -1)->first * next(countMap.end(), -1)->second;
        myMap[next(countMap.end(), -1)->first] = currentRes;
        auto iterStart = next(countMap.end(), -2);
        for (auto it = iterStart; ; it--) {
            int currentNum = it->first;
            int currentProduct = currentNum * countMap[currentNum];
            myMap[currentNum] = currentRes + currentProduct;
            // cout << currentNum << "\t" << myMap[currentNum] << endl;
            currentRes += currentProduct;
            if (it == countMap.begin()) {break;}
        }
        
        TreeNode* output = iOTBuildOutput(root, myMap);
        // assert(myMap[root->val] == output->val);
        return output;
    }
};
