// 1192. Critical Connections in a Network
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
