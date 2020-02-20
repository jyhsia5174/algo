/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        
        ListNode *next = headA;
        while(next != NULL){
            lenA++;
            next = next->next;
        }
        
        next = headB;
        while(next != NULL){
            lenB++;
            next = next->next;
        }
        
        int lenD = lenA - lenB;
        ListNode *nextA = headA, *nextB = headB;
        while( nextA != NULL && nextB != NULL ){
            if(lenD > 0){
                nextA = nextA->next;
                lenD--;
            }
            else if( lenD < 0 ){
                nextB = nextB->next;
                lenD++;
            }
            else{
                if( nextA == nextB )
                    return nextA;    
                nextA = nextA->next;
                nextB = nextB->next;
            }
        }
        
        return NULL;
    }
};
