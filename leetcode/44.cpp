// 44. Wildcard Matching
class Solution {
public:
    bool isMatch(string s, string p) {
        return doMatch( s, 0, p, 0 );
    }
    
    bool doMatch( const string &s, int ii, const string &p, int jj ){
        if( M.find( {ii, jj} ) != M.end() )
            return M[{ii,jj}];
        
        if( jj >= p.size() ){
            if( ii >= s.size() )
                return M[{ii,jj}] = true;
            return M[{ii,jj}] = false;
        }
        
        bool repeat = false;
        if( p[jj] == '*' )
            repeat = true;
        
        bool res = false;
        if( !repeat ){
            if( ii < s.size() ){
                if( s[ii] == p[jj] || p[jj] == '?' ){
                    res = doMatch( s, ii+1, p, jj+1);
                }
            }  
        }
        else{
            res = doMatch( s, ii, p, jj+1);
            if( ii < s.size() )
                res = res || doMatch( s, ii+1, p, jj);
        }
        
        return M[{ii, jj}] = res;
    }
    
    map<pair<int, int>, bool> M;
};
