// Split Array Largest Sum
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        unsigned long long int l = 0;
        unsigned long long int r = 1 << 30;
        
        for(auto a: nums){
            l = max(l, (unsigned long long int) a);
            r += a;
        }
        
        unsigned long long int mid;
        while( l + 1 < r ){
            mid = (l + r) / 2;
            if( check(nums, mid, m) )
                r = mid;
            else
                l = mid;
        }
        
        if( check(nums, l, m) )
            return l;
        return r;
    }
    
private:
    bool check(vector<int>& nums, long long int k, int m){
        int count = 1;
        unsigned long long int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > k){
                if( nums[i] > k )
                    return false;
                sum = nums[i];
                count++;
            }
            else{
                sum += nums[i];
            }
        }
        
        if(count > m)
            return false;
        return true;
    }
};
