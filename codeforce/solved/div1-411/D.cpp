#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

class djs{
    public:
        vector<int> parent;
        vector<int> sz;
        djs(){
            parent.resize(1e5+1);
            sz.resize(1e5+1, 1);
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
            if(x == y) return;
            if( sz[x] > sz[y] ){
                parent[y] = x;
                sz[x] += sz[y];
            }
            else{
                parent[x] = y;
                sz[y] += sz[x];
            }
        }

        int size(int x){
            x = find(x);
            return sz[x];
        }
};

int n, m, q;
djs S;
vector<vector<int>> E;
unordered_map<int, vector<int>> M;
unordered_map<int, vector<LL>> M2;
unordered_map<int, int> diam;
vector<vector<int>> cD;

int dfs(int x, int p){
    int d1 = -1, d2 = -1;
    for(auto &nx: E[x]){
        if(nx != p){
            int D = dfs(nx, x);
            d2 = max(d2, D);
            if(d1 < d2) swap(d1, d2);
        }
    }

    d1++; d2++;
    diam[S.find(x)] = max(diam[S.find(x)], d1 + d2);
    cD[x] = {d1, d2};
    return d1;
}

void dfs2(int x, int p, int dpar){
    int xD = max(cD[x][0], cD[x][1]);
    xD = max(xD, dpar);

    M[S.find(x)].push_back(xD);
    for(auto &nx: E[x]){
        if(nx != p){
            if( cD[x][0] - 1 == max( cD[nx][0], cD[nx][1] ) )
                dfs2(nx, x, max(cD[x][1], dpar) + 1);
            else
                dfs2(nx, x, max(cD[x][0], dpar) + 1);
        }
    }
}

map<vector<int>, double> cache;

void solve(int u, int v){
    u = S.find(u);
    v = S.find(v);
    if( u == v ){
        cout << -1 << endl;
        return;
    }
    
    if(S.size(u) > S.size(v)) swap(u, v);

    if( cache.find({u, v}) != cache.end() ){
        cout << cache[{u, v}] << endl;
        return;
    }

    vector<int> &dl1 = M[u];
    vector<int> &dl2 = M[v];
    vector<LL> &sum2 = M2[v];
    LL mdiam = max( diam[u], diam[v] );
    double sz1sz2 = S.size(u) * (LL) S.size(v);

    double res = 0; 
    for(auto &d1: dl1){
        LL trg = mdiam - d1 - 1;
        LL idx = lower_bound(dl2.begin(), dl2.end(), trg) - dl2.begin();
        double lcnt = idx;
        double rcnt = dl2.size() - lcnt;
        double sr = sum2.back() - sum2[idx];

        res += (mdiam*lcnt + sr + (d1+1.0) * rcnt) / sz1sz2; 
    }
    cout << setprecision(20) << res << endl;
    cache[{u, v}] = res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    E.resize(n);
    cD.resize(n);

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        S.merge(l, r);
        E[l].push_back(r);
        E[r].push_back(l);
    }

    for(int i = 0; i < n; i++){
        if(S.find(i) == i){
            dfs(i, -1); // diam and child deep
            dfs2(i, -1, 0); // M[root] = list of deep
            sort(M[i].begin(), M[i].end());
            M2[i] = vector<LL>(M[i].size()+1, 0);
            vector<LL> &sum = M2[i];
            for(int j = 1; j <= M[i].size(); j++)
                sum[j] = sum[j-1] + (LL) M[i][j-1];
        }
    }

    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        solve(u, v);
    }

    return 0;
}
