// 19m 1
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> E;

void solve(){
    int vih = (E[0][n-1] == 1)? 0 : 1;

    vector<int> dist(n, -1);
    queue<int> Q, Q2;
    Q.push(0);
    dist[0] = 0;
    while( !Q.empty() ){
        while( !Q.empty() ){
            int u = Q.front();
            Q.pop();
            for(int i = 0; i < n; i++){
                if(u != i && E[u][i] == vih && dist[i] == -1){
                    dist[i] = dist[u] + 1;
                    Q2.push(i);
                }
            }
        }
        swap(Q, Q2);
    }

    cout << dist[n-1] << endl;
}

int main(){
    cin >> n >> m;
    E.resize(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        E[u][v] = 1;
        E[v][u] = 1;
    }

    solve();
}
