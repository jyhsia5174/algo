class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0)
            return 0;
        
        m = matrix.size();
        n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                tmp.push_back(matrix[i][j] - '0');
            }
            M.push_back(tmp);
        }
        
        int xx, yy;
        int maxL = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if( M[i][j] == 0)
                    continue;
                
                int L = INT_MAX;
                for(int d = 0; d < 3; d++){
                    xx = i + dx[d];
                    yy = j + dy[d];
                    if( !( xx >= 0 && xx < m && yy >= 0 && yy < n ) ){
                        L = min<int>(L, 0);
                    }
                    else{
                        L = min<int>(L, M[xx][yy]);
                    }
                }
                M[i][j] = L + 1;
                maxL = max<int>( maxL, M[i][j]);
            }
        }
        
        return maxL*maxL;
    }

private:
    int m, n;
    vector<int> dx{0, -1, -1};
    vector<int> dy{-1, 0, -1};
    vector<vector<int>> M;
};
