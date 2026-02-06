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
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0 || lists == null) return null;
       List<Integer> arr = new ArrayList<>();
        for(int i=0;i<lists.length;i++){
           ListNode temp = lists[i];
           while(temp != null){
            arr.add(temp.val);
            temp = temp.next;
           }
        }
         if(arr.size() == 0) return null;
        Collections.sort(arr);
        ListNode head = null,ptr = null;
        
        for(int i=0;i<arr.size();i++){
          ListNode node = new ListNode(arr.get(i));
          if(head == null){
            head = node;
            ptr = head;
          }
          else{ ptr.next = node;
           ptr = ptr.next;
          }
        }
        return head;
    }
}