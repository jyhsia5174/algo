/*
1466. Reorder Routes to Make All Paths Lead to the City Zero
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& C) {
        unordered_map<int, vector<int>> road;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < C.size(); i++){
            road[C[i][0]].push_back(i);
            road[C[i][1]].push_back(i);
        }
        
        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        int res = 0;
        while( !Q.empty() ){
            queue<int> Qtmp;
            while(!Q.empty()){
                int city = Q.front();
                Q.pop();
                for(auto i: road[city]){
                    int nCity;
                    if( C[i][0] == city )
                        nCity = C[i][1];
                    else
                        nCity = C[i][0];
                    
                    if(!visited[nCity]){
                        visited[nCity] = true;
                        Qtmp.push(nCity);
                        if( nCity == C[i][1] )
                            res ++;
                    }
                }
            }
            swap( Q, Qtmp );
        }
        
        return res;
    }
};
