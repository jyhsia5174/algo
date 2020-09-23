// String Transforms Into Another String
class union_sum{
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

class Solution {
public:
    bool canConvert(string str1, string str2) {
        int N = str1.size();
        union_sum u_set;
        u_set.init(N);
        
        // merge a-z
        vector<int> atoz;
        atoz.resize(26, -1);
        for(int i = 0; i < str1.size(); i++){
            int c1 = str1[i] - 'a';
            if( atoz[c1] == -1 ){
                atoz[c1] = i;
                continue;
            }
            
            u_set.merge(atoz[c1], i);
        }
        
        // merge str1 group by inferring str2
        vector<int> str2_count, str2_atoz;
        str2_count.resize(26, 0);
        str2_atoz.resize(26, -1);
        for(int i = 0; i < str2.size(); i++){
            int c1 = str2[i] - 'a';
            str2_count[c1] ++;
            if( str2_atoz[c1] == -1 )
                str2_atoz[c1] = i;
            u_set.merge( str2_atoz[c1], i );
        }
        
        
        int char_used = 0;
        for(int i = 0; i < 26; i++){
            int idx = str2_atoz[i];
            if( idx == -1 )
                continue;
            if( str2_count[i] != u_set.size(idx) )
                return false;
            char_used ++;
        }
        
        if( char_used == 26 ){
            for(int i = 0; i < N; i++){
                if( str1[i] != str2[i] ){
                    return false;
                }
            }
        }
        
        return true;
    }
};
