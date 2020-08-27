// 152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = numeric_limits<int>::min();
        for(auto &v: nums)
            res = max(res, v);
        
        int l = 0;
        for(int i = 0; i < n; i++){
            if( nums[i] == 0 ){
                res = max(res, calc(nums, l, i));
                l = i+1;
            }
        }
        if( l < n )
            res = max(res, calc(nums, l, n));
        
        return res;
    }
    
    int calc(const vector<int>& nums, int l, int r){
        if( l == r ) return 0;
        
        int res = 1;
        for(int i = l; i < r; i++)
            res *= nums[i];
        
        if( res > 0 ) return res;
        
        int l_neg = 1;
        for(int i = l; i < r-1 && l_neg > 0; i++)
            l_neg *= nums[i];
        
        int r_neg = 1;
        for(int i = r-1; i >= l+1 && r_neg > 0; i--)
            r_neg *= nums[i];
        
        return max( res / l_neg, res / r_neg );
    }
};
