/*
242. Valid Anagram
Runtime: 12 ms, faster than 62.20% of C++ online submissions for Valid Anagram.
Memory Usage: 7.4 MB, less than 81.74% of C++ online submissions for Valid Anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() )
            return false;
        
        const int n = s.size();
        if( n == 0 )
            return true;
        
        unordered_map<char, int> m1, m2;
        for(int i = 0; i < n; i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        
        for(auto &kv: m1){
            if( m2.find(kv.first) == m2.end() )
                return false;
            
            if( m2[kv.first] != kv.second )
                return false;
        }
        
        return true;
    }
};
