#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL n;
LL maxnode = 1e7;
LL nid = 1;
vector<vector<LL>> t, inv;
vector<LL> sz;

void add(LL x){
    int curn = 0;
    for(int i = 29; i >= 0; i--){
        int bit = (x&(1<<i)) == 0;
        inv[bit][i] += sz[t[bit^1][curn]];
        if(t[bit][curn] == 0){
            t[bit][curn] = nid;
            nid++;
        };
        sz[t[bit][curn]]++;
        curn = t[bit][curn];
    }
}

int main(){
    t.resize(2, vector<LL>(maxnode, 0));
    inv.resize(2, vector<LL>(30, 0));
    sz.resize(maxnode, 0);

    cin >> n;
    for(int i = 0; i < n; i++){
        LL a;
        cin >> a;
        add(a);
    }

    LL sum = 0, x = 0;
    for(int i = 29; i >= 0; i--){
        sum += min(inv[0][i], inv[1][i]);
        if(inv[0][i] < inv[1][i]) x += (1<<i);
    }

    cout << sum << " " << x << endl;
}
