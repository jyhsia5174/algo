class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        if( s.size() == 0)
            return false;
        
        L = s.size();
        lps = new int[L];
        
        createLPS( s );
        
        if( lps[L-1] == 0 || s.size() % (L - lps[L-1]) != 0 )
            return false;
        return true;
    }
    
    void createLPS(string &s){
        int len = 0;
        lps[0] = 0;
        
        int i = 1; 
        while( i < L){
            if( s[i] == s[len] ){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if( len > 0 ){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

    }
    
private:
    int *lps;
    int L;
};
