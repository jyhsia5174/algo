class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        
        int dp[m+1][n+1];
        
        for(int x1 = 1; x1 <= m ; x1++){
            for(int y1 = 1; y1 <= n ; y1++){
                
                for(int x2 = x1; x2 <= m ; x2++)
                    dp[x2][y1-1] = 0;
                for(int y2 = y1; y2 <= n; y2++)
                    dp[x1-1][y2] = 0;
                dp[x1-1][y1-1] = 0;
                
                for(int x2 = x1; x2 <= m ; x2++){
                    for(int y2 = y1; y2 <= n ; y2++){
                        
                        dp[x2][y2] = matrix[x2-1][y2-1] + dp[x2-1][y2] \
                            + dp[x2][y2-1] - dp[x2-1][y2-1];
                        
                        if( dp[x2][y2] == target )
                            count++;
                    }
                }
            }
        }
        
        return count;
    }

private:
    int count = 0;
    int m, n;
};
