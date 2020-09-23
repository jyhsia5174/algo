// 1249. Minimum Remove to Make Valid Parentheses
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        string tmp;
        
        for(int i = 0; i < s.size(); i++){
            if( s[i] == '(' ){
                count ++;
            }
            else if( s[i] == ')' ){
                if( count == 0 ) continue;
                count --;
            }
            tmp += s[i];
        }
        
        if( count == 0 ) return tmp;
        count = 0;
        string res;
        for(int i = tmp.size()-1; i >= 0; i--){
            if( tmp[i] == ')' ){
                count ++;
            }
            else if( tmp[i] == '(' ){
                if( count == 0 ) continue;
                count --;
            }
            res += tmp[i];
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
