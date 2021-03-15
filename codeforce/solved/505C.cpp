// 120m 20
#include <bits/stdc++.h>
using namespace std;

const int maxID = 3e4+1;
vector<int> gem;
vector<vector<int>> dp;

int main(){
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    
    gem.resize(maxID, 0);
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        gem[x]++;
    }

    dp.resize(maxID, vector<int>(256*2+1, -1));
    int ans = gem[d];
    dp[d][256] = gem[d];

    for(int i = d; i < maxID; i++){
        for(int j = -256; j <= 256; j++){
            if( dp[i][j+256] == -1 )
                continue;

            for(int k = -1; k <= 1; k++){
                int nj = j+k;
                if( k < -256 || k > 256 )
                    continue;

                int l = d + nj;
                if( l <= 0 )
                    continue;

                x = i + l;
                if( x >= maxID )
                    continue;

                dp[x][nj+256] = max(dp[x][nj+256], dp[i][j+256] + gem[x]);
                ans = max(ans, dp[x][nj+256]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
