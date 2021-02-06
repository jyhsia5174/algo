/*
47. Permutations II
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        for(auto &v: nums)
            count[v]++;
        backtrack({});
        
        return res;
    }
    
    void backtrack(vector<int> cand){
        if( cand.size() == n ){
            res.push_back( cand );
            return;
        }
        
        cand.push_back( 0 );
        for(auto &kv: count){
            if( kv.second > 0 ){
                count[kv.first]--;
                cand[cand.size()-1] = kv.first;
                backtrack(cand);
                count[kv.first]++;
            }
        }
    }
private:
    int n;
    unordered_map<int, int> count;
    vector<vector<int>> res;
};
