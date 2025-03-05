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
        ListNode temp = head;
        int len = 0;
        while(temp != null){
            len += 1;
            temp = temp.next;
        }
        int target = len - n;

        System.out.println(target);

        ListNode curr = head, right ;
        if(len == n){
            if(len == 1) return null;
            right = curr.next;
            curr.next = null;
            head = right;
            return head;
        }

        int pos = 1;

        while(pos != target){
            pos += 1;
            curr = curr.next;
        }
        right = curr.next;
        curr.next = right.next;
        right.next = null;
        return head;
    }
}