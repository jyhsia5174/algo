/*
34. Find First and Last Position of Element in Sorted Array
*/
// 0
// 1
// 2
// 3 2 2
// 4 3 2
// 5 3 3


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if( nums.size() == 0 )
            return {-1, -1};
        
        // lower idx
        int l = 0, r = nums.size() - 1;
        while( l + 1 < r ){
            int m = l + (r - l) / 2;
            if( nums[m] >= target )
                r = m;
            else
                l = m;
        }
        
        int lower;
        if( nums[l] == target )
            lower = l;
        else if( nums[r] == target )
            lower = r;
        else
            return {-1, -1};
        
        // upper idx
        l = 0, r = nums.size() - 1;
        while( l + 1 < r ){
            int m = l + (r - l) / 2;
            if( nums[m] > target )
                r = m;
            else
                l = m;
        }
        
        int upper;
        if( nums[r] == target )
            upper = r;
        else if( nums[l] == target  )
            upper = l;
        
        return {lower, upper};
    }
};
