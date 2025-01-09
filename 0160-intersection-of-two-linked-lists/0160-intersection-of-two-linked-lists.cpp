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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA; ListNode* temp2 = headB;
        int size1=0,size2=0,diff = 0;
        while(temp1 != NULL){
            size1++;
            temp1 = temp1->next;
        }
         while(temp2 != NULL){
            size2++;
            temp2 = temp2->next;
        }
        temp1 = headA; temp2 = headB;
        if(size1>size2){
            diff = size1-size2;
            while(diff!=0){
                diff--;
                temp1 = temp1->next;
            }
        }
        else if(size2>size1){
            diff = size2- size1;
             while(diff!=0){
                diff--;
                temp2 = temp2->next;
            }
            }

            while(temp1 != NULL && temp2 != NULL){
                if(temp1 == temp2) return temp1;

                temp1 = temp1->next;
                 temp2 = temp2->next;

            }
            return NULL;
            

       }
    
};