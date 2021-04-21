// 1192. Critical Connections in a Network


class Solution {
public:
    unordered_map<int, vector<int>> E;
    int curT = 0;
    vector<int> invs;
    vector<int> t1, t2;
    
    void dfs(int x, int p){
        invs[x] = true;
        t1[x] = t2[x] = curT;
        curT++;
        for(auto y: E[x]){
            if( y == p ) continue; // bug1: skip parent
            if(invs[y]){ // bug2: not invs[x] ....
                t2[x] = min(t2[x], t1[y]);
                continue;
            }
            dfs(y, x);
            t2[x] = min(t2[x], t2[y]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto &v: connections){
            E[v[0]].push_back(v[1]);
            E[v[1]].push_back(v[0]);
        }
        
        invs.resize(n, false);
        t1.resize(n);
        t2.resize(n);
        
        for(int i = 0; i < n; i++){
            if(invs[i]) continue;
            dfs(i, -1);
        }
        
        vector<vector<int>> sol;
        for(auto &v: connections){
            int x = v[0], y = v[1];
            if(t1[x] < t1[y]) swap(x, y);
            if(t1[x] <= t2[x]){
                sol.push_back(v);
            }
        }
        
        return sol;
    }
};


// old version
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& C) {
        G.resize(n);
        iota( G.begin(), G.end(), 0);
        D.resize(n, 1);
        
        E.resize(n);
        for(auto &e: C){
            E[e[0]].push_back( e[1] );
            E[e[1]].push_back( e[0] );
        }
        
        visited.resize(n, false);
        vector<int> path;
        for(int i = 0 ; i < n; i++){
            if( !visited[i] ) dfs(i, path);
            path.clear();
        }
        
        vector<vector<int>> res;
        for(auto &e: C){
            int a = e[0];
            int b = e[1];
            if( parent( a ) != parent( b ) )
                res.push_back( {a, b} );
        }
        
        return res;
    }
    
    void dfs( int n, vector<int> &path ){
        int from_n = (path.empty())? -1: path.back();
        visited[n] = true;
        path.push_back(n);
        for(auto &next_n: E[n]){
            if( from_n == next_n ) continue;
            if( visited[next_n] ){
                for(int i = path.size()-1; i >= 0; i--){
                    if( parent(next_n) == parent(path[i]) ) break;
                    merge(next_n, path[i]);
                }
            }
            else{
                dfs(next_n, path);
            }
        }
        path.pop_back();
    }

private:
    vector<int> G;
    vector<int> D;
    vector<bool> visited;
    vector<vector<int>> E; 
    
    int parent(int n){
        if( G[n] == n ) return n;
        G[n] = parent( G[n] );
        return G[n];
    }
    
    void merge(int n, int nn){
        int gid1 = parent( n );
        int gid2 = parent( nn );
        
        if( D[gid1] > D[gid2] ){
            G[gid2] = gid1;
            D[gid1] += D[gid2];
        }
        else{
            G[gid1] = gid2;
            D[gid2] += D[gid1];
        }
    }
};
