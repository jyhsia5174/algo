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
