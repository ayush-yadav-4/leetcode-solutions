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
        StringBuilder str = new StringBuilder();
        ListNode ptr = head;
        while(ptr != null){
            str.append(ptr.val);
            ptr = ptr.next;
        }
       String s1 = str.toString();
       String s2 = str.reverse().toString();

        if(s1.equals(s2)){
            return true;
        }
        return false;
    }
}