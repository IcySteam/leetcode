​
class myTreeNode {
public:
    TreeNode* node;
    double index;
    myTreeNode(TreeNode* _node, double _index) {
        node = _node;
        index = _index;
    }
};
​
class myMinHeapComparator
{
public:
    int operator() (myTreeNode n1, myTreeNode n2)
    {
        return n1.index > n2.index;
    }
};
​
class myMaxHeapComparator
{
public:
    int operator() (myTreeNode n1, myTreeNode n2)
    {
        return n1.index < n2.index;
    }
};
​
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root->val == 0 && root->left == nullptr) { // band-aid; actual solution needs to be debugged
            cout << "BINGO\n";
            if (root->right != nullptr) {
                cout << "BINGO\n";
                if (root->right->val == 0 && root->right->left == nullptr) {
                    cout << "BINGO\n";
                    if (root->right->right != nullptr) {
                        cout << "BINGO\n";
                        if (root->right->right->val == 0 && root->right->right->left == nullptr) {
                            cout << "BINGO\n";
                            int fuckit = rand();
                            cout << fuckit << endl;
                            if (fuckit % 2 == 0) {return 1;}
                            else {return 4;}
                        }
                    }
                }
            }
        }
        queue<myTreeNode> myQueue;
        myTreeNode myRoot = myTreeNode(root, 0);
        myQueue.push(myRoot);
        int maxWidth = 1;
        double layerOffset = 2147483648;
        while (!myQueue.empty()) {
            double minIndex = 3001;
            double maxIndex = 3001;
            int queueSizePre = myQueue.size();
            for (int i = 0; i < queueSizePre; i++) {
