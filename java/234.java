// 234. Palindrome Linked List
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

// time O(n), space O(1)
class Solution {
    public boolean isPalindrome(ListNode head) {
        int N = 0;
        
        ListNode curNode = head;
        while( curNode != null ){
            curNode = curNode.next;
            N++;
        }
        
        ListNode halfHead = head;
        ListNode tailHead = null;
        for(int i = 0; i < N/2; i++){
            ListNode nextNode = halfHead.next;
            halfHead.next = tailHead;
            tailHead = halfHead;
            halfHead = nextNode;
        }
        
        if( N % 2 == 1 )
            halfHead = halfHead.next;
        
        for(int i = 0; i < N/2; i++){
            if( tailHead.val != halfHead.val )
                return false;
            tailHead = tailHead.next;
            halfHead = halfHead.next;
        }
        return true;
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
class Solution {
    public boolean isPalindrome(ListNode head) {
        if( head == null )
            return true;
        
        ListNode halfNode = getHalfNode(head);
        ListNode reverseHead = reverse(halfNode.next);
        
        ListNode p1 = head;
        ListNode p2 = reverseHead;
        while( p2 != null ){
            if( p1.val != p2.val )
                return false;
            p1 = p1.next;
            p2 = p2.next;
        }
        
        return true;
    }
    
    private ListNode reverse(ListNode head){
        ListNode prev = null;
        ListNode curr = head;
        while( curr != null ){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    private ListNode getHalfNode(ListNode head){
        ListNode fast = head;
        ListNode slow = head;
        while( fast.next != null && fast.next.next != null ){
            fast = fast.next.next;
            slow = slow.next;
        }
        
        return slow;
    }
}


// time O(n), space O(n)
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
    private ListNode frontPointer;
    
    private boolean recursivelyCheck(ListNode currentEndNode){
        if( currentEndNode != null ){
            if( ! recursivelyCheck( currentEndNode.next ) ) return false;
            if( frontPointer.val != currentEndNode.val ) return false;
            frontPointer = frontPointer.next;
        }
        return true;
    }
    
    public boolean isPalindrome(ListNode head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
}



