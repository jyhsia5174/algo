/*
69. Sqrt(x)
*/
class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 || x == 1 )
            return x;
        int l = 1, r = x/2;
        int res = 0;
        while( l <= r ){
            int m = l + (r - l) / 2;
            int xdm  = x / m;
            if( m <= xdm )
                res = max(res, m);
            
            if( m > xdm ){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        
        return res;
    }
};
