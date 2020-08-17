// 53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        sum.resize(nums.size()+1);
        
        sum[0] = 0;
        for(int i = 0; i < nums.size(); i++)
            sum[i+1] = sum[i] + nums[i];
        
        int max_sum = -2147483647;
        int max_right = sum.back();
        for(int i = sum.size()-2; i >= 0 ; i--){
            if( max_right - sum[i] > max_sum ){
                max_sum = max_right - sum[i];
            }
            
            max_right = max( max_right, sum[i] );
        }
        
        return max_sum;
    }
};
