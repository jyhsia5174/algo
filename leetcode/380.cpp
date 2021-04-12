class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        gen = mt19937(rd());
        dis = uniform_real_distribution<>(0, 1.0);
        A.resize(1, 0);
        sz = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if( m.find(val) != m.end() )
            return false;
        
        if( A.size() == sz )
            A.resize(sz*2, 0);
        
        A[sz] = val;
        m[val] = sz;
        sz++;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if( m.find(val) == m.end() )
            return false;
        
        int pos = m[val]; // [0, sz)
        m.erase(val);
        
        if( pos != sz-1 ){
            swap(A[pos], A[sz-1]);
            m[A[pos]] = pos;
        }
        sz--;
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = sz * dis(gen);
        return A[pos];
    }
    
private:
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<> dis;
    
    unordered_map<int, int> m; // val, pos;
    vector<int> A;
    int sz;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


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
