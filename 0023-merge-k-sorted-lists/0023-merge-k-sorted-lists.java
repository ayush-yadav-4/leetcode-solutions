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
        PriorityQueue<Integer> pq= new PriorityQueue<>();
       //List<Integer> arr = new ArrayList<>();
        for(int i=0;i<lists.length;i++){
           ListNode temp = lists[i];
           while(temp != null){
            pq.add(temp.val);
            temp = temp.next;
           }
        }
         if(pq.size() == 0) return null;
        // Collections.sort(arr);
        ListNode head = null,ptr = null;
        
        while(pq.size()>0){
            int val = pq.peek();
            pq.poll();
          ListNode node = new ListNode(val);
         
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