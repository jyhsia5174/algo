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
