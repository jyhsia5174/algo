// 1428. Leftmost Column with at Least a One

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &M) {
        auto dim = M.dimensions();
        const int m = dim[0], n = dim[1];
        
        int leftmost = n;
        for(int i = 0; i < m; i++){
            int l = 0, r = leftmost;
            while( l + 1 < r ){
                int m = (l + r) / 2;
                if( M.get(i, m) == 1 ){
                    r = m;
                    leftmost = min(leftmost, m);
                }
                else{
                    l = m;
                }    
            }
            if( M.get(i, l) == 1 ) leftmost = min( leftmost, l );
        }
        
        if( leftmost == n ) return -1;
        return leftmost;
    }
};
