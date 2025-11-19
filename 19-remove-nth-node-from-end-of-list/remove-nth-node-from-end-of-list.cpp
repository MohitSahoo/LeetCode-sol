class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);      // dummy before head
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both until fast is at last node
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to delete
        slow->next = slow->next->next;

        return dummy.next;    // new head
    }
};
