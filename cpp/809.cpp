class Solution {
public:
    
    typedef pair<char, int> P;
    
    int expressiveWords(string S, vector<string>& words) {
        vector<P> S_ = transform( S );
        
        int cnt = 0;
        for(int i = 0; i < words.size(); i++)
            if( equal( S_, transform( words[i] )))
                cnt++;
        
        return cnt;
    }
    
    
    vector<P> transform( string &S ){
        vector<P> res;
        if( S.size() == 0 )
            return res;
        
        char cur_c = S[0];
        int count = 1;
        int i = 0, N = S.size();
        while( i < N - 1 ){
            if( S[i] != S[i+1] ){
                res.push_back( {cur_c, count} );
                cur_c = S[i+1];
                count = 0;
            }
            
            i++;
            count++;
        }
        
        res.push_back( {cur_c, count} );
        
        return res;
    }
    
    bool equal( vector<P> &a, vector<P> &&b){
        if( a.size() != b.size() )
            return false;
        
        int N = a.size();
        for(int i = 0; i < N; i++){
            char a_c = a[i].first, b_c = b[i].first;
            if( a_c != b_c )
                return false;
            
            int a_cnt = a[i].second, b_cnt = b[i].second;
            if( a_cnt != b_cnt && ( a_cnt < b_cnt || a_cnt < 3 ) ) return false;
        }
        
        return true;
    }
};
