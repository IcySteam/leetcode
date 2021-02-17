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
    vector<int> arr1;
    vector<int> arr2;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        arr1.clear();
        arr2.clear();
        DFS(root1, arr1);
        DFS(root2, arr2);
        vector<int> output = merge(arr1, arr2);
        return output;
    }
    void DFS(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) {return;}
        if (node->left != nullptr) {DFS(node->left, arr);}
        arr.push_back(node->val);
        if (node->right != nullptr) {DFS(node->right, arr);}
    }
    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        vector<int> output;
        int index1 = 0;
        int index2 = 0;
        while (index1 < arr1.size() || index2 < arr2.size()) {
            if (index1 >= arr1.size() || index2 >= arr2.size()) {
                if (index1 >= arr1.size()) {
                    output.push_back(arr2[index2]);
                    index2++;
                }
                else if (index2 >= arr2.size()) {
                    output.push_back(arr1[index1]);
                    index1++;
                }
            }
            else if (arr1[index1] <= arr2[index2]) {
                output.push_back(arr1[index1]);
                index1++;
            }
            else if (arr1[index1] > arr2[index2]){
                output.push_back(arr2[index2]);
                index2++;
            }
        }
        return output;
    }
};
