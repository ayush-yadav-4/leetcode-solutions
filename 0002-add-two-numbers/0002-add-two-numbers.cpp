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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode* head = new ListNode(0); 
          ListNode* temp = head;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int sum =0,carry=0;
        while(temp1 != NULL && temp2 != NULL){
          sum = temp1->val + temp2->val + carry;
          carry = sum/10;
          ListNode* n = new ListNode(sum%10);
          temp->next = n;
          temp = temp->next;

          if(temp1 != NULL) temp1 = temp1->next;
          if(temp2 != NULL) temp2 = temp2->next;

  }
  while(temp1 != NULL){
          sum = temp1->val + carry;
          carry = sum/10;
          ListNode* n = new ListNode(sum%10);
            temp->next = n;
          temp = temp->next;
           if(temp1 != NULL) temp1 = temp1->next;
  }
  while(temp2 != NULL){
          sum = temp2->val + carry;
          carry = sum/10;
          ListNode* n = new ListNode(sum%10);
            temp->next = n;
          temp = temp->next;
           if(temp2 != NULL) temp2 = temp2->next;
  }
    if(carry>0){
        ListNode* n = new ListNode(carry);
        temp->next = n;
        temp = temp->next;
    }
    temp->next = NULL;
    return head->next;

   
        
    }
};