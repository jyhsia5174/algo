#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL t, n;
vector<LL> A;
vector<vector<LL>> B;

void op(LL i, LL j, LL x){
    B.push_back( {i, j, x} );
    A[i] -= i*x;
    A[j] += i*x; // bug1: i*x not j+x
}

void solve(){
    if( n == 1 ){ // bug3: corner case
        cout << 0 << endl;
        return;
    }

    B.clear();
    LL sum = 0;
    for(int i = 1; i <= n; i++)
        sum += A[i];

    if( sum % n != 0 ){
        cout << -1 << endl;
        return;
    }

    LL targ = sum/n;
    for(int i = 2; i <= n; i++){
        if( A[i] % i != 0 ){
            op(1, i, i - (A[i]%i));
        }
        op(i, 1, A[i]/i);
    }

    for(int i = 2; i <=n; i++){
        op(1, i, targ);
    }
    
    cout << B.size() << endl;
    for(auto &v: B)
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        A.resize(n+1, 0);
        for(int i = 1; i <= n; i++)
            cin >> A[i];
        solve();
    }
    return 0;
}
