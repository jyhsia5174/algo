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
    public ListNode reverseList(ListNode head) {
        if( head == null )
            return head;
        
        ListNode tailhead = head;
        head = head.next;
        tailhead.next = null;
        while( head != null ){
            ListNode nextNode = head.next;
            head.next = tailhead;
            tailhead = head;
            head = nextNode;
        }
        
        return tailhead;
    }
}
