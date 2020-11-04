// 10. Regular Expression Matching
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
