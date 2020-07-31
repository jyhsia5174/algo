// 460. LFU Cache
class LFUCache {
public:
    LFUCache(int capacity) {
        C = capacity;
    }
    
    int get(int key) {
        if( M.count(key) == 0 )
            return -1;
        
        vector<int> freq_T_val_key = *(M[key]);
        rank.erase(M[key]);
        freq_T_val_key[0]++;
        freq_T_val_key[1]=T;
        auto it_bool = rank.insert(freq_T_val_key);
        M[key] = it_bool.first;
        T++;
        return freq_T_val_key[2];
    }
    
    void put(int key, int value) {
        if( C == 0 ) return;
        
        if( M.count(key) == 1 ){
            vector<int> freq_T_val_key = *(M[key]);
            rank.erase(M[key]);
            freq_T_val_key[0]++;
            freq_T_val_key[1]=T;
            freq_T_val_key[2] = value;
            auto it_bool = rank.insert(freq_T_val_key);
            M[key] = it_bool.first;
            T++;
            return;
        }
        
        if( M.size() == C ){
            auto it = rank.begin();
            int old_key = (*it)[3];
            M.erase(old_key);
            rank.erase(it);
        }
        vector<int> freq_T_val_key{1, T, value, key};
        auto it_bool = rank.insert(freq_T_val_key);
        M[key] = it_bool.first;
        T++;
    }
    
private:
    int C;
    int T = 0;
    unordered_map<int, set<vector<int>>::iterator> M;
    set<vector<int>>  rank;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
