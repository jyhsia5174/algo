class Solution {
public:
    int n1, n2, n3;
    vector<vector<int>> E;
    vector<int> go, lx, ly, sl;
    vector<bool> usx, usy;
    const int inf = INT_MAX/2;
    
    bool dfs(int x){
        usx[x] = true;
        for(int i = 0; i < n3; i++){
            if( usy[i] ) continue;
            int v = lx[x] + ly[i] - E[x][i];
            if( v ){
                sl[i] = min(sl[i], v);
            }
            else{
                usy[i] = true;
                if( go[i] == -1 || dfs(go[i]) ){
                    go[i] = x;
                    return 1;
                }
            }
        }
        return 0;
    }
    
    int connectTwoGroups(vector<vector<int>>& cost) {
        n1 = cost.size();
        n2 = cost[0].size();
        n3 = max(n1, n2);
        
        int ans = 0;
        vector<int> rmin(n1, inf), cmin(n2, inf);
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                rmin[i] = min(rmin[i], cost[i][j]);
                cmin[j] = min(cmin[j], cost[i][j]);
            }
        }
        
        for(auto &a: rmin)
            ans += a;
        for(auto &a: cmin)
            ans += a;
        
        E.resize(n3, vector<int>(n3, 0));
        go.resize(n3, -1);
        lx.resize(n3, 0);
        ly.resize(n3, 0);
        sl.resize(n3);
        usx.resize(n3, false);
        usy.resize(n3, false);
        
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                E[i][j] = max(rmin[i] + cmin[j] - cost[i][j], 0);
            }
        }
        
        for(int i = 0; i < n3; i++){
            lx[i] = *max_element(E[i].begin(), E[i].end());
        }
        
        for(int i = 0; i < n3; i++){
            fill(sl.begin(), sl.end(), inf);
            while(1){
                fill(usx.begin(), usx.end(), false);
                fill(usy.begin(), usy.end(), false);
                usx[i] = true;
                if( dfs(i) ) break;
                int d = inf;
                for(int j = 0; j < n3; j++){
                    if( !usy[j] )
                        d = min(d, sl[j]);
                }
                
                for(int j = 0; j < n3; j++){
                    if( usx[j] ){
                        lx[j] -= d;
                    }
                    
                    if( usy[j] )
                        ly[j] += d;
                    else
                        sl[j] -= d;
                }
            }
        }
        
        for(int j = 0; j < n2; j++)
            if( go[j] < n1 )
                ans -= E[go[j]][j];
        
        return ans;
    }
};



class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n1 = cost.size();
        int n2 = cost[0].size();
        const int inf = INT_MAX/2;
        
        vector<vector<int>> dp(1<<n1, vector<int>(n2+1, inf));
        
        dp[0][0] = 0;
        for(int i = 1; i <= n2; i++){
            for(int j = 0; j < (1<<n1); j++){
                for(int k = 0; k < n1; k++){
                    int x = 1<<k;
                    if((j&x) == 0) continue; // bug1: == have hight precedence than & 
                    dp[j][i] = min(dp[j][i], min(dp[j][i], dp[j][i-1]) + cost[k][i-1]);
                    dp[j][i] = min(dp[j][i], min(dp[j-x][i], dp[j-x][i-1]) + cost[k][i-1]);
                }
            }
        }
        
        return dp[(1<<n1)-1][n2];
    }
};
