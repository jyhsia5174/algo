// 23. Merge k Sorted Lists
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

class cmp{
public:
    bool operator() ( const pair<int, ListNode*> &lhs, const pair<int, ListNode*>  &rhs ){
        return lhs.first < rhs.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& L) {
        if( L.size() == 0 ) return NULL;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, 
        cmp> Q, Q_tmp;
        
        for(int i = 0; i < L.size(); i++)
            Q.push( {get_size(L[i]), L[i]} );
        
        while( Q.size() > 1 ){
            while( !Q.empty() ){
                if( Q.size() >= 2 ){
                    auto l = Q.top(); Q.pop();
                    auto r = Q.top(); Q.pop();
                    int size = l.first + r.first;
                    Q_tmp.push( {size, merge(l.second, r.second)} );
                }
                else{
                    auto l = Q.top(); Q.pop();
                    Q_tmp.push(l);
                }
            }
            swap( Q, Q_tmp );
        }
        
        return Q.top().second;
    }
    
    int get_size( ListNode* l ){
        int size = 0;
        while( l != NULL ){
            size++;
            l = l->next;
        }
        return size;
    }
    
    void print( ListNode *l ){
        while( l != NULL ){
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }
    
    ListNode *merge( ListNode *l, ListNode *r ){
        ListNode head;
        ListNode *cur = &head;
        //print(l);
        //print(r);
        while( l != NULL || r != NULL ){
            if( l != NULL && r != NULL ){
                if( l->val <= r->val ){
                    cur->next = l;
                    l = l->next;
                }
                else{
                    cur->next = r;
                    r = r->next;
                }
            }
            else if( l != NULL ){
                cur->next = l;
                break;
            }
            else{
                cur->next = r;
                break;
            }
            cur = cur->next;
        }
        //print(head.next);
        return head.next;
    }
};
