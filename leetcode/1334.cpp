// 2 11m
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int maxD) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX/2));
        
        for(int i = 0; i < n; i++) dp[i][i] = 0;
        for(auto &e: edges){
            int u = e[0], v = e[1], cost = e[2];
            dp[u][v] = dp[v][u] = cost;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); // bug1: INT overflow due to INT_MAX + INT_MAX
            }
        }
        
        int res = 0, mincnt = INT_MAX;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if( i == j ) continue;
                if( dp[i][j] <= maxD )
                    cnt++;
            }
            
            if( cnt <= mincnt ){
                res = i;
                mincnt = cnt;
            }
        }
        
        return res;
    }
};
