class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 0; i <= n; i++)
            fast = fast->next;

        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* wanted = slow->next;
        slow->next = wanted->next;
        delete wanted;

        return dummy->next;
    }
};