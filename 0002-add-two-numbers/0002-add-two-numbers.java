class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }

        ListNode head3 = new ListNode(0);
        ListNode curr1 = l1, curr2 = l2, curr3 = head3;
        int carry = 0;

        while (curr1 != null || curr2 != null || carry != 0) {
            int sum = carry;
            if (curr1 != null) {
                sum += curr1.val;
                curr1 = curr1.next;
            }
            if (curr2 != null) {
                sum += curr2.val;
                curr2 = curr2.next;
            }
            carry = sum / 10;
            curr3.next = new ListNode(sum % 10);
            curr3 = curr3.next;
        }

        return head3.next;
    }
}
