// 403. Frog Jump
class Solution {
public:
    bool canCross(vector<int>& S) {
        int N = S.size();
        unordered_map<int, int> pos_to_idx;
        for(int i = 0; i < N; i++)
            pos_to_idx[S[i]] = i;
        unordered_map<int, unordered_set<int>> M;
        
        M[0].insert(1);
        for(int i = 0; i < N; i++){
            for(auto &step: M[i]){
                if( i != 0 ){
                    for(int d = -1; d < 2; d++){
                        if(step + d <= 0) continue;
                        int next_pos = S[i] + step + d;
                        if( pos_to_idx.count(next_pos) != 0 ){
                            M[pos_to_idx[next_pos]].insert(step+d);
                        }
                    }
                }
                else{
                    int next_pos = S[i] + step;
                    if( pos_to_idx.count(next_pos) != 0 ){
                        M[pos_to_idx[next_pos]].insert(step);
                    }
                }
            }
        }
        
        if( M[N-1].size() == 0 ) return false;
        return true;
    }
};
