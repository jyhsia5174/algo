// 278. First Bad Version
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l = 0, r = n;
        
        while( l+1 < r ){
            long long int m = (l + r) / 2;
            if( isBadVersion(m) ){
                r = m;
            }
            else{
                l = m;
            }
        }
        
        if( isBadVersion(l) )
            return l;
        return r;
    }
};
