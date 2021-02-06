class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack( nums, {}, 0 );
        return res;
    }
    
    void backtrack( vector<int>& nums, vector<int> cand, int idx ){
        if( idx == nums.size() ){
            res.push_back(cand);
            return;
        }
        
        backtrack( nums, cand, idx+1 );
        cand.push_back(nums[idx]);
        backtrack( nums, cand, idx+1);
    }
    
private:
    vector<vector<int>> res;
};
