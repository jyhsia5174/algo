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
