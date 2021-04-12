// 3 1h
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& G, vector<vector<int>>& E) {
        for(int i = 0; i < n; i++){
            if(G[i] == -1){
                G[i] = m;
                m++;
            }
        }
        
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> ingrporder;
        for(int i = 0; i < n; i++){
            for(auto j: E[i]){
                indegree[j]++;
            }
        }
        
        vector<int> topoN;
        for(int i = 0; i < n; i++){
            if( indegree[i] == 0 ){
                topoN.push_back(i);
                ingrporder[G[i]].push_back(i);
            }
        }
        
        for(int i = 0; i < topoN.size(); i++){
            for(auto &j: E[topoN[i]]){
                indegree[j]--;
                if( indegree[j] == 0 ){
                    topoN.push_back(j);
                    ingrporder[G[j]].push_back(j);
                }
            }
        }
        
        if( topoN.size() != n ){
            return {};
        }
        
        unordered_map<int, vector<int>> E2;
        for(int i = 0; i < n; i++){
            for(auto j: E[i])
                if(G[i] != G[j])
                    E2[G[i]].push_back(G[j]);
        }
        
        vector<int> indegM(m, 0);
        for(int i = 0; i < m; i++){
            for(auto j: E2[i]){
                indegM[j]++;
            }
        }
        
        vector<int> topoM;
        for(int i = 0; i < m; i++){
            if(indegM[i] == 0)
                topoM.push_back(i);
        }
        
        for(int i = 0; i < topoM.size(); i++){
            for(auto j: E2[topoM[i]]){
                indegM[j]--;
                if(indegM[j] == 0){
                    topoM.push_back(j);
                }
            }
        }
        
        if( topoM.size() != m )
            return {};
        
        reverse(topoM.begin(), topoM.end());
        vector<int> sol;
        for(auto i: topoM){
            reverse(ingrporder[i].begin(), ingrporder[i].end());
            for(auto item: ingrporder[i])
                sol.push_back(item);
        }
        
        return sol;
    }
};
