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
    // Helper function to clone the linked list
    ListNode* cloneList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* newHead = new ListNode(head->val);
        ListNode* currNew = newHead;
        ListNode* currOld = head->next;

        while (currOld) {
            currNew->next = new ListNode(currOld->val);
            currNew = currNew->next;
            currOld = currOld->next;
        }
        return newHead;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Count the total number of nodes
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: Clone the list
        ListNode* copy = cloneList(head);

        // Step 3: Attach the cloned list to the tail of the original
        temp = head;
        while (temp->next) temp = temp->next;
        temp->next = copy;

        // Step 4: Adjust k
        k = k % n;
        if (k == 0) {
            // Optional cleanup: disconnect duplicated part
            temp->next = nullptr;
            return head;
        }

        // Step 5: Move (n - k) steps from head to get new head
        ListNode* newHead = head;
        for (int i = 0; i < n - k; i++)
            newHead = newHead->next;

        // Step 6: Break after newHead + (n-1)
        ListNode* tail = newHead;
        for (int i = 0; i < n - 1; i++)
            tail = tail->next;
        tail->next = nullptr;

        // Step 7: Return the rotated list head
        return newHead;
    }
};
