#include <bits/stdc++.h>
using namespace std;

int t, n;
string A, B;

class djs{
public:
    vector<int> p;
    djs(){
        p.resize(20);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x){
        if( x == p[x] ) return x;
        p[x] = find(p[x]);
        return p[x];
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        p[y] = x;
    }
};

void solve(){
    for(int i = 0; i < n; i++)
        if( A[i] > B[i] ){
            cout << -1 << endl;
            return;
        }

    djs S;
    for(int i = 0; i < n; i++){
        if( A[i] == B[i] ) continue;
        int u = A[i] - 'a';
        int v = B[i] - 'a';
        S.merge(u, v);
    }

    int cnt = 0;
    for(int i = 0; i < 20; i++){
        if(S.find(i) == i) cnt++;
    }

    cout << 20 - cnt << endl;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n; // bug1: forget cin >> n
        cin >> A >> B;
        solve();
    }
    return 0;
}
