// 30m 2
#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> A;

void solve(){
    unordered_map<int, int> preI;
    unordered_map<int, int> dist;
    for(int i = 0; i < n; i++){
        int d = i - preI[A[i]];
        dist[A[i]] = max(dist[A[i]], d);
        preI[A[i]] = i+1;
    }

    for(auto &kv: preI){
        int a = kv.first;
        int i = kv.second;
        dist[a] = max(dist[a], n - i); 
    }

    vector<vector<int>> B;
    for(auto &kv: dist){
        B.push_back({kv.second, kv.first});
    }
    sort(B.begin(), B.end());

    for(int i = 1; i < B.size(); i++){ // bug1: reverse the order..
        B[i][1] = min(B[i][1], B[i-1][1]);
    }

    int x = -1;
    for(int i = 1; i <= n; i++){
        while(x+1 < B.size() && B[x+1][0] < i)
            x++;

        if(x == -1){
            cout << -1 << " ";
            continue;
        }

        cout << B[x][1] << " ";
    }
    cout << endl;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        A.resize(n);
        for(auto &a: A)
            cin >> a;
        solve();
    }
    return 0;
}
