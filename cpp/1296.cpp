// Divide Array in Sets of K Consecutive Numbers (This question is the same as 846)
class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int W) {
        map<int, int> M;
        for(auto a: hand)
            M[a] ++;
        
        while( M.size() ){
            int min_val = M.begin()->first;
            
            for(int val = min_val; val < min_val + W; val++){
                if( M.find(val) == M.end() )
                    return false;
                M[val]--;
                
                if(M[val] == 0)
                    M.erase(val);
            }
        }
        
        return true;
    }
};
