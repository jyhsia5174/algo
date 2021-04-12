// 91. Decode Ways
class Solution {
public:
    int numDecodings(string s) {
        if( s.size() == 0 ) return 0;
        if( s[0] == '0' ) return 0;
        
        int count1 = 1, count2 = 0;
        
        for(int i = 1; i < s.size(); i++){
            int c1 = 0, c2 = 0;
            if( s[i] >= '1' && s[i] <= '9' )
                c1 = count1 + count2;
            else
                c1 = 0;
            
            if( s[i-1] == '1' || 
               (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6') ){
                c2 = count1;
            }
            else{
                c2 = 0;
            }
            
            count1 = c1;
            count2 = c2;
        }
        
        return count1 + count2;
    }
};
