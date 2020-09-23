// 909. Snakes and Ladders
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        queue<int> Q;
        int D = 0;
        visited[0][0] = true;
        Q.push(rev_idx(0, 0));
        while(!Q.empty()){
            queue<int> Qtmp;
            D++;
            cout << endl;
            while( !Q.empty() ){
                int pos = Q.front();
                Q.pop();
                for(int i = 1; i < 7; i++){
                    if( pos + i >= n * n )
                        break;
                    auto [xx, yy] = idx( pos + i );
                    if( xx >= 0 && xx < n && yy >=0 && yy < n){
                        if( !visited[xx][yy] && board[(n-1)-xx][yy] == -1){
                            visited[xx][yy] = true;
                            if( rev_idx(xx, yy) == (n*n-1) ) return D;
                            Qtmp.push(rev_idx(xx, yy));
                        }
                        else{
                            if( board[(n-1)-xx][yy] != -1 ){
                                auto [xxx, yyy] = idx( board[(n-1)-xx][yy]-1 );
                                assert(xxx >= 0 && xxx < n && yyy >=0 && yyy < n);
                                if( !visited[xxx][yyy] ){
                                    visited[xxx][yyy] = true;
                                    if( rev_idx(xxx, yyy) == (n*n-1) ) return D;
                                    Qtmp.push( rev_idx(xxx, yyy) );
                                }
                            }
                        }
                    }
                }
            }
            swap( Q, Qtmp );
        }
        
        return -1;
    }
    
private:
    int n;
    
    pair<int, int> idx(int num){
        int row_type = (num / n) % 2;
        
        if( row_type == 0 ){
            return { num / n, num % n };
        }
        else{
            return {num / n, (n-1) - (num%n)};
        }
    }
    
    int rev_idx(int x, int y){
        int row_type = x % 2;
        
        if( row_type == 0 ){
            return y + x * n;
        }
        else{
            return (n-1) - y + x * n;
        }
    }
};
