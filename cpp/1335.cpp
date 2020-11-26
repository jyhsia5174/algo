class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int N = jobDifficulty.size();
        if( N < d )
            return -1;
        
        int dp[d+1][N];
        for(int i = 1; i < d+1; i++)
            for(int j = 0; j < N; j++)
                dp[i][j] = 1<<29;
        
        dp[1][N-1] = jobDifficulty[N-1];
        for(int j = N-2; j >= 0; j--)
            dp[1][j] = max( dp[1][j+1], jobDifficulty[j] );
        
        for(int i = 2; i <= d; i++){
            for(int j=0; (N-j) >= i; j++){
                int max_value = 0;
                for(int k = 0; (N-j-(k+1)) >= i-1; k++){
                    max_value = max( max_value, jobDifficulty[j+k] );
                    dp[i][j] = min( dp[i][j], max_value + dp[i-1][j+(k+1)] );
                }
            }
        }
        
        
        return dp[d][0];
    }
};
