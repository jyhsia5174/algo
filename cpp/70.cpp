/*
70. Climbing Stairs
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> m(n+1, -1);
        m[0] = 1;
        m[1] = 1;
        return helper(n, m);
    }
    
    int helper(int n, vector<int> &m){
        if( m[n] != -1 )
            return m[n];
        
        m[n] = helper(n-1, m) + helper(n-2, m);
        
        return m[n];
    }
    
};

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
