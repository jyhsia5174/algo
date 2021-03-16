// 25m 2
// int sum overvlow ... use LL
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<LL> value;
vector<LL> dp;
unordered_map<LL, LL> M[26];

int main(){
    value.resize(26);
    for(auto &v: value)
        cin >> v;

    string s;
    cin >> s;
    n = s.size();
    dp.resize(n+1, 0);
    for(int i = 0; i < n; i++)
        dp[i+1] = dp[i] + value[s[i]-'a'];

    LL ans = 0;
    M[s[0]-'a'][ dp[1] ] = 1;
    for(int i = 1; i < n; i++){
        LL sum = dp[i];
        int c = s[i] - 'a';
        ans += M[c][sum];
        M[c][dp[i+1]]++;
    }

    cout << ans << endl;
    return 0;
}
