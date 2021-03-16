// 1h 3
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL n;
unordered_map<LL, vector<vector<LL>>> E;
vector<LL> sz;
vector<LL> len;

LL dfs(LL x, LL p){
    LL cnt = 1;
    
    for(auto &v: E[x]){
        if( v[0] != p ){
            sz[v[1]] = dfs(v[0], x);
            cnt += sz[v[1]];
        }
    }

    return cnt;
}

unordered_map<LL, double> cache;
double cmb(LL a, LL b){
    LL hc = (a+1)*10 + b;
    if( cache.find(hc) != cache.end() ) return cache[hc];
    LL res = 1;
    for(LL i = 0; i < b; i++)
        res *= (a-i);
    for(LL i = 1; i <= b; i++)
        res /= i;
    cache[hc] = res;
    return cache[hc];
}

int main(){
    cin >> n;
    //123
    sz.resize(n-1, 0);
    for(LL i = 0; i < n-1; i++){
        LL a, b, li;
        cin >> a >> b >> li;
        a--; b--;
        
        E[a].push_back( {b, (LL)len.size()} );
        E[b].push_back( {a, (LL)len.size()} );
        len.push_back(li);
    }

    dfs(0, 0);
    double total = cmb(n, 3);
    double exlen = 0;
    for(LL i = 0; i < n-1; i++){
        LL lsz = sz[i];
        LL rsz = n - lsz;
        for(LL j = 1; j <= 2; j++){
            if( lsz >= j && rsz >= 3-j ){
                exlen += (cmb(lsz, j) * cmb(rsz, 3-j) / total) * len[i] * 2; 
            }
        }
    }

    LL q;
    LL r;
    double w;
    cin >> q;
    while(q--){
        cin >> r >> w;
        r--;
        LL lsz = sz[r];
        LL rsz = n - lsz;
        for(LL j = 1; j <= 2; j++){
            if( lsz >= j && rsz >= 3-j ){
                exlen += (cmb(lsz, j) * cmb(rsz, 3-j) / total) * (w-len[r]) * 2; 
            }
        }
        len[r] = w;
        cout << setprecision(20) << exlen << endl;
    }

    return 0;
}
