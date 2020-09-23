// 70. Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        int count[3];
        count[0] = 0;
        count[1] = 1;
        count[2] = 0;
        
        for(int i = 1; i <= n; i++){
            count[2] = count[1] + count[0];
            count[0] = count[1];
            count[1] = count[2];
        }
        
        return count[2];
    }
};
