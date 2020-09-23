class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( grid[i][j] == 0 )
                    continue;
                res = max(res , get(i, j, grid));
            }
        }
        
        return res;
    }
    
    int get(int i , int j , vector<vector<int>>& grid){
        int gij = grid[i][j];
        grid[i][j] = 0;
        
        int res = 0;
        int xx, yy;
        for(int d = 0; d < 4; d++){
            xx = i + xd[d];
            yy = j + yd[d];
            
            if( !is_valid(xx, yy, grid) )
                continue;
            
            res = max<int>( res, get(xx, yy, grid) );
        }
        
        grid[i][j] = gij;
        return res + gij;
    }
        
private:
    int m, n;
    bool is_valid(int i , int j, vector<vector<int>>& grid){
        if( i < 0 || i >=m || j < 0 || j >= n)
            return false;
        if( grid[i][j] == 0 )
            return false;
        return true;
    }
    
    vector<int> xd{1, -1, 0, 0};
    vector<int> yd{0, 0, 1, -1};
};
