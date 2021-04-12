/*
387. First Unique Character in a String
*/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count[26];
        
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            count[c].push_back(i);
        }
        
        int sol = INT_MAX;
        for(int i = 0; i < 26; i++){
            if( count[i].size() == 1 )
                sol = min( sol, count[i][0] );
        }
        
        return (sol == INT_MAX)? -1 : sol;
    }
};
