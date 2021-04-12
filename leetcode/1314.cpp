// 1314. Matrix Block Sum
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> sum(m+1, vector<int> (n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j]
                    + mat[i][j];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int xmin = max(i-K, 0);
                int xmax = min(i+K+1, m);
                int ymin = max(j-K, 0);
                int ymax = min(j+K+1, n);
                ans[i][j] = sum[xmax][ymax] 
                    - sum[xmax][ymin]
                    - sum[xmin][ymax]
                    + sum[xmin][ymin];
            }
        }
        
        return ans;
    }
};
