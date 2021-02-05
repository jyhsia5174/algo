/*
79. Word Search
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool> (n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                if(match(i, j, board, word, 0))
                    return true;
        }
        
        return false;
    }
    
    bool match(int x, int y, const vector<vector<char>> &board, const string &w, int idx){
        if( board[x][y] == w[idx] ){
            if(idx == w.size() - 1)
                return true;
            
            visited[x][y] = true;
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if( xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy] ){
                    if( match(xx, yy, board, w, idx+1) )
                        return true;
                }
            }
            visited[x][y] = false;
        }
        
        return false;
    }
    
private:
    int m;
    int n;
    vector<vector<bool>> visited;
    vector<int> dx{ 0, 0, 1, -1};
    vector<int> dy{ 1, -1, 0, 0};
};
