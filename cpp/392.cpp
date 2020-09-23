// 392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if( s.size() == 0 ) return true;
        if( t.size() == 0 ) return false;
        vector<bool> visited(s.size(), false);
        
        int idx = 0;
        for(int i = 0; i < t.size() && idx < s.size(); i++){
            if( s[idx] == t[i] ){
                idx++;
            }
        }
        
        if( idx == s.size() )
            return true;
        return false;
    }
};
