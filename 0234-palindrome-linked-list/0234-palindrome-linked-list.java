/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode prev = null,curr = head,next = head.next;

        while(next != null){
          next = curr.next;
          curr.next = prev;
          prev = curr;
          curr = next;
        }
        return prev;

    }
    public boolean isPalindrome(ListNode head) {
        ListNode first = head,second = head;
       while(second.next != null && second.next.next != null){
         first = first.next;
         second = second.next.next;
       }
    
       ListNode lasthead = reverse(first.next);
       ListNode ptr2 = lasthead;
       ListNode ptr1 = head;
         
       while(ptr2 != null){
          if(ptr1.val != ptr2.val){
            //reverse(first.next);
            return false;
          }
          ptr1 = ptr1.next;
          ptr2 = ptr2.next;

       }
        //reverse(first.next);
       return true;
    }
}