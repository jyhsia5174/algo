// 1584. Min Cost to Connect All Points
class Solution {
public:
    int n;
    vector<int> p;
    
    int find(int x){
        if( x == p[x] ) return x;
        return p[x] = find(p[x]);
    }
    
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if( x == y ) return false;
        p[y] = x;
        return true;
    }
    
    int minCostConnectPoints(vector<vector<int>>& P) {
        n = P.size();
        p.resize(n);
        iota(p.begin(), p.end(), 0); // bug1: not initialize p array
        vector<vector<int>> E;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                vector<int> &a = P[i];
                vector<int> &b = P[j];
                int dist = abs(a[0] - b[0]) + abs(a[1] - b[1]);
                E.push_back({i, j, dist});
            }
        }
        
        sort(E.begin(), E.end(), [](const vector<int> &l, const vector<int> &r){
            return l[2] < r[2];
        });
        
        int res = 0;
        for(auto &v: E){
            if( merge(v[0],v[1]) )
                res += v[2];
        }
        
        return res;
    }
};
