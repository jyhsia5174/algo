// 5 40m
class Solution {
public:
    vector<int> dx{0, 0, 1, -1};
    vector<int> dy{1, -1, 0, 0};
    int m, n;
    vector<vector<bool>> vs;
    
    bool findpath(int val, vector<vector<int>> &H){    
        for(int i = 0; i < m; i++)
            fill(vs[i].begin(), vs[i].end(), false);
        queue<pair<int, int>> Q; // bug1: vector<int> can have a lot overhead cmp to pair<int, int>
        vs[0][0] = true;
        Q.push({0, 0});
        while(!Q.empty()){
            pair<int, int> cur =  Q.front();
            int x = cur.first, y = cur.second;
            Q.pop();
            for(int d = 0; d < 4; d++){
                int xx = x + dx[d];
                int yy = y + dy[d];
                if(xx >= 0 && xx < m && yy >= 0 && yy < n && 
                  !vs[xx][yy] && abs(H[x][y] - H[xx][yy]) <= val){
                    vs[xx][yy] = true;
                    Q.push({xx, yy});
                }
            }
        }
        
        return vs[m-1][n-1];
    }
    
    int minimumEffortPath(vector<vector<int>>& H) {
        m = H.size();
        n = H[0].size();
        vs.resize(m, vector<bool>(n, false));
        int lo = -1; // bug2: lo should have consistent property like (not a solution or is a solution)
        for(int i = 1e6; i > 0; i>>=1){
            while(lo+i <= 1e6 && 
                 !findpath(lo+i, H))
                lo += i;
        }
        
        return lo+1;
    }
};
