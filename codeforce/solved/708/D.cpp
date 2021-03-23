// 2h
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

void solve(){
    LL n;
    cin >> n;
    vector<LL> t(n), s(n), dp(n, 0);
    for(auto &v: t)
        cin >> v;
    for(auto &v: s)
        cin >> v;

    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if( t[i] == t[j] ) continue;
            LL dpi = dp[i], dpj = dp[j], p = abs(s[i]-s[j]);
            dp[i] = max(dpi, dpj + p);
            dp[j] = max(dpj, dpi + p);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }

    return 0;
}
