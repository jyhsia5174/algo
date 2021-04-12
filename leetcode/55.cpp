/*
55. Jump Game
Runtime: 8 ms, faster than 97.39% of C++ online submissions for Jump Game.
Memory Usage: 12.8 MB, less than 94.58% of C++ online submissions for Jump Game.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lcap = 0;
        int nlcap = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            if( lcap < i ){
                return false;
            }
            
            nlcap = max( nlcap, nums[i] + i );
            if( lcap == i ){
                lcap = nlcap;
            }
        }
        
        return true;
    }
};
