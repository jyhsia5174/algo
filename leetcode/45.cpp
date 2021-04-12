// 45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        
        int step = 0;
        int l = 0;
        int r = 0;
        
        for(int i = 0; i < n; i++){
            if( i > l ){
                step++;
                l = r;
            }
            
            r = max(r, nums[i] + i);
        }
        
        return step;
    }
};
