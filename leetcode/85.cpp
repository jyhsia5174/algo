// 85. Maximal Rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        int n = M.size();
        if( n == 0 ) return 0;
        int m = M[0].size();
        if( m == 0 ) return 0;
        
        vector<int> h;
        h.resize(m, 0);
        
        int max_area = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( M[i][j] == '1' )
                    h[j] ++;
                else
                    h[j] = 0;
                
                int y = h[j], x = 1;
                max_area = max(max_area, x * y);
                while( y > 0 && j - x >= 0 ){
                    y = min( y, h[j - x] );
                    x++;
                    max_area = max( max_area, x * y);
                }
            }
        }
        
        return max_area;
    }
};
