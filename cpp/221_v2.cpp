class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0)
            return 0;
        
        m = matrix.size();
        n = matrix[0].size();
        int *dp = new int[n+1];
        for(int i = 0; i < n+1; i++)
            dp[i] = 0;
        
        int maxL = 0, prev = 0;
        for(int i = 1; i <= m ; i++){
            for(int j = 1; j <= n; j++){
                int temp = dp[j];
                if( matrix[i-1][j-1] == '0'){
                    dp[j] = 0;
                }
                else{
                    dp[j] = min<int>( min<int>( dp[j-1], prev), dp[j] ) + 1;
                    maxL = max<int>(maxL, dp[j]);
                }
                prev = temp;
            }
        }
        
        return maxL*maxL;
    }

private:
    int m, n;
};
