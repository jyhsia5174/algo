// 15m 2
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL mod = 1e9+7;
vector<LL> dp;

void init(){
    dp.resize(1e6+1, 0);
    for(int i = 1; i <= 1e6; i++){
        assert( i < dp.size() );
        dp[i] = ((dp[i-1]+1)*2 - 1) % mod;
    }
}

LL add(LL a, LL b){
    return (a + b) % mod;
}

int main(){
    string s;
    cin >> s;
    LL n = s.size();
    init();

    LL res = 0;
    LL acnt = 0;
    for(int i = 0; i < n; i++){
        if( s[i] == 'b' ){
            res = add(res, dp[acnt]);
        }
        else{
            acnt++;
        }
    }

    cout << res << endl;
    return 0;
}
