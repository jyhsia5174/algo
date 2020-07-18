// 31. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        if( A.size() == 1 ) return;
        if( !next( A, 0 ) ) reverse(A.begin(), A.end());
    }
    
    bool next(vector<int>& A, int idx){
        if( idx + 2 == A.size() ){
            if( A[idx+1] > A[idx] ){
                swap( A[idx+1], A[idx] );
                return true;
            }
            return false;
        }
        
        if( next( A, idx+1 ) ) return true;
        
        int l = idx+1, r = A.size()-1;
        int jdx = -1, val = 1<<29;
        while( l <= r ){
            int m = (l + r) / 2;
            if( A[m] <= A[idx] ){
                r = m -1;
            }
            else{
                if( A[m] < val ){
                    val = A[m];
                    jdx = m;
                }
                l = m + 1;
            }
        }
        
        if( jdx == -1 ) return false;
        
        swap( A[idx], A[jdx] );
        sort(A.begin()+idx+1, A.end());
        return true;
    }
};
