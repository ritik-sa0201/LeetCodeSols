class Solution {
public:
  
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    int getDecimalValue(ListNode* head) {
        head = reverseList(head);  

        int result = 0;
        int power = 0;


        while (head != nullptr) {
            result += (head->val) * (1 << power);  
            power++;
            head = head->next;
        }

        return result;
    }
};
