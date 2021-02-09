/*
int lo = 0, hi = nums.size();
len = hi - lo

termination lo < hi
len break?  mid lsub    llen    rsub    rlen
0   y
[0, 1) 
1   n       0   [0, 0)  0       [1, 0)  -1
2   n       1   [0, 1)  1       [2, 2)  0
3   n       1   [0, 1)  1       [2, 3)  1
4   n       2   [0, 2)  2       [3, 4)  1
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1, -1};
        
        // lower index
        int lo = 0, hi = nums.size();
        while( lo < hi ){
            int mid = lo + (hi - lo) / 2;
            if( nums[mid] > target )
                hi = mid;
            else if( nums[mid] < target )
                lo = mid + 1;
            else
                hi = mid;
        }
        
        if( hi == nums.size() || nums[hi] != target )
            return {-1, -1};
        int lower = hi;
        
        lo = 0, hi = nums.size();
        while( lo < hi ){
            int mid = lo + (hi - lo) / 2;
            if( nums[mid] > target )
                hi = mid;
            else if( nums[mid] < target )
                lo = mid + 1;
            else
                lo = mid + 1;
        }
        
        if( lo - 1 < 0 || nums[lo-1] != target )
            return {-1, -1};
        int upper = lo - 1;
        return {lower, upper};
    }
};



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
