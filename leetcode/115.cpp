// 115. Distinct Subsequences
class Solution {
public:
    int numDistinct(string s, string t) {
        const int n1 = s.size();
        const int n2 = t.size();
        
        if( n2 == 0 || ( n2 > n1 ) )
            return 0;
        
        long long int dp[n2];
        long long int count = 0;
        memset( dp, 0, sizeof(dp) );
        dp[n2-1] = 1;
        for( int i = n1-1; i >= 0; i-- ){
            for( int j = 0; j < n2; j++ ){
                if( s[i] == t[j] ){
                    if( j == 0 ){
                        count += dp[j];
                    }
                    else{
                        dp[j-1] += dp[j];
                    }
                }
            }  
        }
        
        return count;
    }
};
