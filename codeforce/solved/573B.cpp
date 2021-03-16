#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> h;

int main(){
    cin >> n;
    h.resize(n);
    for(auto &v: h)
        cin >> v;

    vector<int> dp(n, INT_MAX);
    int best = 1;
    for(int i = 0; i < n; i++){
        best = min( best, h[i] );
        dp[i] = best;
        best++;
    }

    int ans = 0;
    best = 1;
    for(int i = n-1; i >= 0; i--){
        best = min( best, h[i] );
        ans = max(ans, min( dp[i], best ));
        best++;
    }

    cout << ans << endl;
    return 0;
}
