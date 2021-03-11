// 1h15m 3
// singed int overflowed
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    LL n, m;

    cin >> n >> m;

    vector<LL> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-1];

    m--;
    vector<int> perm(n);
    int val = 1;
    int x = 0, y = n-1;
    while( x <= y ){
        int k = y-x;
        if( m >= dp[k] ){
            perm[y] = val;
            m -= dp[k];
            y--;
        }
        else{
            perm[x] = val;
            x++;
        }

        val++;
    }

    for(auto &v: perm)
        cout << v << " ";
    cout << endl;
    return 0;
}
