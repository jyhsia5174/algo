// 453. Minimum Moves to Equal Array Elements
class Solution {
    public int minMoves(int[] nums) {
        int sum = 0;
        int minVal = Integer.MAX_VALUE;
        for(int i : nums){
            sum += i;
            minVal = Math.min( minVal, i );
        }
        
        return sum - nums.length * minVal;
    }
}
