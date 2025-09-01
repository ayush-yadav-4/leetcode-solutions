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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null) return head;
        ListNode prev = null,ptr = head;
        int idx = 1,len =1;

        while(ptr.next != null){
            len++;
            idx++;
            ptr = ptr.next;
        }
        ptr.next = head;
        k = k % len;
        idx = len - k;
        ptr = head;
        while(idx>1){
          ptr = ptr.next;
          idx--;
        }
        ListNode head1 = ptr.next;
        ptr.next = null;
        return head1;


    }
}