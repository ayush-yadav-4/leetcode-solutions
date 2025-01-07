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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int size=1,i=1;
        while(curr != NULL){
             curr = curr->next;
            size++;
          
        }

        ListNode* curr1 = head;
        if(size%2 == 1){size = (size/2)+1;}
        else{ size = (size/2);}
        while(i < size){
           
        curr1 = curr1->next;
        i++;
        }
        return curr1;

    }
};