/*
162. Find Peak Element
*/
/*
len break   mid lsub    lLen    rsub    rLen
0   y
1   y
2   y
3   n       1   [0,1]   2       [1,2]   2
4   n       2   [0,2]   3       [2,3]   2
5   n       2   
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if( nums.size() == 1 )
            return 0;
        int lo = 0, hi = nums.size() - 1;
        while( lo + 1 < hi ){
            int mid = lo + (hi - lo) / 2;
            if( nums[mid] > nums[mid + 1] )
                hi = mid;
            else if( nums[mid] < nums[mid + 1] )
                lo = mid;
             else
                 return -1;
        }
        
        if( nums[hi] > nums[lo] )
            return hi;
        else 
            return lo;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size());
    }
    
    int search(vector<int>& A, int begin, int end){
        if(begin + 1 == end)
            return begin;
        
        int mid = (begin + end) / 2;
        double m_val = A[mid];
        double b_val = A[mid-1];
        double e_val = (mid + 1 < A.size())? A[mid + 1] : -HUGE_VAL;
        
        if( b_val > m_val && e_val > m_val )
            return search(A, begin, mid);
        else if( b_val > m_val && m_val > e_val)
            return search(A, begin, mid);
        else if( b_val < m_val && m_val < e_val)
            return search(A, mid, end);
        else 
            return mid;
    }
};
