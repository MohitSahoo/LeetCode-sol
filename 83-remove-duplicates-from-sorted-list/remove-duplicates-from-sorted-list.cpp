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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp3 = head;
        while(temp3  != NULL){
            if(temp1 ->val == temp3 ->val){
                temp3 = temp3->next;
            }else{
                temp1->next->val = temp3->val;
                temp1 = temp1->next;
                temp3 = temp3->next;
            }
        }
        temp1 ->next = NULL;
        return head;

        
    }
};