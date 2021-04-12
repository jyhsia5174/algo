class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if( m > 0)
            n = matrix[0].size();
        else
            return 0;
        
        init();
        
        int maxL = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                maxL = max( maxL, getLPS(i, j, matrix) );
        }
        
        return maxL;
    }
    
private:
    int m, n;
    vector<vector<int>> LIP;
    vector<int> xd {0, 0, -1, 1};
    vector<int> yd {1, -1, 0, 0};
    
    int getLPS(int i, int j, vector<vector<int>>& M){
        if(LIP[i][j] != -1)
            return LIP[i][j];
        
        int maxL = 0;
        for(int d = 0; d < 4; d++){
            int xx = i + xd[d];
            int yy = j + yd[d];
            
            if( !valid_dir(xx, yy) )
                continue;
            
            if( M[xx][yy] >= M[i][j] )
                continue;
            
            if(LIP[xx][yy] == -1)
                maxL = max( maxL, getLPS(xx, yy, M) );
            else
                maxL = max( maxL, LIP[xx][yy]);
        }
        
        LIP[i][j] = maxL + 1;
        return LIP[i][j];
    }
    
    bool valid_dir(int xx, int yy){
        if( !(xx >= 0 && xx < m && yy >= 0 && yy < n) )
            return false;
        return true;
    }
    
    void init(){
        LIP.resize(m);
        for(int i = 0; i < m; i++){
            LIP[i].resize(n, -1);
        }
    }
};
