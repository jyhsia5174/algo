// 887. Super Egg Drop

// math solution

class Solution {
public:
    int superEggDrop(int K, int N) {
        int lo = 1, hi = N;
        int t = N;
        while( lo <= hi ){
            int mi = (lo + hi)/2;
            if( f(mi, K, N) >= N ){
                hi = mi-1;
                t = mi;
            }
            else{
                lo = mi+1;
            }
        }
        
        return t;
    }
    
    int f(int t, int k, int n){
        int x = 1;
        int res = 0;
        for(int i = 1; i <= k; i++){
            x *= t - (i-1);
            x /= i;
            res += x;
            if( res >= n ) break;
        }
        
        return res;
    }
};

// dp with optimal criterion

class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[K+1][N+1];
        int optX[K+1];
        for(int i = 1; i <= K; i++)
            optX[i] = 1;
        
        for(int i = 1; i <= K; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int j = 1; j <= N; j++)
            dp[1][j] = j;
        
        for(int j = 2; j <= N; j++){
            for(int i = 2; i <= K; i++){
                dp[i][j] = max( dp[i-1][optX[i]-1], 
                              dp[i][j - optX[i]]);
                while( optX[i] + 1 <= j &&
                      dp[i][j] > max(dp[i-1][optX[i]+1-1], 
                              dp[i][j - optX[i] - 1]) ){
                    dp[i][j] = max(dp[i-1][optX[i]+1-1], 
                              dp[i][j - optX[i] - 1]);
                    optX[i]++;
                }
                
                dp[i][j] += 1;
            }
        }
        
        return dp[K][N];
    }
};

// dp

class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[K+1][N+1];
        
        for(int i = 1; i <= K; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int j = 1; j <= N; j++)
            dp[1][j] = j;
        
        for(int i = 2; i <= K; i++){
            for(int j = 2; j <= N; j++){
                dp[i][j] = INT_MAX;
                for(int k = 1; k <= j; k++){
                    int res = max( dp[i-1][k-1], dp[i][j-k] );
                    if( res < dp[i][j] )
                        dp[i][j] = res;
                }
                dp[i][j] += 1;
            }
        }
        
        return dp[K][N];
    }
};

// 

class Solution {
public:
    int superEggDrop(int K, int N) {
        if( N == 0 || N == 1)
            return N;
        
        if(K == 1)
            return N;
        
        int min = INT_MAX, x, res;
        
        for(x = 1; x <= N; x++){
            res = max(superEggDrop(K-1, x-1),
                     superEggDrop(K, N-x));
            if(res < min)
                min = res;
        }
        
        return min + 1;
    }
};

// O(NKlogK)
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
        int lo = 0, hi = N-1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int r1 = recursive(K-1, mid, dp);
            int r2 = recursive(K, N-1-mid, dp);
            
            if( r1 < r2 )
                lo = mid + 1;
            else
                hi = mid - 1;
            
            if( r1 != INT_MAX && r2 != INT_MAX )
                dp[K][N] = min( dp[K][N], 1 + max(r1, r2) );
        }
        
        return dp[K][N];
    }

};

// O(NK^2)
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
