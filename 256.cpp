// 256. Paint House
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if( costs.size() == 0 )
            return 0;
        
        for(int i = 1; i < costs.size(); i++){
            for(int j = 0; j < 3; j++){
                int min_cost = numeric_limits<int>::max();
                for(int k = 1; k < 3; k++)
                    min_cost = min(min_cost, costs[i][j]+costs[i-1][(j+k)%3]);
                costs[i][j] = min_cost;
            }
        }
        
        int min_cost = numeric_limits<int>::max();
        for(int i = 0; i < 3; i++)
            min_cost = min( min_cost, costs[costs.size()-1][i] );
        return min_cost;
    }
};
