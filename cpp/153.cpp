/*
153. Find Minimum in Rotated Sorted Array
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size();
        while( l < r ){
            // size == 1 or is sorted then return ans
            if( r - l == 1 || nums[l] < nums[r-1] )
                return nums[l];
            
            // l < m < r
            int m = l + (r - l) / 2;
            
            // [l, m), [m, r)
            
            // if l == m-1 and is not sorted implies answer is in [m, r);
            if( nums[l] <= nums[m-1] )
                l = m;
            else
                r = m;
        }
        
        return -1;
    }
};

// when binary condition is based on l, m, beware about l == m
