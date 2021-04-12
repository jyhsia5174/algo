// 733. Flood Fill
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int m = image.size();
        const int n = image[0].size();
        
        
        const int t_color = image[sr][sc];
        if( newColor == t_color ) return image;
        
        queue<pair<int, int>> Q;
        Q.push( {sr, sc} );
        while( !Q.empty() ){
            queue<pair<int, int>> Qtmp;
            while( !Q.empty() ){
                auto [x, y] = Q.front();
                Q.pop();
                image[x][y] = newColor;
                for(int i = 0; i < 4; i++){
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if( xx >= 0 && xx < m 
                       && yy >= 0 && yy < n 
                       && image[xx][yy] == t_color){
                        Qtmp.push( {xx, yy} );
                    }
                }
            }
            swap( Q, Qtmp );
        }
        
        return image;
    }
    
private:
    vector<int> dx {0, 0, 1, -1};
    vector<int> dy {1, -1, 0, 0};
};
