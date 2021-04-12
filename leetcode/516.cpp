// 516. Longest Palindromic Subsequence

// recursive with memerization

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int N = s.size();
        
        cache.resize(N+1, vector<int>(N, 0));
        
        return lps(s, 0, N);
    }
    
    int lps(const string &s, int l, int r ){
        if( r - l <= 1 ) return r-l;
        if( cache[r-l][l] != 0 ) return cache[r-l][l];
        
        int L = 0;
        if( s[l] == s[r-1] )
            L = max(L, lps(s, l+1, r-1) + 2);
        
        L = max(L, max(lps(s, l, r-1), lps(s, l+1, r)) );
        
        cache[r-l][l] = L;
        return L;
    }
    
    vector<vector<int>> cache;
};

// dp


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int N = s.size();
        
        vector<vector<int>> dp(N, vector<int>(N+1, 0));
        for(int i = 0; i < N; i++)
            dp[i][i+1] = 1;
        
        for(int i = 1; i <= N; i++){
            for(int l = 0; l+i < N; l++){
                int r = l + i; // [l, r]
                if( s[l] == s[r] ){
                    dp[l][r+1] = max(dp[l][r+1], dp[l+1][r] + 2); 
                }
                
                if( l < r-1 && s[l] == s[r-1] ){
                    dp[l][r+1] = max(dp[l][r+1], dp[l+1][r-1] + 2);
                }
                
                if( l+1 < r && s[l+1] == s[r] ){
                    dp[l][r+1] = max(dp[l][r+1], dp[l+2][r] + 2);
                }
                
                dp[l][r+1] = max(dp[l][r+1], dp[l+1][r+1]);
                dp[l][r+1] = max(dp[l][r+1], dp[l][r]);
                dp[l][r+1] = max(dp[l][r+1], 1);
            }
            
        }
        
        return dp[0][N];
    }
};
