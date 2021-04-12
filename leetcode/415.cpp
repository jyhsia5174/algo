// 415. Add Strings
class Solution {
public:
    string addStrings(string A1, string A2) {
        int m = A1.size(), n = A2.size();
        
        string ans;
        int cache = 0;
        int idx = 0;
        while( idx < m || idx < n ){
            if( idx < m && idx < n ){
                cache += A1[m-1-idx] - '0';
                cache += A2[n-1-idx] - '0';
            }
            else if( idx < m ){
                cache += A1[m-1-idx] - '0';
            }
            else{
                cache += A2[n-1-idx] - '0';
            }
            ans += '0' + ( cache % 10 );
            cache = cache / 10;
            idx++;
        }
        if( cache != 0 ) ans += '0' + ( cache % 10 );
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
