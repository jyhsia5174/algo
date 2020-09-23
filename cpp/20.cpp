// 20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        
        for(int i = 0; i < s.size(); i++){
            if( s[i] == '(' || s[i] == '{'  || s[i] == '[')
                S.push( s[i] );
            else if( !S.empty() && M[s[i]] == S.top() )
                S.pop();
            else
                return false;
        }
        
        if( S.size() == 0)
            return true;
        return false;
    }
    
    unordered_map<char, char> M{ {')', '('}, {']', '['}, {'}', '{'} };
};
