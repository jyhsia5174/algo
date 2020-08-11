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
