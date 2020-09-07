// 887. Super Egg Drop
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1, INT_MAX));
        for(int i = 0; i <= K; i++)
            dp[i][0] = 0;
        return recursive(K, N, dp);
    }
    
    int recursive(int K, int N, vector<vector<int>> &dp){
        if( dp[K][N] != INT_MAX ) return dp[K][N];
        if( K == 0 || N == 0 ) return dp[K][N];
        
        
        dp[K][N] = INT_MAX;
        for(int i = 0; i <= N/2; i++){
            int N_l = i;
            int N_r = N-1-i;
            int result = max(recursive(K-1, N_l, dp), recursive(K, N_r, dp));
            if( result == INT_MAX) continue;
            dp[K][N] = min(dp[K][N], 1 + result);
        }
        
        return dp[K][N];
    }

};
