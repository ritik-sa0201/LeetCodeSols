class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* rev = reverseList(head);
        stack<int> st;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (rev != nullptr) {
            int val = rev->val;
            while (!st.empty() && st.top() <= val) {
                st.pop();
            }
            if (st.empty()) {
                tail->next = rev;
                tail = tail->next;
            }
            st.push(val);
            rev = rev->next;
        }
        tail->next = nullptr;
        return reverseList(dummy->next);
    }
};
