/*
50. Pow(x, n)
*/
class Solution {
public:
    double myPow(double x, int n) {
        long long int N = n;
        
        if( N < 0 ){
            x = 1/x;
            N = -N;
        }
        
        return helper(x, N);
    }
    
    // n >= 0
    double helper(double x, long long int n){
        if( n == 0 )
            return 1;
        
        double half = helper( x, n / 2 );
        
        if( n % 2 == 0 )
            return half * half;
        else
            return half * half * x;
    }
};
