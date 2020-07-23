// 785. Is Graph Bipartite?
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        
        vector<int> op_group;
        op_group.resize(N, -1);
        group.resize(N);
        gsize.resize(N, 1);
        iota(group.begin(),group.end(), 0);
        
        for(int i = 0; i < graph.size(); i++){
            for(auto &j: graph[i]){
                if( op_group[i] == -1 ) op_group[i] = parent(j);
                else merge( op_group[i], j );
                
                if( op_group[j] == -1 ) op_group[j] = parent(i);
                else merge( op_group[j], i);
                
                int pi = parent(i);
                int pj = parent(j);
                if( pi == pj ) return false;
            }
        }
        
        return true;
    }
    
    int parent( int i ){
        if( group[i] == i ) return i;
        
        group[i] = parent( group[i] );
        return group[i];
    }
    
    void merge( int ii, int jj ){
        int pii = parent(ii);
        int pjj = parent(jj);
        
        if( pii == pjj ) return;
        
        if( gsize[pii] >= gsize[pjj] ){
            group[pjj] = pii;
            gsize[pii] += gsize[pjj];
        }
        else{
            group[pii] = pjj;
            gsize[pjj] += gsize[pii];
        }
    }
    
    vector<int> group;
    vector<int> gsize;
};
