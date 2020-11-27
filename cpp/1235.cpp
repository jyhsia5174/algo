// 1235. Maximum Profit in Job Scheduling
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size();
        vector<int> idx(N);
        iota(idx.begin(), idx.end(), 1);
        sort(idx.begin(), idx.end(), [&](int l, int r){
            return endTime[l-1] < endTime[r-1];
        });
        
        idx.insert(idx.begin(), 0);
        startTime.insert(startTime.begin(), 0);
        endTime.insert(endTime.begin(), 0);
        profit.insert(profit.begin(), 0);
        
        int dp[N+2];
        memset( dp, 0, sizeof(int) * (N+2) );
        
        priority_queue<pair<int, int>> Q;
        for(int i = N; i >= 0 ; i--){
            dp[i] = dp[i+1];
            while(!Q.empty()){
                pair<int, int> p = Q.top();
                if( p.first < endTime[idx[i]] )
                    break;
                Q.pop();
                dp[i] = max( dp[i], dp[p.second] + profit[idx[p.second]] );
            }
            Q.push( { startTime[idx[i]], i } );
        }
        
        return dp[0];
    }
};
