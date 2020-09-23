// 279. Perfect Squares
class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        vector<int> dp(n+1, numeric_limits<int>::max());
        
        int ii = 1;
        int ii_sq = ii * ii;
        for(int i = 1; i < n+1; i++){
            if( i == ii_sq ){
                sq.push_back( ii_sq );
                ii++;
                ii_sq = ii * ii;
                dp[i] = 1;
                continue;
            }
            
            for(auto &v: sq){
                dp[i] = min(dp[i], dp[i-v] + 1 );
            }
        }
        
        return dp[n];
    }
};
