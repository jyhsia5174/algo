// Stone Game II from @ tumei

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        sum.resize(N);
        sum[N-1] = piles[N-1];
        for(int i = N-2; i >= 0; i--)
            sum[i] = sum[i+1] + piles[i];
        
        scores.resize(N);
        for(int i = 0; i < N; i++)
            scores[i].resize(N, 0);
        
        return best_score( 0, 1);
    }
private:
    int N;
    vector<vector<int>> scores;
    vector<int> sum;
    
    int best_score(int i, int m){
        if( i == N ) return 0;
        if( N - i <= 2 * m ){
            scores[i][m] = sum[i];
            return scores[i][m];
        }
        
        if( scores[i][m] != 0 )
            return scores[i][m];
        
        int min_score = 1<<30 - 1;
        for(int x = 1; x <= 2*m; x++){
            min_score = min( min_score, best_score(i+x, max(x, m)));
        }
        
        scores[i][m] = sum[i] - min_score;
        
        return scores[i][m];
    }
};
