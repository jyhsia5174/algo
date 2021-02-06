/*
247. Strobogrammatic Number II
*/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        backtrack(n, "", "");
        return res;
    }
    
    void backtrack(int n, string head, string tail){
        if( head.size() >= 1 && head[0] == '0' )
            return;
        
        if( n == 0 ){
            res.push_back( head + tail );
            return;
        }
        
        if( n == 1 ){
            for(auto &v: dd){
                res.push_back( head + v + tail );
            }
            return;
        }
        
        for(int i = 0; i < 5; i++){
            string H = head + d[i];
            string T = invd[i] + tail;
            backtrack( n - 2, H, T );
        }
    }
    
private:
    // 0 1 2 3 4 5 6 7 8 9
    // 0 1 x x x x 9 x 8 6
    vector<string> dd{"0", "1", "8"};
    vector<string> d{"0", "1", "8", "6", "9" };
    vector<string> invd{"0", "1", "8", "9", "6"};
    vector<string> res;
};
