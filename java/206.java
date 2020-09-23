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
// iteration
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
// recursive
class Solution {
    public ListNode reverseList(ListNode head) {
        return subroutine( null, head );
    }
    
    private ListNode subroutine( ListNode reverseListHead , ListNode head ){
        if( head == null )
            return reverseListHead;
        ListNode nextHead = head.next;
        head.next = reverseListHead;
        return subroutine( head, nextHead );
    }
}
