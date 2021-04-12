// 1167. Minimum Cost to Connect Sticks
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> Q(sticks.begin(), sticks.end());
        
        
        int cost = 0;
        while( Q.size() > 1 ){
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            cost += a + b;
            Q.push( a+b );
        }
        
        return cost;
    }
};
