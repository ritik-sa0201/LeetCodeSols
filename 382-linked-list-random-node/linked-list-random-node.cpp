class Solution {
private:
    ListNode* head;
    int size;

    int sizeL(ListNode* node) {
        int ans = 0;
        while (node) {
            ans++;
            node = node->next;
        }
        return ans;
    }

public:
    Solution(ListNode* head) {
        this->head = head;
        this->size = sizeL(head);
        srand(time(0));
    }

    int getRandom() {
        int ran = rand() % size; 
        ListNode* curr = head;
        for (int i = 0; i < ran; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
};
