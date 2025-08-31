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
    public ListNode oddEvenList(ListNode head) {
        int idx = 1;
         ListNode ptr = head;
         ListNode evenhead = null;
         ListNode oddhead = null;
         ListNode ptr1= null , ptr2 = null;
        while(ptr!= null){
          if(idx%2 == 0){
            if(evenhead == null){
                evenhead = ptr;
                ptr1 = evenhead;

            }else{
                ptr1.next = ptr;
                ptr1 = ptr1.next;
            }
          }
          else{
             if(oddhead == null){
                oddhead = ptr;
                ptr2 = oddhead;

            }else{
                ptr2.next = ptr;
                ptr2 = ptr2.next;
            }
          }
          idx++;
          ptr = ptr.next;
        }
         if (ptr1 != null) ptr1.next = null;

         if (ptr2 != null) ptr2.next = evenhead;
        return oddhead;
    }
}