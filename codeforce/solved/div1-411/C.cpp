#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> E;
vector<vector<int>> ice;
vector<int> color;

void dfs(int v, int p){
    unordered_set<int> used;
    for(auto &x: ice[v]){
        if( color[x] != -1 ){
            used.insert(color[x]);
        }
    }

    int next_color = 1;
    for(auto &x: ice[v]){
        if( color[x] == -1 ){
            while(used.find(next_color) != used.end()){
                next_color++;
            }
            color[x] = next_color;
            next_color++;
        }
    }

    for(auto &u: E[v]){
        if( u != p )
            dfs(u, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    E.resize(n);
    ice.resize(n);
    color.resize(m, -1);

    for(int i = 0; i < n; i++){
        int k, c;
        cin >> k;
        while( k ){
            cin >> c;
            c--;
            ice[i].push_back(c);
            k--;
        }
    }

    for(int i = 0; i < n-1; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        E[l].push_back(r);
        E[r].push_back(l);
    }

    dfs(0, -1);
    for(auto &v: color)
        if( v == -1 ) v = 1;
    cout << *max_element(color.begin(), color.end()) << endl;
    for(auto &v: color)
        cout << v << " ";
    cout << endl;

    return 0;
}
