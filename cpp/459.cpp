class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        if( s.size() == 1)
            return false;
        
        int m = 1;
        while( m < s.size() ){
            if( s.size() % m != 0 ){
                m++;
                continue;
            }
            
            if( is_valid(m, s) )
                return true;
            
            m++;
        }
        
        return false;
    }
    
    bool is_valid(int m, string& s){
        for(int i = m; i < s.size(); i+=m){
            for(int j = 0; j < m; j++){
                if(s[j] != s[i+j])
                    return false;
            }
        }
        
        return true;
    }
    
};
