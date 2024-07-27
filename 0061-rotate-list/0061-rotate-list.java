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
     
     if(head == null){
        return null;
     }
         ListNode curr = head;
          ListNode prev = null;
          int sum =0;
   ListNode temp = head;
          while(temp != null){
            sum ++;
            temp = temp.next;
          }
          k = k%sum;
             if(k==0){
            return head;
        }
          sum =sum- k;
          while(sum != 0){
            prev = curr;
            curr = curr.next;
            sum--;
          }
          prev.next =null;
  ListNode tail = curr;
          while(tail.next != null){
            tail = tail.next;
          }
          tail.next = head;

          return curr;

       
}
}