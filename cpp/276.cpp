// 276. Paint Fence
class Solution {
public:
    int numWays(int n, int k) {
        if( n == 0 ) return 0;
        if( k == 1 ){
            if( n > 2 )
                return 0;
            return 1;
        }
        
        int a = k, b = 0;
        
        for(int i = 1; i < n; i++){
            int aa = a*(k-1) + b * (k-1);
            int bb = a;
            a = aa;
            b = bb;
        }
        
        return a + b;
    }
};
