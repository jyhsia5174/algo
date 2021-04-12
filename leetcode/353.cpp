/*
353. Design Snake Game
*/
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height;
        n = width;
        for(auto &v: food)
            F.push(v);
        D["U"] = {-1, 0};
        D["D"] = {1, 0};
        D["L"] = {0, -1};
        D["R"] = {0, 1};
        snake.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string s) {
        vector<int> dir = D[s];
        vector<int> head = snake.front();
        int x = head[0] + dir[0];
        int y = head[1] + dir[1];
        int hashval = x*10001 + y;
        if( x < 0 || x >= m || y < 0 || y >= n || (body.find(hashval) != body.end() && hashval != (snake.back()[0]*10001 + snake.back()[1] ) ) )
            return -1;
        
        if( !F.empty() && x == F.front()[0] && y == F.front()[1] ){
            F.pop();
        }
        else{ 
            body.erase(snake.back()[0]*10001 + snake.back()[1] );
            snake.pop_back();
        }
        snake.push_front({x, y});
        body.insert( hashval );
        
        return snake.size()-1;
    }
private:
    int m, n;
    queue<vector<int>> F;
    deque<vector<int>> snake;
    unordered_set<int> body; 
    unordered_map<string, vector<int>> D;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */


// 353. Design Snake Game
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    int hash(int row, int col){
        return row * W + col;
    }
    
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        W = width;
        H = height;
        for(auto v: food)
            F.push({v[0], v[1]});
        S.push_back({0, 0});
        M.insert(hash(0, 0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto [dx, dy] = D[direction];
        auto [x, y] = S.back();
        int xx = x + dx;
        int yy = y + dy;
        cout << xx << "\t" << yy << endl;
        if( xx < 0 || xx >= H || yy < 0 || yy >= W )
            return -1;
        if( !F.empty() &&  F.front().first == xx &&  F.front().second == yy ){
            M.insert(hash(xx, yy));
            S.push_back({xx, yy});
            F.pop();
        }
        else{
            auto [tx, ty] = S.front();
            S.pop_front();
            M.erase(hash(tx, ty));
            if( M.count(hash(xx, yy)) == 1)
                return -1;
            S.push_back({xx, yy});
            M.insert(hash(xx, yy));
        }
        return S.size()-1;
    }
private:
    int W, H;
    deque<pair<int, int>> S;
    queue<pair<int, int>> F;
    unordered_set<int> M;
    unordered_map<string, pair<int, int>> D{
        {"U", {-1, 0}},
        {"D", {1, 0}},
        {"L", {0, -1}},
        {"R", {0, 1}}
    };
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
