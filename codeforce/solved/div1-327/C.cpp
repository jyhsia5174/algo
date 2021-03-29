// 10 2h
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;
int V;
unordered_map<int, vector<int>> E;
vector<int> dx{0, 0, -1, 1};
vector<int> dy{1, -1, 0, 0};

vector<int> pth;
void bfs(int x){
    fill(pth.begin(), pth.end(), -1);
    queue<int> Q, Q2;
    Q.push(x);
    pth[x] = 0; // bug1: not initializae 
    while(!Q.empty()){
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(auto &v: E[u]){
                if(pth[v] == -1){
                    pth[v] = pth[u]+1;
                    Q2.push(v);
                }
            }
        }
        swap(Q, Q2);
    }
}

void solve(){
    vector<int> res(V+1, 0);
    pth.resize(V+1);
    for(int i = 1; i <= 3; i++){
        bfs(i);
        for(int j = 1; j <= V; j++){ // bug2: use wrong index i insead of j
            if(res[j] == INT_MAX) continue; // bug3: not familiar with how to handle case is impossible flag
            if(pth[j] == -1)
                res[j] = INT_MAX;
            else
                res[j] += pth[j];
        }
    }

    if( res[1] == INT_MAX ){
        cout << -1;
        return;
    }

    cout << *min_element(res.begin()+1, res.end()) - 2 << endl;
}

int main(){
    cin >> n >> m;
    G.resize(n, vector<int>(m, -1));
    V = 3;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if( s[j] == '1' || s[j] == '2' || s[j] == '3' ){
                G[i][j] = s[j] - '0'; // bug4: G[j] wrong accessing
            }
            else if( s[j] == '.' ){
                V++;
                G[i][j] = V;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( G[i][j] == -1 ) continue; // bug5: G[i][j] == -1 can not have edge
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if( x >= 0 && x < n && y >= 0 && y < m 
                        && G[x][y] != -1
                        && G[i][j] != G[x][y]){ // bug6: self-edge is not allowed
                    E[G[i][j]].push_back(G[x][y]);
                }
            }
        }
    }

    solve();
    return 0;
}
