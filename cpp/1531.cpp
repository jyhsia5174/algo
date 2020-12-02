class Solution {
public:
    unordered_map<int, int> dp;
    int getLengthOfOptimalCompression(string s, int k) {
        int res = solver(2600, s, 0, k);
        return res;
    }
    
    int encode( char c, int count ){
        return ( c - 'a' ) * 100 + count - 1;
    }
    
    int getLen( int E ){
        if( E == 2600 )
            return 0;
        
        int count = (E % 100) + 1;
        if( count == 1 )
            return 1;
        else if( count < 10 )
            return 2;
        else if( count < 100 )
            return 3;
        else
            return 4;
    }
    
    int solver(int pre, string &s, int idx, int k){
        int key = pre * 110 * 100 + idx * 100 + k-1;
        if( dp.count(key) )
            return dp[key];
        
        if( s.size() - idx == k || idx == s.size() ){
            dp[key] = getLen(pre);
            return dp[key];
        }
        
        char c = (pre == 2600) ? NULL : ('a' + (pre / 100));
        
        // omit s[idx]
        int length = 1 << 29;
        if( k > 0 ){
            length = solver( pre, s, idx+1, k-1 );
        }
        
        // not omit s[idx]
        if( c == NULL || (c != NULL && s[idx] != c) ){
            length = min( length, solver( encode( s[idx], 1 ), s, idx+1, k ) + getLen(pre) );
        }
        else{
            int next_pre = pre + 1;
            length = min( length, solver( next_pre, s, idx+1, k ) );
        }
        
        dp[key] = length;
        return dp[key];
    }
};

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int dp[101][101];
        memset( dp, -1, sizeof(dp) );
        return solve(s, 0, k, dp);
    }
    
    int len( int num ){
        if( num == 1 ) return 0;
        else if( num < 10  ) return 1;
        else if( num < 100 ) return 2;
        return 3;
    }
    
    int solve( string &s, int i, int k, int dp[101][101] ){
        if( k < 0 ) return 1<<29;
        if( k >= s.size() - i ) return 0;
        if( dp[i][k] != -1 ) return dp[i][k];
        
        int res = solve( s, i+1, k-1, dp );
        int cnt = 0;
        int c = s[i];
        int t = k;
        
        for(int j = i; j < s.size(); j++){
            if( s[j] == c ){
                cnt++;
                res = min( res, 1 + len(cnt) + solve( s, j+1, t, dp ) );
            }
            else{
                if( --t < 0 )
                    break;
            }
        }
        
        return dp[i][k] = res;
    }
};
