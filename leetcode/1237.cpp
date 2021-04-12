/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

/*
len
1 0 1 0 0 0 1
2 0 2 0 1 1 2
3 0 3 0 1 1 3
*/

/*
1 0 0 0 0 0 0
2 0 1 0 0 0 1
*/

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& f, int z) {
        vector<vector<int>> res;
        for(int i = 1; i < 1001; i++){
            // lower_bound
            int lo = 1, hi = 1001;
            while( lo + 1 < hi ){
                int mi = lo + (hi - lo) / 2;
                int ff = f.f( i, mi );
                if( ff == z ){
                    hi = mi;
                }
                else if(ff > z){
                    hi = mi;
                }
                else{
                    lo = mi;
                }
            }
            
            // lo + 1 == hi
            int lbound;
            if( f.f(i,lo) >= z )
                lbound = lo;
            else
                lbound = hi;
            
            // upper_bound
            lo = 1, hi = 1001;
            while( lo + 1 < hi ){
                int mi = lo + (hi - lo) / 2;
                int ff = f.f( i, mi );
                if( ff == z ){
                    lo = mi;
                }
                else if(ff > z){
                    hi = mi;
                }
                else{
                    lo = mi;
                }
            }
            
            int ubound;
            if( f.f(i, lo) > z )
                ubound = lo;
            else
                ubound = hi;
            
            for(int j = lbound; j < ubound; j++)
                res.push_back( {i, j} );
        }
        
        return res;
    }
};
