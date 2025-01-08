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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        int i =3 ;
        ListNode* h1 = head;  ListNode* h2 = head->next;
        ListNode* temp1 = h1;   ListNode* temp2 = h2; 
        ListNode* ptr = head->next->next;
        while(ptr != NULL){
            if(i%2 == 1){
                temp1->next = ptr;
                 temp1 = ptr;  
            }else{
                temp2->next = ptr;
                 temp2 = ptr; 
            }
            ptr = ptr->next; i++;
        }
        temp1->next = h2;
        temp2->next = nullptr;
        return h1;

    }
  
};