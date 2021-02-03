/*
46. Permutations
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        used.resize(n, false);
        
        vector<int> tmp;
        backtrack(nums, tmp);
        
        return res;
    }
    
    void backtrack(const vector<int>& nums, const vector<int> &cand){
        if( cand.size() == n ){
            res.push_back( cand );
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if( !used[i] ){
                used[i] = true;
                vector<int> tmp( cand.begin(), cand.end() ) ;
                tmp.push_back( nums[i] );
                backtrack( nums, tmp );
                used[i] = false;
            }
        }
    }
    
    int n;
    vector<bool> used;
    vector<vector<int>> res;
};
