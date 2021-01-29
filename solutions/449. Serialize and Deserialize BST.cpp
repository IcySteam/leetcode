/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {return "";}
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        string output = "";
        output.append(to_string(root->val) + ",");
        while (!myQueue.empty()) {
            int sizePre = myQueue.size();
            bool allNull = true;
            for (int i = 0; i < sizePre; i++) {
                TreeNode* front = myQueue.front();
                if (front != nullptr) {
                    if (front->left == nullptr) {
                        output.append("n,");
                        myQueue.push(nullptr);
                    }
                    else {
                        allNull = false;
                        output.append(to_string(front->left->val) + ",");
                        myQueue.push(front->left);
                    }
                    if (front->right == nullptr) {
                        output.append("n,");
                        myQueue.push(nullptr);
                    }
                    else {
                        allNull = false;
                        output.append(to_string(front->right->val) + ",");
                        myQueue.push(front->right);
                    }
                }
                else {
                    output.append("n,");
                    output.append("n,");
                    myQueue.push(nullptr);
                    myQueue.push(nullptr);
                }
                myQueue.pop();
            }
            if (allNull) {break;}
