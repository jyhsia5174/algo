// 343. Integer Break

// dp 
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int v = 1; v < i; v++){
                dp[i] = max( dp[i], v * dp[i-v] );
                dp[i] = max( dp[i], v * (i-v) );
            }
        }
        
        return dp[n];
    }
};

// recursive with memorization
