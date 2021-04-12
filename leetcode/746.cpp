// 746. Min Cost Climbing Stairs
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        
        for(int i = 2; i < cost.size(); i++){
            cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
        }
        
        return cost[cost.size()-1];
    }
};
