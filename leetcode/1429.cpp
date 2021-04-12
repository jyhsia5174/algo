// 1429. First Unique Number
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(auto &v: nums)
            add(v);
    }
    
    int showFirstUnique() {
        if( Q.empty() ) return -1;
        return Q.begin()->second;
    }
    
    void add(int value) {
        if( M.count(value) == 1){
            if( M[value] == Q.end() ) return;
            Q.erase(M[value]);
            M[value] = Q.end();
        }
        else{
            Q.insert({T, value});
            M[value] = Q.find( {T, value} );
            T++;
        }
    }
private:
    int T = 0;
    set<pair<int, int>> Q;
    unordered_map<int, set<pair<int, int>>::iterator> M;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
