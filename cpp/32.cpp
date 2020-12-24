// 32. Longest Valid Parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        if( n == 0 )
            return 0;
        
        stack<int> S;
        for(int i = 0; i < n; i++){
            if( s[i] == '(' ){
                S.push(i);
            }
            else{
                if( !S.empty() ){
                    M[S.top()] = i;
                    S.pop();
                }
            }
        }
        
        int max_len = 0;
        int cur_len = 0;
        int i = 0;
        while( i < n ){
            if( M.find(i) != M.end() ){
                cur_len += M[i] - i + 1;
                i = M[i] + 1;
            }
            else{
                max_len = max( max_len, cur_len );
                cur_len = 0;
                i++;
            }
        }
        max_len = max( max_len, cur_len );
        
        return max_len;
    }
    
    unordered_map<int, int> M;
}; 


// Better version
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stk;
        stk.push(-1);
        
        for( int i = 0; i < s.size(); i++ ){
            if( s[i] == '(' ){
                stk.push( i );
            }
            else{
                stk.pop();
                if( stk.empty() ){
                    stk.push(i);
                }
                else{
                    res = max( res, i - stk.top() );
                }
            }
        }
        
        return res;
    }
}; 
