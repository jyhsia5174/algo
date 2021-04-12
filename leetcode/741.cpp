// 741. Cherry Pickup
class Solution {
public:
    int cherryPickup(vector<vector<int>>& A) {
        const int n = A.size();
        
        int dp[2*(n-1)+1][n][n];
        memset( dp, -1, sizeof(dp) );
        
        dp[0][0][0] = A[0][0];
        
        for(int t = 1; t < 2*(n-1) + 1; t++){
            for(int i = max(0, t-(n-1)); i < min(n, t+1); i++){
                for(int j = max(0, t-(n-1)); j < min(n, t+1); j++){
                    if( A[i][t-i] == -1 || A[j][t-j] == -1 )
                        continue;
                    
                    if( t < i || t < j )
                        continue;
                        
                    for(int d = 0; d < 4; d++){
                        if( i + di[d] >= 0 && j + dj[d] >= 0)
                            dp[t][i][j] = max(dp[t][i][j] ,
                                            dp[t-1][i + di[d]][j + dj[d]] );
                    }
                    
                    if( dp[t][i][j] == -1 )
                        continue;
                    
                    if( A[i][t-i] == 1 )
                        dp[t][i][j]++;
                    if( i != j && A[j][t-j] == 1 )
                        dp[t][i][j]++;
                }
            }
        }
        
        if( dp[2*(n-1)][n-1][n-1] != -1 )
            return dp[2*(n-1)][n-1][n-1];
        return 0;
    }
    
    vector<int> di { 0, 0, -1, -1};
    vector<int> dj { -1, 0, -1, 0};
};
