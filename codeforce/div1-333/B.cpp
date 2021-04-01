// 1 120
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, q;
vector<LL> A;
vector<LL> D;
vector<LL> L; // D[a] >= D[i]
vector<LL> R; // D[b] > D[i]

void printV(const vector<LL> &v){
    for(auto &a: v)
        cout << a << "\t";
    cout << endl;
}

void solve(){
    for(int i = 0; i < n-1; i++)
        D[i] = abs(A[i] - A[i+1]);

    stack<vector<LL>> stk;
    stk.push({LLONG_MAX, -1});
    for(int i = 0; i < n-1; i++){
        while( stk.top()[0] < D[i] )
            stk.pop();
        L[i] = stk.top()[1];
        stk.push( {D[i], i} );
    }

    stk = stack<vector<LL>>();
    stk.push({LLONG_MAX, n-1});
    for(int i = n-2; i >= 0; i--){
        while( stk.top()[0] <= D[i] )
            stk.pop();
        R[i] = stk.top()[1];
        stk.push( {D[i], i} );
    }

}

void query(int l, int r){
    LL res = 0;
    for(int i = l; i < r; i++){
        LL lo = max(L[i], (LL) l-1); // bug1: not trimming
        LL hi = min(R[i], (LL) r);
        res += D[i] * (i-lo) * (hi-i);
    }
    cout << res << endl;
}

int main(){
    cin >> n >> q;
    A.resize(n);
    D.resize(n-1);
    L.resize(n-1);
    R.resize(n-1);
    for(auto &v: A)
        cin >> v;

    solve();

    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        query(l, r);
    }
}
