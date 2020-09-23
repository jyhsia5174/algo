// 438. Find All Anagrams in a String
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans; 
        if( p.size() > s.size() ) return ans;
        
        int p_count[26], s_count[26];
        for(int i = 0; i < 26; i++)
            p_count[i] = s_count[i] = 0;
        
        for(auto &c: p)
            p_count[c-'a'] ++;
        
        for(int i = 0; i < p.size(); i++)
            s_count[s[i]-'a']++;
        
        if( match(p_count, s_count) ) ans.push_back(0);
        
        for(int i = 1; i < s.size() - p.size() + 1; i++){
            s_count[s[i-1] - 'a']--;
            s_count[s[i+p.size()-1] - 'a']++;
            if( match(p_count, s_count) ) ans.push_back(i);
        }
        
        return ans;
    }
    
    bool match(int a[26], int b[26]){
        for(int i = 0; i < 26; i++)
            if( a[i] != b[i] )
                return false;
        return true;
    }
};
