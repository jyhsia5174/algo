/*
322. Coin Change
Runtime: 68 ms, faster than 87.61% of C++ online submissions for Coin Change.
Memory Usage: 14 MB, less than 70.25% of C++ online submissions for Coin Change.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount+1, INF);
        res[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(auto &val: coins){
                int pre = i - val;
                if( pre >= 0 && res[pre] != INF )
                    res[i] = min( res[i], res[pre] + 1 );
            }
        }
        
        return (res[amount] == INF)? -1 : res[amount];
    }
    
private:
    const int INF = numeric_limits<int>::max();
};

#include <vector>
#include <limits>
using namespace std;

const int int_max = numeric_limits<int>::max();

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        init( amount );
        int num = solve(coins, amount);
        if( num == int_max )
            return -1;
        else
            return num;
    }

private:
    vector<int> table;
    void init(int amount);
    
    int solve(vector<int>& coins, int amount){
        if( table[amount] != -1 )
            return table[amount];
        
        int subprob_num = int_max;
        for( auto c: coins )
            if( amount >= c )
                subprob_num = min( subprob_num, solve( coins, amount - c) );
        
        if( subprob_num == int_max )
            table[amount] = subprob_num;
        else
            table[amount] = subprob_num + 1;
        
        return table[amount];
    }
};

void Solution::init(int amount){
    table.resize(amount+1);
    fill(table.begin(), table.end(), -1);
    table[0] = 0;
}
