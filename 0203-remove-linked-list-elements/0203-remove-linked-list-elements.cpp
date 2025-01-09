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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head); // Dummy node before the actual head
        ListNode* prev = dummy; // Start from dummy
        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val == val) {
                prev->next = temp->next; // Remove the current node
            } else {
                prev->next = temp; 
                prev = prev->next;// Move prev only if no deletion
            }
            temp = temp->next; // Always move temp forward
        }
        
        return dummy->next; // Return the updated head
    }
};