/*
22. Generate Parentheses
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        N = n;
        backtrack(0, 0, "");
        return res;
    }
    
    void backtrack(int lcnt, int rcnt, string cand){
        if( lcnt + rcnt == 2*N )
            res.push_back(cand);
        
        if( lcnt < N )
            backtrack(lcnt+1, rcnt, cand + "(");
        
        if( rcnt < lcnt )
            backtrack(lcnt, rcnt+1, cand + ")");
    }
    
private:
    int N;
    vector<string> res;
};
