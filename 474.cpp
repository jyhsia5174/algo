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


class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        int L = strs.size();
        dp.resize(L);
        for(int i = 0; i < L; i++)
            dp[i] = vector<vector<int>> (m+1, vector<int>(n+1, 0) );
        
        return recursive(strs, 0, m, n);
    }
    
    int recursive(vector<string>& strs, int i, int m, int n){
        if( strs.size() == i )
            return 0;
        if( dp[i][m][n] != 0 )
            return dp[i][m][n];
        
        auto [zero, one] = parse(strs[i]);
        int c1 = recursive(strs, i+1, m, n);
        int c2 = 0;
        if( m >= zero && n >= one )
            c2 = recursive(strs, i+1, m-zero, n-one) + 1;
        
        dp[i][m][n] = max(c1, c2);
        return dp[i][m][n];
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
