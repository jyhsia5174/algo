// 24 Game
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> dnums;
        for(auto a : nums)
            dnums.push_back(a);
        
        vector<int> mask;
        mask.resize(4, 1);
        
        generate( dnums, mask );
        
        for(auto a: table[15]){
            if( abs(24 - a) < 1e-6 )
                return true;
        }
        return false;
    }
private:
    unordered_set<double> table[16];
    
    void generate(vector<double>& dnums, vector<int>& mask){
        int idx = get_idx(mask);
        int size = get_size(mask);
        
        if( !table[idx].empty() || size == 0 ) return;
        
        if( size == 1 ){
            for(int i = 0; i < 4; i++){
                if( mask[i] == 1 ){
                    table[idx].insert(dnums[i]);
                    return;
                }
            }
        }
        
        for(int i = 0; i < 4; i++){
            if( mask[i] == 1 ){
                mask[i] = 0;
                generate( dnums, mask );
                fill_table(dnums[i], idx, get_idx(mask));
                mask[i] = 1;
            }
        }
        
        if( size == 4 ){
            for(int i = 0; i < 4; i++){
                for(int j = i + 1; j < 4; j++){
                    mask[i] = mask[j] = 0;
                    vector<int> mask2 {0, 0, 0, 0};
                    mask2[i] = 1;
                    mask2[j] = 1;
                    generate( dnums, mask );
                    generate( dnums, mask2 );
                    fill_table(get_idx(mask2), idx, get_idx(mask));
                    mask[i] = mask[j] = 1;
                }
            }
        }
    }
    
    void fill_table(int c2_idx, int p_idx, int c_idx){
        for(auto val: table[c_idx]){
            for(auto val2: table[c2_idx]){
                // a + val
                table[p_idx].insert( val2 + val );
                // a - val or val - a
                table[p_idx].insert( val2 - val );
                table[p_idx].insert( val - val2 );
                // a * val
                table[p_idx].insert( val2 * val );
                // a / val or val / a
                if( val != 0 ) table[p_idx].insert( val2 / val );
                if( val2 != 0 ) table[p_idx].insert( val / val2 );
            }
        }
    }
    
    void fill_table(double a, int p_idx, int c_idx){
        for(auto val: table[c_idx]){
            // a + val
            table[p_idx].insert( a + val );
            // a - val or val - a
            table[p_idx].insert( a - val );
            table[p_idx].insert( val - a );
            // a * val
            table[p_idx].insert( a * val );
            // a / val or val / a
            if( val != 0 ) table[p_idx].insert( a / val );
            if( a != 0 ) table[p_idx].insert( val / a );
        }
    }
        
    int get_idx(const vector<int>& mask){
        int idx = 0;
        for(int i = 0; i < 4; i++){
            idx <<= 1;
            idx += mask[i];
        }
        return idx;
    }
    
    int get_size(const vector<int>& mask){
        int size = 0;
        for(int i = 0; i < 4; i++)
            size += mask[i];
        return size;
    }
};
