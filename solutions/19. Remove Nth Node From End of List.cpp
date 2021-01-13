/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> node_stack;
        ListNode* current = head;
        node_stack.push(current);
        while (current->next != nullptr) {
            current = current->next;
            node_stack.push(current);
        }
        ListNode* target;
        int popped = 0;
        for (int i = 1; i < n; i++) {
            node_stack.pop();
            popped += 1;
        }
        target = node_stack.top();
        if (popped == 0) {
            node_stack.pop();
            if (node_stack.empty()) {return nullptr;}
            else {
                node_stack.top()->next = nullptr;
            }
            while (node_stack.size() > 1) {node_stack.pop();}
            return node_stack.top();
        }
        else {
            node_stack.pop();
            if (node_stack.empty()) {return target->next;}
            else {
                node_stack.top()->next = node_stack.top()->next->next;
                while (node_stack.size() > 1) {node_stack.pop();}
                return node_stack.top();
            }
        }
    }
};
