// 10m 1
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    map<int, int> M;
    for(auto &v: A){
        cin >> v;
        M[v]++;
    }

    vector<int> B;
    while( B.size() < A.size() ){
        for(auto &p: M){
            if( p.second > 0 ){
                B.push_back(p.first);
                p.second--;
            }
        }
    }

    for(auto &v: B)
        cout << v << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
