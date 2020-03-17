class Solution {
public:
    typedef pair<int, int> pii;
    int minKnightMoves(int x, int y) {
        if( abs(x) < abs(y) ) swap(x, y);
        pii target = { abs(x), abs(y) };
        queue<pii> que;
        que.push({0,0});
        unordered_map<int, unordered_map<int, bool> > visited;
        visited[0][0] = true;
        int step = 0;
        
        if( x == 0 && y == 0 )
            return 0;
        
        while( true ){
            int size = que.size();
            for(int k = 0; k < size; k++){
                pii p = que.front();
                que.pop();

                for(int i = 0; i < 8; i++){
                    int xx = p.first + dx[i];
                    int yy = p.second + dy[i];
                    
                    pii next = {xx, yy};
                    
                    if( yy - xx > 2 || visited[xx][yy])
                        continue;
                    
                    que.push( next );
                    visited[xx][yy] = true;
                    
                    if( target == next ){
                        step++;
                        return step;
                    }
                }                
            }
            
            step++;    
        }
    }
    
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
};
