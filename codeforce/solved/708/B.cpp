// 20m 1
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(m, 0);
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        dp[a % m]++;
    }

    int ans = (dp[0] > 0)? 1 : 0;
    for(int i = 1; i < m/2 + 1; i++){
        int j = m-i;
        if(i == j){
            if(dp[i] != 0)
                ans++;
        }
        else{
            int l = dp[i];
            int r = dp[j];
            if( l > r ) swap(l, r);
            if( l > 0 ){
                r -= l;
                r --;
                ans++;
            }
            if( r > 0 ) ans += r;
        }
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while( t-- ){
        solve();
    }

    return 0;
}
