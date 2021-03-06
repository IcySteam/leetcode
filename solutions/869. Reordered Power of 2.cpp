class Node {
public:
    Node() {
        for (int i = 0; i < 10; i++) {next[i] = nullptr;}
        // end = false;
    }
    Node* next[10];
    // bool end;
};
​
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int myNum = 1;
        Node* myTrie = new Node();
        while (myNum <= 1000000000) {
            int temp = myNum;
            vector<int> count(10, 0);
            while (temp > 0) {
                count[temp % 10]++;
                temp /= 10;
            }
            Node* currentNode = myTrie;
            for (int i = 0; i < 10; i++) {
                if (currentNode->next[count[i]] == nullptr) {currentNode->next[count[i]] = new Node;}
                currentNode = currentNode->next[count[i]];
            }
            myNum *= 2;
        }
        
        int temp = N;
        vector<int> count(10, 0);
        while (temp > 0) {
            count[temp % 10]++;
            temp /= 10;
        }
        Node* currentNode = myTrie;
        for (int i = 0; i < 10; i++) {
            if (currentNode->next[count[i]] == nullptr) {return false;}
            currentNode = currentNode->next[count[i]];
        }
        return true;    
    }
};
