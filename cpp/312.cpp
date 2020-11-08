// 312. Burst Balloons
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> A( nums.size() + 2, 1 );
        
        for(int i = 0; i < nums.size(); i++)
            A[i+1] = nums[i];
        
        const int N = nums.size() + 2;
        
        vector<vector<int>> dp( N, vector<int>(N, 0) );
        
        for( int l = N-3; l > -1 ; l-- ){
            for( int r = l + 2; r < N; r++ ){
                for( int m = l+1; m < r; m++ ){
                    dp[l][r] = max( dp[l][r]
                                   , A[l] * A[m] * A[r] + dp[l][m] + dp[m][r] );
                }
            }
        }
        
        return dp[0][N-1];
    }
};
