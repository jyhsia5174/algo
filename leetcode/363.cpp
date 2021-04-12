// 363. Max Sum of Rectangle No Larger Than K
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& M, int k) {
        n = M.size();
        assert( n >= 1 );
        m = M[0].size();
        assert( m >= 1 );
        arr.resize( n, 0 );
        
        int res = INF;
        for( int l = 0; l < m; l++ ){
            for( int i = 0; i < n; i++ )
                    arr[i] = 0;
            for( int r = l+1; r < m+1; r++){
                for( int i = 0; i < n; i++ )
                    arr[i] += M[i][r-1];
                res = max( res, solve( k ) );
            }
        }
        
        return res;
    }
    
    int solve( int k ){
        set<int> S;
        S.insert(0);
        
        int res = INF, currSum = 0;
        for(int i = 0; i < n; i++){
            currSum += arr[i];
            auto it = S.lower_bound( currSum - k );
            if( it != S.end() ){
                res = max( res, currSum - (*it) );
                if( res == k )
                    break;
            }
            S.insert( currSum );
        }
        
        return res;
    }

private:
    int n, m;
    vector<int> arr;
    const int INF = numeric_limits<int>::min();
};
