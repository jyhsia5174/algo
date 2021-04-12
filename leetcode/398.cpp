// 398. Random Pick Index
class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            val_idx_map[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        auto &candidates = val_idx_map[target];
        return candidates[ rand() % candidates.size()];
    }
private:
    unordered_map<int, vector<int>> val_idx_map;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
