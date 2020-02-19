class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        
        bool res = false;
        int a = INT_MAX;
        int b = INT_MAX;
        for(auto n: nums){
            if( n > a && n > b ){
                res = true;
            }
            
            if( n > a )
                b = min<int>(b, n);
            
            a = min<int>(a, n);
        }
        
        return res;
    }
};
