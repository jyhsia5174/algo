#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }

int dp[2020][2020][2];

int solver(string &s, int m, int d){
    int n = s.size();

    memset( dp, 0, sizeof(dp) );
    dp[0][0][1] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 2; k++){
                int ni = i + 1;
                int nj, nk;
                for(int l = 0; l < (k ? int(s[i]-'0') : 9) + 1; l++){
                    if( (i&1) && l != d )
                        continue;
                    if( !(i&1) && l == d)
                        continue;
                    if( i == 0 && l == 0 )
                        continue;

                    nj = (j * 10 + l) % m;
                    nk = k && (l == s[i] - '0');
                    dp[ni][nj][nk] = add( dp[ni][nj][nk], dp[i][j][k] );
                }
            }
        }
    }

    return add( dp[n][0][0], dp[n][0][1] );
}

int check(string &s, int m, int d){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        int dig = s[i] - '0';
        if( i & 1 && dig != d  )
            return 0;
        if( !(i & 1) && dig == d )
            return 0;
        sum = (sum * 10 + dig) % m;
    }

    if( sum % m == 0 )
        return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, d;
    cin >> m >> d;

    string a, b;
    cin >> a >> b;

    int res = 0;
    res = add( res, solver(b, m, d) );
    res = sub( res, solver(a, m, d) );
    res = add( res, check(a, m, d) );

    cout << res << endl;

    return 0;
}
