// 957. Prison Cells After N Days
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int, int> M;
        unordered_map<int, vector<int>> rM;
        
        int idx = 0;
        int s_idx;
        vector<int> tmp(8);
        while(true){
            int h_val = my_hash(cells);
            if( M.count(h_val) == 1 ){
                s_idx = M[h_val];
                break;
            }
            M[h_val] = idx;
            rM[idx] = cells;
            idx++;
            
            for(int i = 0; i < 8; i++){
                if( i == 0 || i == 7 ){
                    tmp[i] = 0;
                }
                else{
                    if( (cells[i-1] == 0 && cells[i+1] == 0) ||
                      (cells[i-1] == 1 && cells[i+1] == 1) ){
                        tmp[i] = 1;
                    }
                    else{
                        tmp[i] = 0;
                    }
                }
            }
            swap(tmp, cells);
        }
        
        int T = (N-s_idx) % (idx-s_idx);
        return rM[T+s_idx];
    }
    
    
    int my_hash(const vector<int> &cells){
        int res = 0;
        
        for(auto &v: cells){
            res <<= 1;
            res += v;
        }
        
        return res;
    }
};
