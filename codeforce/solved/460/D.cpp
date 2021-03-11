#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
unordered_map<int, vector<int>> E;
unordered_map<int, vector<int>> cnt;
int ans = 0;
vector<bool> prevvs;
vector<bool> postvs;

bool dfs( int nd ){
    prevvs[nd] = true;
    cnt[nd] = vector<int>(26, 0);

    //travsers
    for(auto &next: E[nd]){
        if( prevvs[next] && !postvs[next] ){
            postvs[next] = true;
            return true;
        }

        if( !postvs[next] ){
            if( dfs(next) ){
                postvs[next] = true;
                return true;
            }
        }

        for(int i = 0; i < 26; i++)
            cnt[nd][i] = max( cnt[nd][i], cnt[next][i] );
    }

    cnt[nd][s[nd]-'a']++;
    for(int i = 0; i < 26; i++)
        ans = max( ans, cnt[nd][i] );
    postvs[nd] = true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;
    
    int l, r;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        l--; r--;
        E[l].push_back(r);
    }

    prevvs.resize(n, false);
    postvs.resize(n, false);
    for(int i = 0; i < n; i++){
        if( !postvs[i] ){
            if( dfs(i) ){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
