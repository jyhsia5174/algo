// 380. Insert Delete GetRandom O(1)
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if( S.count(val) == 0 ){
            L.push_back(val);
            S[val] = (L.size()-1);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if( S.count(val) == 0 )
            return false;
        int idx = S[val];
        int a = L.back();
        int b = L[idx];
        
        L[idx] = a;
        S[a] = idx;
        
        L.pop_back();
        S.erase(b);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % L.size();
        return  L[idx];
    }
    
    unordered_map<int, int> S;
    vector<int> L;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
