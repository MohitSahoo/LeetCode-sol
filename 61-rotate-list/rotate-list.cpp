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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int len =1;
        while(temp->next!=NULL){
            temp = temp->next;
            len++;
        }
       
        temp->next = head;
         k = k % len;
        if (k == 0) {          // Fix: must break circular link before returning
            temp->next = nullptr;
            return head;
        }

        int count2 = len -k-1;
       
        ListNode * temp2 = head;
        while(count2 !=0){
            temp2= temp2->next;
            count2--;
        }
        head = temp2->next;
        temp2->next = NULL;
        return head;
    
        
    }
};