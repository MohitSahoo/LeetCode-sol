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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =1;
        ListNode * temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            count++;
        }
        int k = count-n;
        ListNode * prev = NULL;
        temp = head;
        if (k == 1) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        k--;
        while(k != 0 ){
            prev = temp;
            temp = temp->next;
            k--;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;

        
    }
};