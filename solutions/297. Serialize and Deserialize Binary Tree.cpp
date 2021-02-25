    
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
const int REPR_NULL = -1001;
​
class Codec {
public:
​
    // Encodes a tree to a single string.
    void preorderDFS(string& output, TreeNode* node) {
        if (node == nullptr) {
            char nullChars[sizeof(int)];
            memcpy(&nullChars, &REPR_NULL, sizeof(int));
            for (int i = 0; i < sizeof(int); i++) {output.push_back(nullChars[i]);}
        }
        else {
            char myInt[sizeof(int)];
            memcpy(&myInt, &(node->val), sizeof(int));
            for (int i = 0; i < sizeof(int); i++) {output.push_back(myInt[i]);}
            
            preorderDFS(output, node->left);
            preorderDFS(output, node->right);
        }
    }
    
    string serialize(TreeNode* root) {
        string output = "";
        preorderDFS(output, root);
        // cout << output << endl;
        return output;
    }
    
    TreeNode* reconstruct(string& data, int& pos) {
        if (pos >= data.size()) {return nullptr;}
        int myInt;
        memcpy(&myInt, &data[pos], sizeof(int));
        pos += sizeof(int);
        
        if (myInt == REPR_NULL) {return nullptr;}
        TreeNode* node = new TreeNode(myInt);
        node->left = reconstruct(data, pos);
        node->right = reconstruct(data, pos);
        return node;
    }
​
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos);
    }
};
​
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
