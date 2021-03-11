// 27m 3
// ans int -> LL
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<LL> A(n);
    for(auto &v: A)
        cin >> v;

    LL a = 1;
    vector<LL> p2;
    while( a <= 2e10L ){
        p2.push_back(a);
        a <<= 1L;
    }

    LL ans = 0;
    unordered_map<LL, LL> M;
    for(auto &v: A){
        for(auto &trg: p2){
            LL vp = trg - v;
            if( M.find(vp) != M.end() ){
                ans += M[vp];
            }
        }
        M[v]++;
    }

    cout << ans << endl;
    return 0;
}
