// 1. Two Sum

// O(n^2)
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for( int i = 0; i < nums.length; i++){
            for(int j = i+1; j < nums.length; j++){
                if( nums[j] == target - nums[i] )
                    return new int[] {i, j};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

// O(n)
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < nums.length; i++){
            map.put(nums[i], i);
        }
        
        for(int i = 0; i < nums.length; i++){
            int complement = target - nums[i];
            if( map.containsKey(complement) 
               && map.get(complement) != i ){
                return new int[] { i, map.get(complement)};
            }
        }
        
        throw new IllegalArgumentException("No two sum solution");
    }
}
