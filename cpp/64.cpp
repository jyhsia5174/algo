// 64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        if( m == 0 ) return 0;
        const int n = grid[0].size();
        if( n == 0 ) return 0;
        
        vector<int> dp(n+1, numeric_limits<int>::max());
        dp[1] = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[j+1] = min(dp[j], dp[j+1]) + grid[i][j];
            }
        }
        
        return dp[n];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        if( m == 0 ) return 0;
        const int n = grid[0].size();
        if( n == 0 ) return 0;
        
        queue<pair<int, int>> Q;
        vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max()));
        dp[0][0] = grid[0][0];
        Q.push( {0,0} );
        while( !Q.empty() ){
            auto [x, y] = Q.front();
            Q.pop();
            for(int i = 0; i < 2; i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if( xx >= 0 && xx < m 
                  && yy >= 0 && yy < n
                  && dp[x][y] + grid[xx][yy] < dp[xx][yy]){
                    dp[xx][yy] = dp[x][y] + grid[xx][yy];
                    Q.push( {xx, yy} );
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    vector<int> dx{1, 0};
    vector<int> dy{ 0, 1};
};
