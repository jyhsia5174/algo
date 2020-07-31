// 472. Concatenated Words
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &l, const string &r){
            return l.size() < r.size();
        });
        
        vector<string> result;
        
        for(auto &w: words){
            if( dfs( w, 0) >= 2 )
                result.push_back(w);
            S.insert(w);
        }
        
        return result;
    }
    
    int dfs(string &s, int loc){
        if( s.size() == loc ) return 0;
        
        string cur_w;
        for(int i = loc; i < s.size(); i++){
            cur_w += s[i];
            if( S.count(cur_w) == 1 ){
                int count = dfs(s, i+1);
                if( count >= 0 )
                    return count + 1;
            }
        }
        
        return -1;
    }
private:
    unordered_set<string> S;
    
};
