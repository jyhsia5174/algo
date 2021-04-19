// 6 110m
class Solution {
public:
    unordered_map<int, vector<vector<int>>> E;
    unordered_set<int> noncrit;
    
    bool dfs(int x, int p, vector<int> ids, int targW, int targx){
        if( x == targx ){
            noncrit.insert(ids.begin(), ids.end());
            return !ids.empty();
        }
        
        bool res = false;
        for(auto &e: E[x]){
            if( e[0] == p ) continue;
            vector<int> nids = ids;
            if( e[1] == targW )
                nids.push_back(e[2]);
            res |= dfs(e[0], x, nids, targW, targx );
        }
        
        return res;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> orgE;
        for(int i = 0; i < edges.size(); i++){
            auto &e = edges[i]; // bug1: edges is two level array
            orgE[e[0]].push_back( {e[0], e[1], e[2], i} );
            orgE[e[1]].push_back( {e[1], e[0], e[2], i} );
        }
        
        auto comp = []( vector<int> &l,  vector<int> &r){
            return l[2] > r[2]; // bug4: l[2] > r[2] put smaller front
        }; // comp function should trailing with ;
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> Q(comp); // bug3: Q(comp)
        vector<int> used(n, false);
        used[0] = true;
        unordered_set<int> treeE;
        for(auto &e: orgE[0])
            Q.push(e);
        while(!Q.empty()){
            vector<int> e = Q.top();
            Q.pop();
            if( used[e[1]] ) continue;
            treeE.insert(e[3]);
            used[e[1]] = true;
            E[e[0]].push_back({e[1], e[2], e[3]}); // bug5: {to, from} should swap position
            E[e[1]].push_back({e[0], e[2], e[3]});
            for(auto &ne: orgE[e[1]])
                Q.push(ne);
        }
        
        for(auto &id: treeE){
            cout << id << " ";
        }
        cout << endl;
        
        for(int i = 0; i < edges.size(); i++){ // bug6: i < edges.size() not n
            if( treeE.find(i) != treeE.end() ) continue;
            auto &e = edges[i];
            cout << e[0] << " " << e[1] << endl;
            if( dfs(e[0], -1, {}, e[2], e[1]) )
                noncrit.insert(i);
        }
        
        vector<int> crit;
        vector<int> ncrit(noncrit.begin(), noncrit.end());
        for(auto &id: treeE)
            if( noncrit.find(id) == noncrit.end() )
                crit.push_back(id);
        
        return { crit, ncrit };
    }
};
