// 49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        
        for(auto &s: strs){
            string s_cp = s;
            sort( s_cp.begin(), s_cp.end() );
            res[s_cp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto &pp: res)
            ans.push_back( pp.second );
        
        return ans;
    }
};
