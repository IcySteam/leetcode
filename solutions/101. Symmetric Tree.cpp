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
​
class CustomNode {
public:
    TreeNode* node;
    int lvlIndex;
    CustomNode(TreeNode* _node, int _lvlIndex) {
        node = _node;
        lvlIndex = _lvlIndex;
    }
};
​
class Solution {
public:    
    bool isSymmetric(TreeNode* root) {
        queue<CustomNode> myQueue;
        CustomNode customRoot = CustomNode(root, 0);
        myQueue.push(customRoot);
        bool symmetrical = true;
        bool encounteredExtraneousNode = false;
        int currentLvl = 0;
        while (myQueue.size() && symmetrical) {
            int lvlSize = pow(2, currentLvl);
            int initQueueSize = myQueue.size();
            CustomNode initFront = myQueue.front();
            stack<CustomNode> myStack;
            for (int i = 0; i < initQueueSize; ++i) {
                CustomNode front = myQueue.front();
                if (front.lvlIndex < lvlSize / 2) {
                    myStack.push(front);
                    cout << "added: " << front.node->val << endl;
                }
                else {
                    if (myStack.size()) {
                        if (myStack.top().node->val == front.node->val && (myStack.top().lvlIndex == lvlSize - front.lvlIndex - 1)) {
                            cout << "removed: " << myStack.top().node->val << endl;
                            myStack.pop();
                        }
                        else {
                            cout << "failed to remove: " << front.node->val << endl;
                            encounteredExtraneousNode = true;
                        }
                    }
                    else if (front.node != root) {
                        // cout << front.node->val << " " << front.lvlIndex << endl;
                        encounteredExtraneousNode = true;
                    }
                }
                if (front.node->left) {
                    CustomNode added = CustomNode(front.node->left, front.lvlIndex * 2);
                    myQueue.push(added);
                }
                if (front.node->right) {
                    CustomNode added = CustomNode(front.node->right, front.lvlIndex * 2 + 1);
                    myQueue.push(added);
                }
                myQueue.pop();
            }
            symmetrical = ((myStack.empty() || initFront.node == root) && !encounteredExtraneousNode);
            currentLvl++;
        }
        return symmetrical;
    }
};
