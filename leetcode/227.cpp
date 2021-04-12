// 227. Basic Calculator II
class Solution {
public:
    int calculate(string s) {
        // Clean s
        string tmp;
        for(int i = 0; i < s.size(); i++)
            if( s[i] != ' ' )
                tmp += s[i];
        s = tmp;
        
        size_t start = -1;
        size_t end = s.find_first_of("+-", start+1);
        
        int ans = eval_mul(s.substr(start+1, end-(start+1)));
        start = end;
        end = s.find_first_of("+-", start+1);
        while( start != string::npos ){
            int mul = eval_mul(s.substr(start+1, end-(start+1)));
            if( s[start] == '+' ){
                ans = ans + mul;
            }
            else{
                ans = ans - mul;
            }
            start = end;
            end = s.find_first_of("+-", start+1);
        }
        
        return ans;
    }
    
    int eval_mul(string s){
        int start = -1;
        int end = s.find_first_of("*/", start+1);
        
        int res = stoi( s.substr(start+1, end - (start+1)) );
        start = end;
        end = s.find_first_of("*/", start+1);
        while( start != string::npos ){
            if( s[start] == '*' ){
                res = res * stoi( s.substr(start+1, end - (start+1)));
            }
            else{
                res = res / stoi( s.substr(start+1, end - (start+1)));
            }
            start = end;
            end = s.find_first_of("*/", start+1);
        }
        
        return res;
    }
    
};
