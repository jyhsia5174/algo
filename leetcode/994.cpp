// 994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        queue<pair<int, int>> rotten;
        int fresh_count = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if( grid[i][j] == 2 ){
                    rotten.push( {i, j} );
                }
                else if( grid[i][j] == 1 ){
                    fresh_count++;
                }
            }
        }
        
        int time = 0;
        while( !rotten.empty() ){
            queue<pair<int, int>> tmp;
            while( !rotten.empty() ){
                auto xy = rotten.front();
                rotten.pop();
                for(int i = 0; i < 4; i++){
                    int xx = xy.first + dx[i];
                    int yy = xy.second + dy[i];
                    if( xx >= 0 && xx < M && yy >= 0 && yy < N ){
                        if( grid[xx][yy] == 1 ){
                            grid[xx][yy] = 2;
                            fresh_count --;
                            tmp.push( {xx, yy} );
                        }
                    }
                }
            }
            if( !tmp.empty() ) time++;
            swap( tmp, rotten );
        }
        
        if( fresh_count > 0 ) return -1;
            return time;
    }
private:
    int M, N;
    vector<int> dx {0, 0, 1, -1};
    vector<int> dy {1, -1, 0, 0};
};
