// 127. Word Ladder
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& W) {
        W.push_back( beginWord );
        int N = W.size();
        
        int target_idx;
        auto it = find(W.begin(), W.end(), endWord);
        if( it == W.end() ) return 0;
        else target_idx = distance(W.begin(), it);
        
        unordered_map<string, int> hash_idx;
        for(int i = 0; i < N; i++)
            hash_idx[W[i]] = i;
        
        queue<pair<int, int>> Q;
        vector<int> dist(N, 1<<30);
        dist[N-1] = 0;
        Q.push( {0, N-1} );
        while( !Q.empty() ){
            auto pp = Q.front();
            Q.pop();
            int ii = pp.second;
            int cost = pp.first;
            
            string wii = W[ii];
            for(int i = 0; i < wii.size(); i++){
                for(int j = 0; j < 26; j++){
                    if( (W[ii][i] - 'a') == j )
                        continue;
                    wii[i] = j + 'a';
                    
                    if( hash_idx.count(wii) == 1 ){
                        int jj = hash_idx[wii];
                        if( cost + 1 < dist[jj] ){
                            dist[jj] = cost + 1;
                            Q.push( {dist[jj], jj} );
                        }
                    }
                }
                wii[i] = W[ii][i];
            }
        }
        
        if( dist[target_idx] == (1<<30) ) return 0;
        return dist[target_idx] + 1;
    }
    
    bool has_edge(string &s1, string &s2){
        int diff_count = 0;
        for(int i = 0; i < s1.size(); i++){
            if( s1[i] != s2[i] ) diff_count++;
            if( diff_count >= 2 ) return false;
        }
        return true;
    }
};
