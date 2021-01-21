// Runtime: 88 ms, faster than 86.36% of C++ online submissions for Word Squares.
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        wlen = words[0].size();
        
        for(auto &w: words){
            for(int i = 0; i <= wlen; i++)
                preS[w.substr(0, i)].insert(w);
        }
        
        unordered_set<string> cache;
        solve("", cache);
        
        vector<vector<string>> res;
        for(auto &s: cache){
            vector<string> v;
            for(int i = 0; i < wlen; i++)
                v.push_back( s.substr(i*wlen, wlen) );
            res.push_back(v);
        }
        
        return res;
    }
    
    void solve(string s, unordered_set<string> &res){
        if( s.size() == wlen * wlen )
            res.insert(s);
        
        int preSize = s.size() / wlen;
        string pre = "";
        for(int i = 0; i < preSize; i++)
            pre += s[i*wlen + preSize];
        
        if( preS.find(pre) != preS.end() ){
            unordered_set<string> &cands = preS[pre];
            for(auto &w: cands)
                solve(s+w, res);
        }
    }
    
private:
    int wlen;
    unordered_map<string, unordered_set<string>> preS;
};
