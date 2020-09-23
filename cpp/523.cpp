// 523. Continuous Subarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, mode;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if( k == 0 )
                mode = sum;
            else
                mode = sum%k;
            
            if( m.count(mode) && i - m[mode] >= 2 ) return true;
            
            if( !m.count(mode) ) m[mode] = i;
        }
        
        return false;
    }
};
