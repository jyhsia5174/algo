// 674. Longest Continuous Increasing Subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int N = nums.size();
        if(N == 0) return 0;
        vector<int> dp(N, 1);
        
        int res = 1;
        for(int i = 1; i < N; i++){
            if( nums[i-1] < nums[i] )
                dp[i] = dp[i-1] + 1;
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};
