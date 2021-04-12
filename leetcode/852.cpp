/*
852. Peak Index in a Mountain Array
Runtime: 8 ms, faster than 99.09% of C++ online submissions for Peak Index in a Mountain Array.
Memory Usage: 11.6 MB, less than 90.81% of C++ online submissions for Peak Index in a Mountain Array.
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        const int n = A.size();
        
        int l = 1, r = n-1, m;
        while( l < r ){
            int m = (l + r) / 2;
            int a = A[m-1];
            int b = A[m];
            int c = A[m+1];
            
            if( a < b && b > c ){
                return m;
            }
            else if( a < b && b < c ){
                l = m + 1;
            }
            else{
                r = m;
            }
        }
        
        return -1;
    }
};
