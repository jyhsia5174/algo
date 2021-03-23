// 19m 1
#include <bits/stdc++.h>
using namespace std;

int n;
int root;
unordered_map<int, bool> M;
vector<int> val, lch, rch, indegree;

void dfs(int nid, int pid, int lmax, int rmin){
    if( nid == -1 ) return;
    if( val[nid] >= lmax && val[nid] < rmin ) {
        M[val[nid]] = true;
    }

    dfs(lch[nid], nid, lmax, min(rmin, val[nid]));
    dfs(rch[nid], nid, max(lmax, val[nid]), rmin);

    return;
}

void solve(){
    cin >> n;
    val.resize(n);
    lch.resize(n);
    rch.resize(n);
    indegree.resize(n, 0);

    for(int i = 0; i < n; i++){
        int v, l, r;
        cin >> v >> l >> r;
        if(l>0) l--; 
        if(r>0) r--;
        val[i] = v;
        lch[i] = l;
        rch[i] = r;
        if(l>=0) indegree[l]++;
        if(r>=0) indegree[r]++;
        M[v] = false;
    }

    for(int i = 0; i < n; i++){
        if( indegree[i] == 0 ){
            dfs(i, -1, INT_MIN, INT_MAX);
            break;
        }
    }

    int fail = 0;
    for(int i = 0; i < n; i++){
        if( !M[val[i]] )
            fail++;
    }
    cout << fail << endl;

    return;
}

int main(){
    solve();
}
