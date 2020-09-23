class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int xx;
        int bound = (x > 0)? ( ((unsigned int) 1 << 31) - 1) : (-1 * (1 << 31) );

        if( x > 0 ){
            while( x != 0 ){
                if( res > (bound / 10))
                    return 0;
                res *= 10;
                
                xx = x - (x/10)*10;
                if( res > (bound - xx))
                    return 0;
                res += xx;
                    
                x /= 10;
            }
        }
        else{
            while(x != 0){
                if( res < (bound / 10))
                    return 0;
                res *= 10;
                
                xx = x - (x/10)*10;
                if( res < (bound - xx))
                    return 0;
                res += xx;
                    
                x /=10;
            }
        }
        
        return res;
    }
};
