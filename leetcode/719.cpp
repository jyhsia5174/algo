/*
719. Find K-th Smallest Pair Distance
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int lo = 0, hi = nums[n-1] - nums[0];
        while(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;
            if(count(nums, mid) == k)
                hi = mid;
            else if(count(nums, mid) > k)
                hi = mid;
            else
                lo = mid;
        }
        
        // lo + 1 == hi
        if( count(nums, lo) >= k )
            return lo;
        return hi;
    }
    
    int count( const vector<int> &A, int val ){
        int count = 0;
        for(int i = 0; i < A.size(); i++){
            auto it1 = upper_bound(A.begin(), A.end(), A[i] + val);
            count += (it1 - (A.begin() + i)) - 1;
        }
        return count;
    }
};
