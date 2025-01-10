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
        if(head == NULL || head->next == NULL ) return head;
         ListNode* n = new ListNode(-1);
         ListNode*prev = n;
         ListNode*curr = head;
        

         
        while(curr != NULL){ 
    
               if(curr->next != NULL && curr->val == curr->next->val){
               int val = curr->val;
               while(curr != NULL && curr->val == val){
                curr = curr->next;
               }
                prev->next = curr;
                }else{
                    prev->next = curr;
                    prev = prev->next;
                    curr = curr->next;
                }
               
                 
        }
        return n->next;
    }
};