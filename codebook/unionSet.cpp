ass union_sum{
public:
    void init(int N){
        sz.resize(N, 1);
        p.resize(N);
        iota(p.begin(), p.end(), 0);
    }
    
    int root(int idx){
        if( p[idx] == idx )
            return idx;
        
        p[idx] = root(p[idx]);
        return p[idx];
    }
    
    void merge(int id1, int id2){
        int r1 = root(id1);
        int r2 = root(id2);
        if( r1 == r2 )
            return;
        
        if( sz[r1] > sz[r2] ){
            p[r2] = r1;
            sz[r1] += sz[r2];
        }
        else{
            p[r1] = r2;
            sz[r2] += sz[r1];
        }
    }
    
    int size(int idx){
        if( idx == -1 )
            return 0;
        return sz[root(idx)];
    }
private:
    vector<int> sz, p;
};
