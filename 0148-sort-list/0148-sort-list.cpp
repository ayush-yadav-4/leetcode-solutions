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
 ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
ListNode* Merge(ListNode* left, ListNode* right){
     ListNode* head = new ListNode(0); ListNode* temp = head;

   while(left != NULL && right != NULL){
     if(left->val <= right->val){
          temp->next = left;
          temp = temp->next;
          left = left->next;

     }
     else{
          temp->next = right;
          temp = temp->next;
          right = right->next;

     }
   }

   if(left) temp->next = left;
   else temp->next = right;
   return head->next;

}
    ListNode* Merge_Sort(ListNode* head){
       
       if(head == NULL || head->next == NULL) return head;

       ListNode* mid = findmid(head);
      
       ListNode* right = mid->next;
       mid->next = NULL;
        ListNode* left = head;

       left = Merge_Sort(left);
       right = Merge_Sort(right);
       return Merge(left,right);

    }
    ListNode* sortList(ListNode* head) {
        return Merge_Sort(head);
    }
};