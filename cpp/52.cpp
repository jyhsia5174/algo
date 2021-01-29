/*
52. N-Queens II
*/
class Solution {
public:
    int totalNQueens(int n) {
        N = n;
        C.resize(N, true);
        D1.resize(2*N, true);
        D2.resize(2*N, true);
        return backtrack(0, 0);
    }
    
    int backtrack(int row, int count){
        for(int i = 0; i < N; i++){
            int d1 = i - row + (N-1);
            int d2 = row + i;
            if( C[i] && 
              D1[d1] &&
              D2[d2]  ){
                C[i] = false;
                D1[d1] = false;
                D2[d2] = false;
                
                if( row + 1 == N )
                    count += 1;
                else
                    count = backtrack(row + 1, count);
                
                C[i] = true;
                D1[d1] = true;
                D2[d2] = true;
            }
        }
        
        return count;
    }
private:
    int N;
    vector<bool> C, D1, D2;
};
