class Solution {
public:
    int N;
    vector<int> par;
    vector<int> sz;
    
    void init(int _n){
        par.resize(_n);
        iota(par.begin(), par.end(), 0);
    }
    
    int find(int x){
        if( x == par[x] ) return x;
        return par[x] = find(par[x]);
    }
    
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if( x == y ) return false;
        if( x > N && y > N )  return false;
        if( x < y )  swap(x, y);
        par[y] = x;
        return true;
    }
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        N = n; // bug1: not int N = n 
        init(2*N+1);
        
        for(int i = 1; i <= n; i++)
            pipes.push_back( {i, i+n, wells[i-1]} );
        
        sort(pipes.begin(), pipes.end(), [](const vector<int> &l, const vector<int> &r){
            return l[2] < r[2];
        });
        
        int cost = 0;
        for(auto &v: pipes){
            if( merge(v[0], v[1]) ){
                cost += v[2];
            }
        }
        
        return cost;
    }
};
