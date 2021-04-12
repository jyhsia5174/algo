// 694. Number of Distinct Islands
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        if( m == 0 ) return 0;
        n = grid[0].size();
        if( n == 0 ) return 0;
        
        set<string> land;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( grid[i][j] == 1 ){
                    land.insert(fill(grid, i, j));
                }
            }
        }
        
        for(auto &s: land)
            cout << s << endl;
        
        return land.size();
    }
    
    string fill( vector<vector<int>> &grid, int x, int y){
        if( grid[x][y] == 0 ) return"";
        grid[x][y] = 0;
        string path = "[";
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if( xx >= 0 && xx < m && yy >= 0 && yy < n 
               && grid[xx][yy] == 1){
                path += to_string(i);
                path += fill(grid, xx, yy);
            }
        }
        path += "]";
        return path;
    }
    
    
private:
    int m, n;
    vector<int> dx{0, 0, 1, -1};
    vector<int> dy{1, -1, 0, 0};
};
