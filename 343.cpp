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
class Solution {
public:
    int integerBreak(int n) {
        cache.resize(n+1, 0);
        return MP(n);
    }
    
    vector<int> cache;
    
    int MP(int n){
        if( n == 1 ) return 0;
        if( cache[n] != 0 ) return cache[n];
        
        int max_prod = 0;
        int prod;
        for(int i = 1; i < n; i++){
            prod = max( i * (n-i), i * MP(n-i) );
            max_prod = max(max_prod, prod);
        }
        
        cache[n] = max_prod;
        return cache[n];
    }
};
