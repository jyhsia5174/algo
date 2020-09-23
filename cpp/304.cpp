// 304. Range Sum Query 2D - Immutable
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if( m == 0 ) return;
        n = matrix[0].size();
        if( n == 0 ) return;
        
        sum.resize(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j]
                    + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if( m == 0 || n == 0 )
            return 0;
        return sum[row2+1][col2+1] 
            - sum[row1][col2+1]
            - sum[row2+1][col1]
            + sum[row1][col1];
    }
    
    int n, m;
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
