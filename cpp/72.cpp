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

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp( n1+1, vector<int>( n2+1, INF ) );
        
        dp[n1][n2] = 0;
        for( int i = 0; i < n1; i++ )
            dp[i][n2] = n1 - i;
        for( int j = 0; j < n2; j++)
            dp[n1][j] = n2 - j;
        
        for( int j = n2-1; j >= 0; j-- ){
            for( int i = n1-1; i>=0; i-- ){
                if( s1[i] == s2[j] ){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int cnt = INF;
                    // insert
                    cnt = min( cnt, 1 + dp[i][j+1] );
                    // delete
                    cnt = min( cnt, 1 + dp[i+1][j] );
                    // replace
                    cnt = min( cnt, 1 + dp[i+1][j+1] );
                    dp[i][j] = cnt;
                }
            }
        }
        
        return dp[0][0];
    }
    
private:
    const int INF = 1<<29;
};
