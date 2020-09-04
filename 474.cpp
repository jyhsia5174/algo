// 474. Ones and Zeroes
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp( m+1, vector<int>(n+1, 0) );
        
        for(const auto &s: strs){
            auto [zero, one] = parse( s );
            for(int i = m; i >= zero; i--){
                for(int j = n; j >= one; j--){
                    dp[i][j] = max( dp[i][j], dp[i-zero][j-one] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
    
    pair<int, int> parse(const string &s){
        int zero = 0, one = 0;
        for(int i = 0; i < s.size(); i++){
            if( s[i] == '0' )
                zero++;
            else
                one++;
        }
        
        return {zero, one};
    }
};
