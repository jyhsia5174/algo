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
