/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Swap two nodes: head and head->next
    ListNode* reverse(ListNode* head, ListNode* rest) {
        ListNode* first = head;
        ListNode* second = head->next;
        second->next = first;
        first->next = rest;
        return second; 
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* rest = swapPairs(head->next->next);
        return reverse(head, rest);
    }
};
