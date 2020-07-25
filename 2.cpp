// 2. Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cache = 0, sum = 0;
        ListNode *root = new ListNode;
        ListNode *cur_n = root;
        while( l1 != NULL || l2 != NULL ){
            if( l1 != NULL && l2 != NULL ){
                sum = l1->val + l2->val + cache;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if( l1 != NULL ){
                sum = l1->val + cache;
                l1 = l1->next;
            }
            else{
                sum = l2->val + cache;
                l2 = l2->next;
            }
            cur_n->next = new ListNode( sum % 10 );
            cache = sum / 10;
            cur_n = cur_n->next;
        }
        if( cache != 0 ) cur_n->next = new ListNode( cache );
        
        return root->next;
    }
};
