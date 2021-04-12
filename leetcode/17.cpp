/*
17. Letter Combinations of a Phone Number
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.6 MB, less than 90.88% of C++ online submissions for Letter Combinations of a Phone Number.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if( digits == "" )
            return res;
        
        unordered_map<int, vector<string>> m;
        m[2] = vector<string>{ "a", "b", "c" };
        m[3] = vector<string>{ "d", "e", "f" };
        m[4] = vector<string>{ "g", "h", "i" };
        m[5] = vector<string>{ "j", "k", "l" };
        m[6] = vector<string>{ "m", "n", "o" };
        m[7] = vector<string>{ "p", "q", "r", "s" };
        m[8] = vector<string>{ "t", "u", "v" };
        m[9] = vector<string>{ "w", "x", "y", "z" };
        
        backtracing("", 0, digits, m, res);
        return res;
    }
    
    void backtracing(string s, int i, const string &D, 
                     unordered_map<int, vector<string>>& m, 
                     vector<string> &res){
        if( i >= D.size() ){
            res.push_back(s);
            return;
        }
        
        int a = D[i] - '0';
        vector<string> &cands = m[a];
        for(auto &c: cands){
            backtracing(s+c, i+1, D, m, res);
        }
    }
};
