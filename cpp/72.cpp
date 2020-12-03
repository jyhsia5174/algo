// 72. Edit Distance
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp( n1, vector<int>( n2, -1 ) );
        
        return solver( s1, 0, s2, 0, dp );
    }
    
    int solver( const string &s1, int _i, const string &s2, int _j, vector<vector<int>> &dp){
        if( s1.size() <= _i  )
            return s2.size() - _j;
        
        if( s2.size() <= _j )
            return s1.size() - _i;
        
        if( dp[_i][_j] != -1 )
            return dp[_i][_j];
        
        int cnt = INF;
        
        if( s1[_i] == s2[_j] )
            cnt = min(cnt, solver( s1, _i+1, s2, _j+1, dp ) );
        
        // insert
        cnt = min( cnt, 1 + solver( s1, _i, s2, _j+1, dp ) );
        // delete
        cnt = min( cnt, 1 + solver( s1, _i+1, s2, _j, dp ) );
        // replace
        cnt = min( cnt, 1 + solver( s1, _i+1, s2, _j+1, dp ) );

        return dp[_i][_j] = cnt;
    }
private:
    const int INF = 1<<29;
};
