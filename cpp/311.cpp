// 311. Sparse Matrix Multiplication
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        
        vector<vector<pair<int, int>>> AA;
        
        int m = A.size();
        int k = B.size();
        int n = B[0].size();
        
        AA.resize(m);
        ans.resize(m);
        for(int i = 0; i < m; i++)
            ans[i].resize(n, 0);
        
        for(int i = 0; i < m; i++){
            for( int j = 0; j < k; j++ )
                if( A[i][j] != 0 ) AA[i].push_back( {j, A[i][j]} );
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = 0;
                for(auto a_row: AA[i]){
                    sum += B[a_row.first][j] * a_row.second;
                }
                ans[i][j] = sum;
            }
        }
        
        return ans;
    }
};
