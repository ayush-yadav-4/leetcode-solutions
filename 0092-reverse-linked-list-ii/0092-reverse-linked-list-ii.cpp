/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     i val;
 *     ListNntode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* start = head; ListNode* end = head; 
        while(left !=1){
            left--; start = start->next;
        }

        while(right !=1){
            right--; end = end->next;
        }
        stack<int>stack;

        ListNode* temp = start;

        while(temp != end->next){
         stack.push(temp->val);
         temp = temp->next;
        }
        while(start != end->next){
        start->val = stack.top();
        stack.pop();
         start = start->next;
        }

        return head;

    }
};