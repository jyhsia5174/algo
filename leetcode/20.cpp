class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        unordered_map<char, char> m1;
        m1['('] = ')';
        m1['['] = ']';
        m1['{'] = '}';
        
        for(int i = 0; i < s.size(); i++){
            if( m1.find(s[i]) != m1.end() ){
                stk.push(s[i]);
            }
            else{
                if( !stk.empty() && m1[stk.top()] == s[i] )
                    stk.pop();
                else
                    return false;
            }
        }
        
        if( !stk.empty() )
            return false;
        return true;
    }
};

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
