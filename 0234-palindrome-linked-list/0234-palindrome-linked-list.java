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
    public boolean isPalindrome(ListNode head) {
        ListNode curr = head;
        ListNode middleNode = middlenode(curr);
        ListNode newNode = reverseList(middleNode);
         curr = head;
        while(curr != null && newNode != null){
            if(curr.val != newNode.val){
                return false;
            }
            curr = curr.next;
            newNode = newNode.next;
        }
            return true;
        }
    
    

    ListNode middlenode(ListNode head) {
          ListNode curr = head;
        ListNode prev = head;

        while(curr!=null && curr.next != null){
           prev = prev.next;
           curr = curr.next.next;
        }
        return prev;
    }
    ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while(curr!= null){
            ListNode next = curr.next;
        

            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}