// 763. Partition Labels
class Solution {
public:
    vector<int> partitionLabels(string S) {
        for(int i = 0; i < 26; i++){
            B[i].first = INF;
            B[i].second = -INF;
        }
        
        for(int i = 0; i < S.size(); i++){
            int chash = S[i] - 'a';
            B[chash].first = min(B[chash].first, i);
            B[chash].second = max(B[chash].second, i);
        }
        
        sort(B, B+26);
        
        int l = B[0].first;
        int r = B[0].second;
        int ii = 1;
        vector<int> res;
        while( l != INF && ii < 26 ){
            int n_l = B[ii].first;
            int n_r = B[ii].second;
            if( n_l != INF ){
                if( n_l <= r ){
                    r = max(r, n_r);
                }
                else{
                    res.push_back( r - l + 1 );
                    l = n_l;
                    r = n_r;
                }
            }
            else{
                res.push_back( r - l + 1 );
                l = n_l;
                r = n_r;
            }
            ii++;
        }
        if( l != INF ) res.push_back( r - l + 1 );
        
        return res;
    }
private:
    const int INF = 1<<29;
    pair<int, int> B[26];
};
