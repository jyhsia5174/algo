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
