/*
L   l   r   m
1   0   0   0   0   -1  1   0
2   0   1   0   0   -1   1   1
3   0   2   1   0   0   2   2
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if( A.size() == 0 && B.size() == 0 )
            return 1;
        if( A.size() < B.size() ) swap(A, B);
        
        int m = A.size(), n = B.size();
        int target = (m+n+1) / 2;
        B.push_back(INT_MAX);
        int lo = 0, hi = n-1;
        int anext = target-1, bnext = 0;
        while( lo <= hi ){
            int mi = lo + (hi - lo) / 2;
            int ai = lower_bound(A.begin(), A.end(), B[mi]) - A.begin();
            int aj = lower_bound(A.begin(), A.end(), B[mi+1]) - A.begin();
            int cnt1 = ai + mi;
            int cnt2 = aj + mi + 1;
            if( target > cnt1 && target <= cnt2 ){
                int x = target - cnt1 - 1;
                if( x == 0 ){
                    anext = ai;
                    bnext = mi;
                }
                else{
                    anext = ai + x + -1;
                    bnext = mi+1;
                }
                break;
            }
            else if( target <= cnt1 ){
                hi = mi-1;
            }
            else if( target > cnt2 ){
                lo = mi+1;
            }
        }
        
        cout << anext << " " << bnext << endl;
        double res = 0;
        if(anext < m && bnext < n){
            res += min( B[bnext], A[anext] );
            if( B[bnext] <= A[anext] ) 
                bnext++;
            else
                anext++;
        }
        else if( anext < m ){
            res += A[anext];
            anext++;
        }
        else{
            res += B[bnext];
            bnext++;
        }
        
        if( (m+n) % 2 == 1 ) return res;
        
        if(anext < m && bnext < n){
            res += min( B[bnext], A[anext] );
            if( B[bnext] <= A[anext] ) 
                bnext++;
            else
                anext++;
        }
        else if( anext < m ){
            res += A[anext];
            anext++;
        }
        else{
            res += B[bnext];
            bnext++;
        }
        return res / 2.0;
    }
};
