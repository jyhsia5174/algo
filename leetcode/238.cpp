// 238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> output;
        output.resize(N);
        
        int product = 1;
        for(int i = 0; i < N; i++){
            output[i] = product;
            product *= nums[i];
        }
        
        product = 1;
        for(int i = N - 1; i >= 0; i--){
            output[i] *= product;
            product *= nums[i];
        }
        
        return output;
    }
    
};
