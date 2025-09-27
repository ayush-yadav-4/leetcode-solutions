class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode r1 = reverse(l1);
        ListNode r2 = reverse(l2);

        ListNode dum = new ListNode(-1);
        ListNode cur = dum;
        int carry = 0;
        while(r1!=null || r2!=null || carry==1){
            int n1 = 0,n2 = 0;
            if(r1!=null) {
                n1 = r1.val;
                r1 = r1.next;
            }
            if(r2!=null){
                n2 = r2.val;
                r2 = r2.next;
            }
            int tot = n1+n2+carry;
            carry = (tot < 10) ? 0 : 1;
            ListNode s1 = new ListNode(tot%10);
            cur.next = s1;
            cur = cur.next;
        }
        return reverse(dum.next);
    }
    public ListNode reverse(ListNode head) {
        ListNode prev = null;      // previous node
        ListNode curr = head;      // current node
        
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;             
            prev = curr;              
            curr = nextTemp;              
        }
        
        return prev; 
    }
}