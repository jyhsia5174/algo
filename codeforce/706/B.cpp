// 30m 1
#include<bits/stdc++.h>
using namespace std;

void solve(){
    unordered_set<int> S;
    int ma = 0, me;
    int n, k;
    cin >> n >> k;
    
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        ma = max(ma, a);
        S.insert(a);
    }

    for(int i = 0; i < 1e5+1; i++){
        if( S.find(i) == S.end() ){
            me = i;
            break;
        }
    }

    if( k > 0 && me < ma ){
        S.insert( (me + ma + 1) / 2 );
        cout << S.size() << endl;
        return;
    }

    cout << S.size() + k << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
