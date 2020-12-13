// 131. Palindrome Partitioning
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res = doPartition( 0, s);
        for(auto &v: res )
            reverse( v.begin(), v.end() );
        return res;
    }
    
    bool isP( const string &s ){
        int i = 0, j = s.size() - 1;
        while( i < j ){
            if( s[i] != s[j] )
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<string>> doPartition( int _i, const string &s ){
        vector<vector<string>> res;
        if( M.count(_i) >= 1 )
            return M[_i];
        if( _i == s.size() - 1 ){
            string ss = s.substr( _i, 1 );
            res.push_back( vector<string>( {ss} ) );
            return M[_i] = res;
        }
        
        string ss = s.substr( _i, 1 );
        for(int i = _i+1; i < s.size(); i++){
            if( isP(ss) ){
                vector<vector<string>> sub_res = doPartition( i, s );
                for( auto &v: sub_res ){
                    res.push_back( v );
                    res.back().push_back( ss );
                }
            }
            
            ss += s[i];
        }
        
        if( isP(ss) )
            res.push_back( vector<string>( {ss} ) );
        
        return M[_i] = res;
    }
    
    map<int, vector<vector<string>>> M ;
};
