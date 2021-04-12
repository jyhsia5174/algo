// Complexity O(n^3)
// Space O(n^2)

class Solution {
public:
    int getMoneyAmount(int n) {
        dp.resize(n+2);
        for(int i = 1; i < n + 2; i++ )
            dp[i].resize(n+2, 0);
        
        int result = calc_money(1, n+1);
        
        return result;
    }
private:
    vector<vector<int>> dp;
    
    int calc_money(int l, int r){
        assert(l != r);
        if( l + 1 == r )
            return dp[l][r];
        if( dp[l][r] != 0 )
            return dp[l][r];
        
        int result = l + calc_money(l+1, r);
        for(int i = l+1; i + 1 < r; i++){
            result = min( result, i + max(calc_money(l, i), calc_money(i+1, r)) );
        }
        result = min(result, r-1 + calc_money(l, r-1));
        
        dp[l][r] = result;
        return result;
    } 
};
