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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        else if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        else if (nums.size() == 2) {
            return new TreeNode(nums[0], nullptr, new TreeNode(nums[1]));
        }
        else if (nums.size() == 3) {
            return new TreeNode(nums[1], new TreeNode(nums[0]), new TreeNode(nums[2]));
        }
        else {
            int mid = nums.size() / 2;
            vector<int> v1 = vector<int>(nums.begin(), nums.begin() + mid);
            vector<int> v2 = vector<int>(nums.begin() + mid + 1, nums.end());
            return new TreeNode(nums[mid], sortedArrayToBST(v1), sortedArrayToBST(v2));
        }
    }
};
