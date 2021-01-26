/*
24. Swap Nodes in Pairs
Runtime: 8 ms, faster than 58.56% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.4 MB, less than 99.91% of C++ online submissions for Swap Nodes in Pairs.
*/
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
    ListNode* swapPairs(ListNode* head) {
        if( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode* tmp = head->next;
        head->next = swapPairs(tmp->next);
        tmp->next = head;
        
        return tmp;
    }
};
