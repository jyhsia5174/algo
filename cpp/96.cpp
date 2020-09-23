// 96. Unique Binary Search Trees
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n+1; i++){
            const int num_of_ch = i - 1;
            
            int l = num_of_ch;
            int r = 0;
            while( l >= 0 ){
                dp[i] += dp[l] * dp[r];
                l--;
                r++;
            }
        }
        
        return dp[n];
    }
};
