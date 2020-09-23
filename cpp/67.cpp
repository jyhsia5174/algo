// 67. Add Binary
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        
        int sz1 = a.size(), sz2 = b.size();
        if( sz1 == 0 ) return b;
        if( sz2 == 0 ) return a;
        
        int sum;
        int idx = 0;
        int reg = 0;
        while( sz1 - idx - 1 >= 0 || sz2 - idx - 1 >= 0 ){
            if( sz1 - idx - 1 >= 0 && sz2 - idx - 1 >= 0 ){
                int d1 = a[sz1 - idx - 1] - '0';
                int d2 = b[sz2 - idx - 1] - '0';
                sum = d1 + d2 + reg;
            }
            else if( sz1 - idx - 1 >= 0 ){
                int d = a[sz1 - idx - 1] - '0';
                sum = d + reg;
            }
            else{
                int d = b[sz2 - idx - 1] - '0';
                sum = d + reg;
            }
            reg = sum / 2;
            ans += (sum % 2) + '0';
            idx ++;
        }
        
        if( reg == 1 ) ans += '1';
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
