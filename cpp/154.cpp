/*
154. Find Minimum in Rotated Sorted Array II
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if( nums.size() == 1 )
            return nums[0];
        
        int lo = 0, hi = nums.size() - 1;
        while( lo + 1 < hi ){
            if( nums[lo] < nums[hi] )
                return nums[lo];
            
            int mid = lo + (hi - lo) / 2;
            if( nums[lo] == nums[mid] ){
                lo++;
            }
            else if( nums[lo] < nums[mid] ){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        
        // lo + 1 == hi and pivot is lo or hi
        if( nums[lo] < nums[hi] )
            return nums[lo];
        return nums[hi];
    }
};
