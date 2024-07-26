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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev = head;
        int size =0;
        while(prev != null){
            size++;
            prev = prev.next;
        }
        size -=n;
         prev = head;
         ListNode curr = head;
            if(curr.next == null){
                head =null;
                return head;
            }if(size ==0 && head.next != null){
                head = head.next;
                return head;
            }
            while(size!=0){
                prev = curr;
                curr = curr.next;
                size--;}
            
            prev.next = curr.next;

        
        return head;
    }
}