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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        if(list1 == NULL){
          return list2;
        }else if(list2 == NULL){
          return list1;
        }
        ListNode* head = NULL;
        ListNode* curr = NULL;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                if (head == NULL){
                    head = curr = l1;
                    l1 = l1->next;}
                else {
                    curr->next = l1;
                    curr = curr->next;
                    l1 = l1->next;
                }
            } else {

                if (head == NULL){
                    head = curr = l2;
                    l2 = l2->next;}
                else {
                    curr->next = l2;
                    curr = curr->next;
                    l2 = l2->next;
                }
            }
        }

        while(l1 != NULL){
           curr->next = l1;
           curr = curr->next;
            l1 = l1->next;
        }

         while(l2 != NULL){
           curr->next = l2;
           curr = curr->next;
            l2 = l2->next;
        }

        return head;
        
    }
};