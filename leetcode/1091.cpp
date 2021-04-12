// 1091. Shortest Path in Binary Matrix
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        
        vector<vector<int>> C(N, vector<int>(N, 1<<30));
        
        if( grid[0][0] == 1 ) return -1;
        C[0][0] = 1;
        queue<pair<int, int>> Q;
        Q.push({0,0});
        
        while(!Q.empty()){
            queue<pair<int, int>> Qtmp;
            while(!Q.empty()){
                auto [x, y] = Q.front();
                Q.pop();
                for(int i = 0; i < 8; i++){
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if( xx >= 0 && xx < N && yy >= 0 && yy < N 
                       && grid[xx][yy] == 0 ){
                        if( C[x][y] + 1 < C[xx][yy] ){
                            C[xx][yy] = C[x][y] + 1;
                            Qtmp.push({xx, yy});
                        }
                    }
                }
            }
            swap(Q, Qtmp);
        }
        
        if( C[N-1][N-1] == 1<<30 ) return -1;
        return C[N-1][N-1];
    }
    
private:
    vector<int> dx { 1, -1, 0, 0, 1, 1, -1, -1};
    vector<int> dy { 0, 0, 1, -1, 1, -1, 1, -1};
};
