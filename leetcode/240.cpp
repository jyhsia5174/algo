/*
240. Search a 2D Matrix II
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        return helper(matrix, 0, 0, m, n, target); 
    }
    
    bool helper(vector<vector<int>> &M, int x, int y, int xx, int yy, int T){
        if( x >= xx || y >= yy )
            return false;
        
        if( x+1 == xx && y+1 == yy )
            return M[x][y] == T;
        
        if( M[x][y] > T || M[xx-1][yy-1] < T )
            return false;
        
        int xm = (x + xx) / 2;
        int ym = (y + yy) / 2;
        
        bool res = false;
        res = res || helper(M, x, y, xm, ym, T);
        res = res || helper(M, x, ym, xm, yy, T);
        res = res || helper(M, xm, ym, xx, yy, T);
        res = res || helper(M, xm, y, xx, ym, T);
        
        return res;
    }
};


// 240. Search a 2D Matrix II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
        n = M.size();
        if(n == 0) return false;
        m = M[0].size();
        
        int x = 0, y = m-1;
        while( x < n && y >= 0 ){
            if( target == M[x][y] ){
                return true;
            }
            else if( target < M[x][y] ){
                y--;
            }
            else{
                x++;
            }
        }
        
        return false;
    }
private:
    int n, m;
};
