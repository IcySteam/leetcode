//         return output;
//     }
    
//     int getDepthFromSize(int size) { // cache to improve runtime
//         int output = 0;
//         int sum = 0;
//         while (sum < size) {
//             sum += pow(2, output);
//             output++;
//         }
//         return output;
//     }
    
//     int getIndexFromDepth(int depth) {
//         int output = 0;
//         for (int i = 0; i < depth; i++) {
//             output += pow(2, i);
//         }
//         return output;
//     }
// };
​
// // Your Codec object will be instantiated and called as such:
// // Codec* ser = new Codec();
// // Codec* deser = new Codec();
// // string tree = ser->serialize(root);
// // TreeNode* ans = deser->deserialize(tree);
// // return ans;
​
​
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
​
    // Encodes a tree to a single string.
    void preorderDFS(string& output, TreeNode* node) {
        if (node == nullptr) {return;}
        char myInt[sizeof(int)];
        memcpy(&myInt, &(node->val), sizeof(int));
        for (int i = 0; i < sizeof(int); i++) {output.push_back(myInt[i]);}
        preorderDFS(output, node->left);
        preorderDFS(output, node->right);
    }
    
    string serialize(TreeNode* root) {
        string output = "";
        preorderDFS(output, root);
        return output;
    }
​
    TreeNode* reconstruct(string& data, int& pos, int minVal, int maxVal) {
        if (pos >= data.size()) {return nullptr;}
        
        int val;
        memcpy(&val, &data[pos], sizeof(int));
        if (val < minVal || val > maxVal) {return nullptr;}
        
        pos += sizeof(int);
        TreeNode* node = new TreeNode(val);
        node->left = reconstruct(data, pos, minVal, val);
        node->right = reconstruct(data, pos, val, maxVal);
        return node;
​
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        TreeNode* output;
        int pos = 0;
        output = reconstruct(data, pos, INT_MIN, INT_MAX);
        return output;
    }
};
​
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
