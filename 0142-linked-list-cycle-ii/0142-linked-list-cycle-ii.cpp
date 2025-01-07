/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL;
        bool cycle = false;
        ListNode* slow = head; ListNode* fast = head;
        while( fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                cycle = true;
                break;
            }
  
        }
        if(!cycle) return NULL;
           while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
        return slow;
    }
};