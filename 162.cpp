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
