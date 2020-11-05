// 10. Regular Expression Matching

class Solution {
public:
    bool isMatch(string _s, string _p) {
        s = _s;
        p =  _p;
        for(int i = 0; i < 26; i++)
            ch.insert( 'a' + i );
        ch.insert('.');
        
        dp.resize( _s.size() + 1, vector<int>(_p.size() + 1, -1) );
        return check(0, 0);
    }
    
    bool check( int si, int pi){
        if( dp[si][pi] != -1 )
            return dp[si][pi];

        if( pi == p.size() ){
            dp[si][pi] = (si == s.size()) ? 1 : 0;
            return dp[si][pi];
        }
        
        bool one_match;
        if( (si < s.size()) && (s[si] == p[pi] || p[pi] == '.') )
            one_match = true;
        else
            one_match = false;
        
        if( pi + 1 < p.size() && p[pi + 1] == '*' ){
            if( check( si, pi+2 ) || 
               ( one_match && check( si+1, pi) ))
                dp[si][pi] = 1;
            else
                dp[si][pi] = 0;
        }
        else{
            if( one_match && check( si+1, pi+1 ) )
                dp[si][pi] = 1;
            else
                dp[si][pi] = 0;
        }
        
        return dp[si][pi];
    }
    
private: 
    string s, p;
    vector<vector<int>> dp;
    unordered_set<char> ch;
};


class Solution {
public:
    bool isMatch(string s, string p) {
        ss = s;
        pp = p;
        for(int i = 0; i < 26; i++)
            ch.insert( 'a' + i );
        ch.insert('.');
        return recursiveMatch(0, 0);
    }
    
    bool recursiveMatch( int ii, int jj){
        if( ii == ss.size() ){
            int count = 0;
            for(int j = jj; j < pp.size(); j++){
                if( ch.count( pp[j] ) == 1 )
                    count += 1;
                else
                    count -= 1;
            }
            if( count > 0 )
                return false;
            return true;
        }
        
        if( jj == pp.size() ) return false;
        char c = pp[jj];
        bool repeat = false;
        if(  jj + 1 < pp.size() && pp[jj+1] == '*' ) repeat = true;
        
        if( repeat ){
            if( recursiveMatch( ii, jj+2 ) )
                return true;
            
            for(int i = ii; i < ss.size(); i++){
                if( c != '.' && c != ss[i] )
                    break;
                
                if( recursiveMatch( i+1, jj+2) )
                    return true;
            }
        }
        else{
            if( c == ss[ii] || c == '.' )
                return recursiveMatch( ii+1, jj+1);
        }
        return false;
    }
    
private: 
    string ss, pp;
    unordered_set<char> ch;
};
