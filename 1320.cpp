//1320. Minimum Distance to Type a Word Using Two Fingers 1h
class Solution {
public:
    int minimumDistance(string W) {
        init();
        
        int dp[2][27][27];
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 27; j++)
                for(int k = 0; k < 27; k++)
                    dp[i][j][k] = 0;
        
        // solve
        int N = W.size();
        for(int pos = N-1; pos >=0; pos--){
            //cout << pos << endl;
            int c = W[pos] - 'A';
            auto &t1 = dp[pos%2];
            auto &t2 = dp[(pos+1)%2];
            for(int i = 0; i < 27; i++){
                for(int j = 0; j < 27; j++){
                    t1[i][j] = t1[j][i] = min( dist[c][i] + t2[c][j],
                                            dist[j][c] + t2[i][c]);
                }
            }
            //print(dp[pos%2]);
        }
        
        return dp[0][26][26];
    }
    
    void init(){
        for(int i = 0; i < 26; i++){
            int x = i / 6;
            int y = i % 6;
            position[i] = { x, y };
        }
        
        dist.resize(27);
        for(int i = 0; i < 27; i++){
            dist[i].resize(27, 0);
            for(int j = 0; j < 27; j++){
                if( i == 26 || j == 26 ){
                    dist[i][j] = 0;
                }
                else{
                    dist[i][j] = 
                        abs( position[i].first - position[j].first ) +
                        abs( position[i].second - position[j].second );
                }
            }
        }
    }
    
    void print(int A[27][27]){
        for(int i = 0; i < 27; i++){
            for(int j = 0; j < 27; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    }
    
    unordered_map<int, pair<int, int>> position;
    vector<vector<int>> dist;
};
