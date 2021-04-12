// 200. Number of Islands
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if( grid.size() == 0 ) return 0;
        m = grid.size();
        n = grid[0].size();
        
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( grid[i][j] == '0' )
                    continue;
                count += 1;
                dfs( i, j, grid);
            }
        }
        
        return count;
    }
    
    int m, n;
    vector<vector<bool>> visited;
    vector<int> dx{ 0, 0, 1, -1 };
    vector<int> dy{ 1, -1, 0, 0 };
    
    void dfs(int ii, int jj, vector<vector<char>> &grid){
        grid[ii][jj] = '0';
        for(int i = 0; i < 4; i++ ){
            int xx = ii + dx[i];
            int yy = jj + dy[i];
            
            if( (xx >= 0 && xx < m && yy >=0 && yy < n) && (grid[xx][yy]=='1') )
                dfs(xx, yy, grid);
        }
    }
};
