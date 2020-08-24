// 983. Minimum Cost For Tickets
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), numeric_limits<int>::max());
        vector<int> C(30);
        
        int cur_cost = costs[2];
        for(int i = 29; i >= 0; i--){
            if( i == 6 )
                cur_cost = min( cur_cost, costs[1] );
            if( i == 0 )
                cur_cost = min( cur_cost, costs[0] );
            C[i] = cur_cost;
        }
        
        for(int i = 0; i < days.size(); i++){
            if( days[0] + 30 <= days[i] )
                break;
            dp[i] = min( dp[i], C[days[i] - days[0]] );
        }
        
        for(int i = 1; i < days.size(); i++){
            for(int j = i; j < days.size(); j++){
                if( days[i] + 30 <= days[j] )
                    break;
                dp[j] = min( dp[j], C[days[j] - days[i]] + dp[i-1] );
            }
        }
        
        return dp.back();
    }
};
