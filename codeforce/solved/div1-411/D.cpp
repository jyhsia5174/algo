#include <bits/stdc++.h>
using namespace std;

class djs{
    public:
        vector<int> parent;
        djs(){
            parent.resize(1e5+1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x){
            if( parent[x] == x ) return x;
            parent[x] = find( parent[x] );
            return parent[x];
        }

        void merge(int x, int y){
            x = find(x);
            y = find(y);
            if( x == y ) return;
            parent[y] = x; 
        }
};

int n, m, q;
djs S;
vector<vector<int>> E;
unordered_map<int, vector<int>> M;
vector<vector<int>> cdp;
unordered_map<int, int> diam;

int dfs(int x, int p){
    for(auto &nx: E[x]){
        if( nx != p ){
            cdp[x].push_back(dfs(nx, x));
        }
    }

    sort(cdp[x].begin(), cdp[x].end(), greater<int>);

    diam[S.find(x)] = cdp[x][0]+1;
    return dp+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    E.resize(n);
    cdp.resize(n);

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        S.merge(l, r);
        E[l].push_back(r);
        E[r].push_back(l);
    }

    for(int i = 0; i < n; i++){
        if( S.find(i) == i ){
            dfs(i, -1);
        }
    }
}
