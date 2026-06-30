class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (true) {

            
            ListNode* kth = prev;
            for (int i = 0; i < k && kth; i++)
                kth = kth->next;

            if (!kth)
                break;

            ListNode* curr = prev->next;

            
            for (int i = 0; i < k - 1; i++) {

                ListNode* temp = curr->next;

                curr->next = temp->next;

                temp->next = prev->next;

                prev->next = temp;
            }

            
            prev = curr;
        }

        return dummy->next;
    }
};