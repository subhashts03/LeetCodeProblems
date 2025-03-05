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
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
        ListNode fast = head,slow = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode curr = slow.next,prev,temp = slow.next.next;
        slow.next = null;
        curr.next = null;
        while(temp != null){
            prev = curr;
            curr = temp;
            temp = curr.next;
            curr.next = prev;
        }
        
        ListNode h1 = head, h2 = curr;
        while(h2 != null){
            System.out.println(h2.val);
            h2 = h2.next;
        }
        h2 = curr;
        while(h2 != null){
            ListNode temp2 = h2.next;
            h2.next = h1.next;
            h1.next = h2;
            h1 = h2.next;
            h2 = temp2;
        }
        
    }
}