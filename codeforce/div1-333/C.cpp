// 10 2h
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> record;

void solve(){
    if( m == 1 ){ // bug3 : corner case
        cout << 1 << endl;
        return;
    }
    vector<vector<double>> dp(n+1, vector<double>(n*m+1, 0));
    dp[0][0] = m-1;
    
    for(int i = 1; i <= n; i++){
        vector<double> preSum(n*m+2, 0); // bug1: n*m+2 not +1
        for(int j = 0; j <= n*m; j++)
            preSum[j+1] = preSum[j] + dp[i-1][j];
        for(int j = 0; j <= n*m; j++){
            int hi = j;  // bug2: hi is not inclusive
            int lo = max(0, j-m);
            dp[i][j] = preSum[hi] - preSum[lo];
            int x = record[i-1];
            if(j-x >= 0)
                dp[i][j] -= dp[i-1][j-x];
            dp[i][j] /= (m-1);
        }

    }

    int sum = 0;
    for(auto &v: record)
        sum += v;

    double res = 0;
    for(int i = 0; i < sum; i++)
        res += dp[n][i];
    cout << setprecision(20) << res + 1 << endl; // bug4: forget to add 1
}

int main(){
    cin >> n >> m;
    record.resize(n);
    for(auto &v: record)
        cin >> v;

    solve();
    return 0;
}
