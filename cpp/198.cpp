// 198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        if( nums.size() == 0 )
            return 0;
        int money[2];
        money[0] = nums[0];
        money[1] = 0;
        
        for(int i = 1; i < nums.size(); i++){
            int rob = money[1] + nums[i];
            int norob = max(money[0], money[1]);
            money[0] = rob;
            money[1] = norob;
        }
        
        return max(money[0], money[1]);
    }
};
