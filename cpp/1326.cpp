// 1326. Minimum Number of Taps to Open to Water a Garden
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int N = n+1;
        
        vector<pair<int, int>> A;
        for(int i = 0; i < N; i++){
            int st = max( 0, i - ranges[i] );
            int ed = min( n, i + ranges[i] );
            A.push_back( {st, ed} );
        }
        
        sort(A.begin(), A.end());
        
        map<int, int> M;
        M[0] = 0;
        for( int i = 0; i < N; i++ ){
            auto it = M.lower_bound( A[i].first );
            if( it == M.end() )
                return -1;
            if( A[i].second > M.rbegin()->first )
                M[ A[i].second ] = it->second + 1;
        }
        
        return M.rbegin()->second;
    }
};
