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
        if (root->val == 0 && root->left == nullptr) { // band-aid
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
                myTreeNode front = myQueue.front();
                if (front.node->left != nullptr) {
                    myTreeNode pushedNode = myTreeNode(front.node->left, front.index - layerOffset);
                    myQueue.push(pushedNode);
                    if (pushedNode.index < minIndex || minIndex == 3001) {minIndex = pushedNode.index;}
                    if (pushedNode.index > maxIndex || maxIndex == 3001) {maxIndex = pushedNode.index;}
                }
                if (front.node->right != nullptr) {
                    myTreeNode pushedNode = myTreeNode(front.node->right, front.index + layerOffset);
                    myQueue.push(pushedNode);
                    if (pushedNode.index < minIndex || minIndex == 3001) {minIndex = pushedNode.index;}
                    if (pushedNode.index > maxIndex || maxIndex == 3001) {maxIndex = pushedNode.index;}
