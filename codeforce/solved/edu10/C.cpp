// 52m
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<int> A(n+1), P(n+1);
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        A[i] = tmp;
        P[tmp] = i;
    }

    vector<int> dp(n+1, 0);
    for(int i = 0; i < m; i++){
        int x, y, px, py;
        cin >> x >> y;
        px = P[x];
        py = P[y];
        if( px > py ) swap(px, py);
        dp[py] = max(dp[py], px);
    }

    LL ans = 0;
    int lo = 0;
    for(int i = 1; i <= n; i++){
        lo = max(lo, dp[i]);
        ans += i - lo;
    }

    cout << ans << endl;
    return 0;
}

/*
int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<int> P(n);
    for(auto &p: P)
        cin >> p;

    unordered_map<int, vector<int>> M;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }

    LL ans = 0;
    int j = n;
    unordered_map<int, int> count;
    for(int i = n-1; i >= 0; i--){
        // remove
        if( j > i + 1 && M.find(P[i]) != M.end() ){
            for(auto &b: M[P[i]]){
                while(count[b] > 0){
                    j--;
                    count[P[j]]--;
                }
            }
        }

        count[P[i]]++;
        ans += j - i;
    }

    cout << ans << endl;
    return 0;
}
*/
