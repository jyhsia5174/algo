// 5 60m
#include <bits/stdc++.h>
using namespace std;

class solver{
public:
    void sol(){
        cin >> n >> m;

        perm.resize(n);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);

        for(auto &v: perm)
            cin >> v;

        int x, y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            x--; y--;
            merge(x, y);
        }

        for(int i = 0; i < n; i++){
            int grpid = root(i);
            M[grpid].push(perm[i]);
        }

        for(int i = 0; i < n; i++){
            int grpid = root(i);
            cout << M[grpid].top() << " ";
            M[grpid].pop();
        }
        
    }

    int root(int x){
        if(x == p[x])
            return x;

        p[x] = root(p[x]);
        return p[x];
    }

    void merge(int x, int y){
        x = root(x); y = root(y);
        if( x == y )
            return;
        if(sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }

    int n, m;
    vector<int> perm;
    vector<int> p;
    vector<int> sz;
    unordered_map<int, priority_queue<int>> M;
};

int main(){
    ios_base::sync_with_stdio(false);
    solver mySol;
    mySol.sol();
    return 0;
}
