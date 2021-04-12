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

// 53. Maximum Subarray --> Next: 363. Max Sum of Rectangle No Larger Than K
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        
        int sum = 0;
        int L = 0;
        int res = nums[0];
        
        for( int i = 0; i < n; i++ ){
            res = max( res, nums[i] );
            if( sum + nums[i] > 0 ){
                sum += nums[i];
                res = max( res, sum );
            }
            else{
                L = 0;
                sum = 0;
            }
        }
        
        return res;
    }
};
