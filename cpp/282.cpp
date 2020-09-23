// 282. Expression Add Operators
typedef long long int lli;
class Solution {
public:
    vector<string> addOperators(string num, lli target) {
        T = target;
        solve( num, 0, "", 1);
        return ans;
    }
    
    void solve(string num, lli sum, string s, lli prod){
        if( num.size() == 1 ){
            if( sum + prod * (num[0]-'0') == T ){
                ans.push_back( s + num[0] );
            }
            return;
        }
        
        lli a = num[0] - '0';
        string a_s{ num[0] };
        for(int i = 1; i < num.size(); i++){
            solve( num.substr(i, num.size() - i), sum + prod * a , s+a_s+"+", 1);
            solve( num.substr(i, num.size() - i), sum + prod * a , s+a_s+"-", -1);
            solve( num.substr(i, num.size() - i), sum , s+a_s+"*", prod * a);
            if( a == 0 ) break;
            a *= 10;
            a += num[i] - '0';
            a_s += num[i];
        }
        
        if( a_s.size() == num.size() && sum + prod * a == T )
            ans.push_back( s + a_s );
    }
    
    vector<string> ans;
    int T;
};
