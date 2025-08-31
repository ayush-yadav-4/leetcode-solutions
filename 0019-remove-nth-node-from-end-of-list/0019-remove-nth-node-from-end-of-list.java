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
        
        ListNode ptr = head;
        int idx = 1;
        while(ptr != null){
          idx++;
          ptr = ptr.next;
        }
        int i = 0;
        idx = idx - n;
        ptr = head;
        if(idx == 1){
            head = head.next;
            return head;
        }
        while(ptr!= null && i+1 != idx-1){
          ptr = ptr.next;
          i++;
        }
        if(ptr == null) return head;
        if(ptr.next == null)return head;
        else {
            ptr.next = ptr.next.next;
        }
        return head;
    }
}