#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), t(n), tt(n);
    int preb = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        a[i] = l;
        b[i] = r;
        t[i] = a[i] - preb;
        preb = b[i];
    }

    for(auto &v: tt)
        cin >> v;

    int T = 0;
    for(int i = 0; i < n-1; i++){
        T += t[i] + tt[i];
        int waitT = (b[i] - a[i] + 1) / 2; 
        if( T + waitT > b[i] )
            T += waitT;
        else
            T = b[i];
    }

    T += t[n-1] + tt[n-1];
    cout << T << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
