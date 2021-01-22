/*
146. LRU Cache
Runtime: 76 ms, faster than 99.35% of C++ online submissions for LRU Cache.
Memory Usage: 39.7 MB, less than 97.66% of C++ online submissions for LRU Cache.
*/
class node{
public:
    int key;
    int val;
    node* next = nullptr;
    node* pre = nullptr;
    
    node(int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        C = capacity;
        head = new node(-1, -1);
        tail = head;
    }
    
    int get(int key) {
        if( m.find(key) != m.end() ){
            node* curNode = m[key];
            
            if( curNode != tail ){
                node* pre = curNode->pre;
                node* next = curNode->next;
            
                pre->next = next;
                next->pre = pre;
            
                tail->next = curNode;
                curNode->pre = tail;
                tail = curNode;
            }
            
            return tail->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if( m.find(key) != m.end() ){
            node* curNode = m[key];
            
            if( curNode != tail ){
                node* pre = curNode->pre;
                node* next = curNode->next;
            
                pre->next = next;
                next->pre = pre;
            
                tail->next = curNode;
                curNode->pre = tail;
                tail = curNode;
            }
            
            tail->val = value;
        }
        else{
            if( m.size() == C ){
                node *curNode = head->next;
                m.erase(curNode->key);
                
                if( curNode != tail ){
                    head->next = curNode->next;
                    curNode->next->pre = head;
                }
                else{
                    curNode->pre->next = nullptr;
                    tail = curNode->pre;
                }
                
                delete curNode;
            }
            
            node* curNode = new node(key, value);
            tail->next = curNode;
            curNode->pre = tail;
            tail = curNode;
            
            m[key] = tail;
        }
    }

private:
    int C;
    unordered_map<int, node*> m;
    node *head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 146. LRU Cache
class LRUCache {
public:
    LRUCache(int capacity) {
        C = capacity;
    }
    
    int get(int key) {
        if( M.count(key) == 1 ){
            auto it = pos[key];
            L.push_back(*it);
            L.erase(it);
            it = L.begin();
            advance(it, L.size()-1);
            pos[key] = it;
            return M[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if( M.count(key) == 1 ){
            M[key] = value;
            auto it = pos[key];
            L.push_back(*it);
            L.erase(it);
            it = L.begin();
            advance(it, L.size()-1);
            pos[key] = it;
        }
        else{
            if( M.size() == C ){
                M.erase(L.front());
                pos.erase(L.front());
                L.pop_front();
            }
            M[key] = value;
            L.push_back( key );
            list<int>::iterator it = L.begin();
            advance(it, L.size()-1);
            pos[key] = it;
        }
    }
    
    int C;
    list<int> L;
    unordered_map<int, list<int>::iterator> pos;
    unordered_map<int, int> M;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
