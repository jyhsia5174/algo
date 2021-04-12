/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    
    void cleanRoom(Robot& bot) {
        dfs( bot, 0, 0, 3);
        dfs( bot, 0, 0, 1);
    }
    
    void turnBack( Robot& bot ){
        bot.turnRight();
        bot.turnRight();
    }
    
    void dfs( Robot &bot, int x, int y, int d){
        bot.clean();
        visited.insert( {x, y} );
        
        int xx, yy, dd;
        for(int i = 1; i >= -1; i--){
            bot.turnRight();
            dd = (d + i + 4) % 4;
            xx = x + dx[dd];
            yy = y + dy[dd];
            if( visited.find( {xx, yy} ) == visited.end() &&  bot.move() ){
                dfs(bot, xx, yy, dd);
            }
            else{
                turnBack(bot);
            }
        }
        
        if( x == 0 && y == 0 ){
            bot.turnRight();
            dd = ( d + 2 ) % 4;
            xx = x + dx[dd];
            yy = y + dy[dd];
            if( visited.find( {xx, yy} ) == visited.end() && bot.move() ){
                dfs(bot, xx, yy, dd);
            }
        }
        else{   
            bot.turnRight();
            bot.move();
        }
    }
    
    vector<int> dx = { -1, 0, 1, 0};
    vector<int> dy = { 0, 1, 0, -1};
    set<pair<int, int>> visited;
};
