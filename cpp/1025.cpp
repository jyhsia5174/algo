// 1025. Divisor Game
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> record(N+1, false);
        
        for(int i = 2; i < N+1 ; i++){
            for(int j = 1; j < i; j++){
                if( i % j == 0 && !record[i-j] ){
                    record[i] = true;
                    break;
                }
            }
        }
        
        return record[N];
    }
};
